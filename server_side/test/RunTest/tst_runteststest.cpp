#include <QString>
#include <QtTest>

#include <string>
#include <cstdio>
#include <regex>
#include <map>

#include "model/run.h"
#include "helpers.hxx"

using namespace std;

class RunTestsTest : public QObject
{
	Q_OBJECT

public:
	RunTestsTest();

private Q_SLOTS:
	void testCSrc();
	void testJavaSrc();
};

RunTestsTest::RunTestsTest()
{
}

const char* sample_code_c = R"dhamak(
#include <stdio.h>
int main()
{
	printf("Hello World - c\n");
//	usleep(750 * 1000);
	return 0;
}
)dhamak";


const char* sample_code_java = R"chicken(
public class Main
{
   public static void main(String [] args){
	   System.out.println("Hello World - Java 8");
   }
}
)chicken";


string test_run(string source_code,string type)
{
	Solution s(source_code, type);
	Run r(s);
	RunResult result = r.execute("",1000);
	result.m_oup.str(convertCRLF2LF(result.m_oup.str()));
	qDebug()<<"O/P"<<result.m_oup.str().data();
//	qDebug()<<result.exec_time.count();
	return result.toString();
}

void RunTestsTest::testCSrc()
{
	QCOMPARE(test_run(sample_code_c,"c").data(), "Hello World - c\n") ;
}

void RunTestsTest::testJavaSrc()
{
	QCOMPARE(test_run(sample_code_java,"java").data(), "Hello World - Java 8\n") ;
}



QTEST_APPLESS_MAIN(RunTestsTest)

#include "tst_runteststest.moc"
