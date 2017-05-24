#include <QString>
#include <QtTest>

#include "mapper/usermapper.h"
#include "service/userservice.h"
#include "service/sessionservice.h"

class ServiceTest : public QObject
{
	Q_OBJECT

public:
	ServiceTest();

	shared_ptr<UserMapper> userMapperP;
	shared_ptr<UserService> userServiceP;
	shared_ptr<SessionService> ssnServiceP;

	User mrJoe;
	Session mrJoesSession;

private Q_SLOTS:
	void initTestCase();
	void cleanupTestCase();
	void testLoginSuccess();
	void testLoginFail();
	void testUserIdOfValidSession();
	void testStoreSessionData();
};

ServiceTest::ServiceTest()
	: mrJoe("mrJoe@e.c","pppasss"),
	  mrJoesSession(NULL,"")
{
}

void ServiceTest::initTestCase()
{
	try
	{
		AbstractMapper::universal_db = database("../data/service_test_db.db");
		userMapperP = make_shared<UserMapper>();
		userServiceP = make_shared<UserService>(*userMapperP);
		ssnServiceP = make_shared<SessionService>(SessionMapper());

		userMapperP->insertUser(mrJoe);
		userServiceP->login(mrJoe);
		mrJoesSession = ssnServiceP->createSession(mrJoe);
	}
	catch (sqlite_exception e)
	{
		qDebug()<<e.what()<<e.get_code()<<e.get_sql().data();
		throw ;
	}
}

void ServiceTest::cleanupTestCase()
{
}

void ServiceTest::testLoginSuccess()
{
	User trialUser(mrJoe.get_email(), mrJoe.get_password());
	QVERIFY(userServiceP->login(trialUser));
}

void ServiceTest::testLoginFail()
{
	User badUser("abraKiDabra","");
	QVERIFY(not userServiceP->login(badUser));
}

void ServiceTest::testUserIdOfValidSession()
{
	QCOMPARE(mrJoesSession.userid, mrJoe.get_id());
}

void ServiceTest::testStoreSessionData()
{
	string value="Hi";
	try
	{
		mrJoesSession["k1"]="v1";
		value = mrJoesSession["k1"];
	}
	catch (sqlite_exception e)
	{
		qDebug()<<e.what()<<e.get_code()<<e.get_sql().data();
		throw ;
	}
	QCOMPARE(value,"v1"s);
}

QTEST_APPLESS_MAIN(ServiceTest)

#include "tst_servicetest.moc"
