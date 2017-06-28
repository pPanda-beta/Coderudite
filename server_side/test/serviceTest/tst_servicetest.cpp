#include <QString>
#include <QtTest>

#include "mapper/usermapper.h"
#include "service/userservice.h"
#include "service/sessionservice.h"
#include "service/leaderboardservice.h"


class ServiceTest : public QObject
{
	Q_OBJECT

public:
	ServiceTest();

	shared_ptr<UserMapper> userMapperP;
	shared_ptr<UserService> userServiceP;
	shared_ptr<SessionService> ssnServiceP;
	shared_ptr<SubmissionMapper> submissionMapperP;
	shared_ptr<LeaderBoardService> lbdServiceP;

	User mrJoe;
	Session mrJoesSession;

private Q_SLOTS:
	void initTestCase();
	void populateSubmissions();
	void cleanupTestCase();
	void testLoginSuccess();
	void testLoginFail();
	void testUserIdOfValidSession();
	void testStoreSessionData();
	void testLeaderBoard();
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

		submissionMapperP = make_shared<SubmissionMapper>();
		lbdServiceP = make_shared<LeaderBoardService>(*submissionMapperP);

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

void ServiceTest::populateSubmissions()
{
	submissionMapperP->db<<" DELETE FROM submission ; ";
	auto addSubmission = [&](QString uid, QString pid, QString status, QString timestamp)
	{
		Submission smb;
		smb.set_uid(uid)
			.set_pid(pid)
			.set_status(status)
			.set_timestamp(timestamp);
		submissionMapperP->insertSubmisssion(smb);
	};

	addSubmission("u001", "P001", "SUCC", " t1");
	addSubmission("u001", "P003", "TLE", " t2");
	addSubmission("u001", "P002", "SUCC", " t2");
	addSubmission("u002", "P003", "ERR", " t3");
	addSubmission("u002", "P001", "RTE", " t4");
}

void ServiceTest::testLeaderBoard()
{
	auto &&lbd = lbdServiceP->getCurrentLeaderBoard(
		{"P001","P002","P003"},
		{ 100, 20, 300}
	);
	for(auto &row : lbd)
		qDebug()<<row;
}

QTEST_APPLESS_MAIN(ServiceTest)

#include "tst_servicetest.moc"
