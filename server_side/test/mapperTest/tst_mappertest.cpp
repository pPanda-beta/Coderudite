#include <QString>
#include <QtTest>

#include "model/user.h"
#include "mapper/qobjecthelper.h"

class MapperTest : public QObject
{
	Q_OBJECT

public:
	User mrJoe;
	MapperTest();

private Q_SLOTS:
	void testQObjectToJson();
};

MapperTest::MapperTest()
	: mrJoe("mrJoe@e.c","pppasss")
{/*
	mrJoe.set_email( "mrJoe@e.c")
			.set_password("pppasss");*/
}

void MapperTest::testQObjectToJson()
{
	QByteArray serializedMrJoe = "{\n    \"email\": \"mrJoe@e.c\",\n    \"password\": \"pppasss\"\n}\n";
	auto &&qJson = QObjectHelper::qobject2qjson(&mrJoe);
	//	qDebug()<<QJsonDocument(qJson).toJson();

	QCOMPARE(QJsonDocument(qJson).toJson(),serializedMrJoe);
}

QTEST_APPLESS_MAIN(MapperTest)

#include "tst_mappertest.moc"
