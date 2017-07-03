#ifndef CONCURRENCY_HELPERS_HXX
#define CONCURRENCY_HELPERS_HXX

#include <thread>
#include <memory>
#include <future>
#include <algorithm>
#include <vector>
#include <utility>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>
#include <QTimer>
#include <QThread>
#include <QSemaphore>
#include <QCoreApplication>

template <typename Func>
inline void runOnThread(QThread *qThread, Func &&func)
{
	if(qThread == QThread::currentThread())
	{
		func();
		return;
	}
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
	QSemaphore done;
	auto mover = [&]
	{
		ptr->setParent(NULL);
		ptr->moveToThread(targetThrd);
		done.release();
	};
	runOnThread(ptr->thread(),mover);
	if(QThread::currentThread() != ptr->thread())
		done.acquire();
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


template<typename F, typename ...A>
struct Task : public QRunnable
{
	F func;
	std::tuple<A...> args;

	Task(F f, A ...a) : func(f),args(a...) {}

	template<size_t ...Is>
	void callIt(std::index_sequence<Is...>)
	{
		func(std::get<Is>(args)...);
	}

	void run()
	{
		callIt(std::index_sequence_for<A...>());
	}
};


template<typename F, typename ...A>
inline
QRunnable * make_QRunnable(F  f, A ...a)
{
	return new Task<F,A...>(f,a...);
}

inline	// Equivalent to QtConcurrent::run(pool, func, args...);
void runOnQThreadPool(QThreadPool *pool, auto &&func, auto &&...args)
{
	pool->start(make_QRunnable(func,args...));
}

inline
void async_transform(auto &&ipb, auto &&ipe, auto &&opb, auto &&mapper)
{
	using R = typename std::remove_reference_t< decltype (*opb)>;
	std::vector< std::future<R>> interMediate(std::distance(ipb,ipe));
	std::transform(ipb, ipe, interMediate.begin(),[=](auto &t)
	{
		return std::async(std::launch::async, mapper,t);
	});

	std::transform(interMediate.begin(), interMediate.end(), opb, [](auto &ft)
	{
		return ft.get();
	});
}

inline
void async_transform(auto &&src, auto &&dest, auto &&mapper)
{
	async_transform(begin(src), end(src), begin(dest), mapper);
}

inline	// similar to QtConcurrent::map
void async_transform(QThreadPool *pool, auto &&ipb, auto &&ipe, auto &&opb, auto &&mapper)
{
	using R = typename std::remove_reference_t< decltype (*opb)>;
	std::vector< QFuture<R> > interMediate(std::distance(ipb,ipe));
	std::transform(ipb, ipe, interMediate.begin(),[=](auto &t)
	{
		return QtConcurrent::run(pool, mapper,t);
	});

	std::transform(interMediate.begin(), interMediate.end(), opb, [](auto &ft)
	{
		return ft.result();
	});
}

inline
void async_transform(QThreadPool *pool, auto &&src, auto &&dest, auto &&mapper)
{
	async_transform(pool, begin(src), end(src), begin(dest), mapper);
}

#endif // CONCURRENCY_HELPERS_HXX
