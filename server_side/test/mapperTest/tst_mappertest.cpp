#include <QString>
#include <QtTest>

#include "model/user.h"
#include "mapper/qobjecthelper.h"
#include "mapper/usermapper.h"

auto ignore=[]()
{
	AbstractMapper::universal_db=database("../data/test_db.db");
	return 0;
}();

class MapperTest : public QObject
{
	Q_OBJECT

public:
	UserMapper userMapper;
	User mrJoe;
	MapperTest();

private Q_SLOTS:
	void testQObjectToJson();
	void testInsertionAndQueryUser();
};

MapperTest::MapperTest()
	: mrJoe("mrJoe@e.c","pppasss")
{
}

void MapperTest::testQObjectToJson()
{
	QByteArray serializedMrJoe = "{\n    \"email\": \"mrJoe@e.c\",\n    \"password\": \"pppasss\"\n}\n";
	auto &&qJson = QObjectHelper::qobject2qjson(&mrJoe,QStringList({"id","objectName"}));
		qDebug()<<QJsonDocument(qJson).toJson();

	QCOMPARE(QJsonDocument(qJson).toJson(),serializedMrJoe);
}

void MapperTest::testInsertionAndQueryUser()
{
	try
	{
		userMapper.db<<"DELETE FROM user WHERE email = ?;"
					<<mrJoe.get_email();
		userMapper.insertUser(mrJoe);		
		auto mrJoeP = userMapper.getUserByEmail(mrJoe.get_email());

		QCOMPARE(mrJoe.get_email(), mrJoeP->get_email());
		QCOMPARE(mrJoe.get_password(), mrJoeP->get_password());
	}
	catch(sqlite_exception e)
	{
		qDebug()<<e.what()<<e.get_code()<<e.get_sql().data();
		throw ;
	}
	catch(string s)
	{
		qDebug()<<s.data();
	}
}

QTEST_APPLESS_MAIN(MapperTest)

#include "tst_mappertest.moc"
