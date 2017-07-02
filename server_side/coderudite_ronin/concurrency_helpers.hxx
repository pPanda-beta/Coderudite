#ifndef CONCURRENCY_HELPERS_HXX
#define CONCURRENCY_HELPERS_HXX

#include <thread>
#include <memory>
#include <condition_variable>
#include <QTimer>
#include <QThread>
#include <QApplication>

template <typename Func>
inline void runOnThread(QThread *qThread, Func &&func)
{
	QTimer *t = new QTimer();
	t->moveToThread(qThread);
	t->setSingleShot(true);
	QObject::connect(t, &QTimer::timeout, [=]()
	{
		func();
		t->deleteLater();
	});
	QMetaObject::invokeMethod(t, "start", Qt::QueuedConnection, Q_ARG(int, 0));
}


template <typename Func>
inline void runOnMainThread(Func &&func)
{
	runOnThread(qApp->thread(), func);
}

inline
void moveToThread(QObject *ptr, QThread *targetThrd=QThread::currentThread())
{
	std::mutex mt;
	std::condition_variable_any cv;
	runOnThread(ptr->thread(),[&]
	{
		ptr->setParent(NULL);
		ptr->moveToThread(targetThrd);
		cv.notify_one();
	});
	cv.wait(mt);
}

inline
void moveToMyThread(QObject *ptr)
{
	moveToThread(ptr);
}

template<typename T>
std::weak_ptr<T> deriveSmartPtr(T *ptr)
{
	std::shared_ptr<T> *shrd = new std::shared_ptr<T>(ptr,[](T *){});
	QObject::connect((QObject *)ptr, &QObject::destroyed, [=]{	delete shrd;	});
	return *shrd;
}

#endif // CONCURRENCY_HELPERS_HXX
