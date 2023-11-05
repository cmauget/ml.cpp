#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h> 
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "../include/Tensor.hpp"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestTensor : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestTensor);
	CPPUNIT_TEST(testConstructors);
    CPPUNIT_TEST(testOperators);
    CPPUNIT_TEST(testAssesors);
    CPPUNIT_TEST(testMult);
	CPPUNIT_TEST_SUITE_END();
public:
	void setUp(void);
	void tearDown(void);
protected:
	void testConstructors(void);
    void testOperators(void);
    void testAssesors(void);
    void testMult(void);
private:
	Tensor *mTestObj;
};
//-----------------------------------------------------------------------------
void TestTensor::testConstructors(void){

    cout << "" << endl;
    // Test the default constructor
    Tensor t1;
    vector<int> dim = t1.getDim();
    vector<double> data = t1.getData();
    int size = t1.getSize();
    CPPUNIT_ASSERT(dim.size() == 1);
    CPPUNIT_ASSERT(dim[0] == 1);
    CPPUNIT_ASSERT(data.size() == 1);
    CPPUNIT_ASSERT(data[0] == 0.0);
    CPPUNIT_ASSERT(size == 1);

    // Test the constructor with specified dimensions
    dim = {2, 3, 4};
    Tensor t2(dim);
    dim = t2.getDim();
    data = t2.getData();
    size = t2.getSize();
    CPPUNIT_ASSERT(dim.size() == 3);
    CPPUNIT_ASSERT(dim[0] == 2);
    CPPUNIT_ASSERT(dim[1] == 3);
    CPPUNIT_ASSERT(dim[2] == 4);
    CPPUNIT_ASSERT(data.size() == 24);
    CPPUNIT_ASSERT(size == 24);

    // Test the constructor with specified dimensions and data
    data = {1.0, 2.0, 3.0, 4.0};
    Tensor t3(dim, data);
    dim = t3.getDim();
    data = t3.getData();
    size = t3.getSize();
    CPPUNIT_ASSERT(dim.size() == 3);
    CPPUNIT_ASSERT(dim[0] == 2);
    CPPUNIT_ASSERT(dim[1] == 3);
    CPPUNIT_ASSERT(dim[2] == 4);
    CPPUNIT_ASSERT(data.size() == 24);
    CPPUNIT_ASSERT(data[0] == 1.0);
    CPPUNIT_ASSERT(data[1] == 2.0);
    CPPUNIT_ASSERT(data[2] == 3.0);
    CPPUNIT_ASSERT(data[3] == 4.0);
    CPPUNIT_ASSERT(size == 24);

    // Test the constructor with too much data
    vector<int> dim2 = {2, 1};
    data = {1.0, 2.0, 3.0, 4.0};
    Tensor t4(dim2, data);
    dim = t4.getDim();
    data = t4.getData();
    size = t4.getSize();
    CPPUNIT_ASSERT(dim.size() == 2);
    CPPUNIT_ASSERT(dim[0] == 2);
    CPPUNIT_ASSERT(dim[1] == 1);
    CPPUNIT_ASSERT(data.size() == 2);
    CPPUNIT_ASSERT(data[0] == 1.0);
    CPPUNIT_ASSERT(data[1] == 2.0);
    CPPUNIT_ASSERT(size == 2);

}

void TestTensor::testOperators(void){

    cout << "" << endl;
    // test the + operator
    vector<int> dim = {2, 2};
    vector<double> data = {1.0, 2.0, 3.0, 4.0};
    Tensor t1(dim, data);
    Tensor t2(dim, data);
    Tensor t3 = t1 + t2;
    data = t3.getData();
    CPPUNIT_ASSERT(data[0] == 2.0);
    CPPUNIT_ASSERT(data[1] == 4.0);
    CPPUNIT_ASSERT(data[2] == 6.0);
    CPPUNIT_ASSERT(data[3] == 8.0);
    CPPUNIT_ASSERT(data.size() == 4);

    // test the - operator
    Tensor t4 = t1 - t2;
    data = t4.getData();
    CPPUNIT_ASSERT(data[0] == 0.0);
    CPPUNIT_ASSERT(data[1] == 0.0);
    CPPUNIT_ASSERT(data[2] == 0.0);
    CPPUNIT_ASSERT(data[3] == 0.0);
    CPPUNIT_ASSERT(data.size() == 4);

    // test the + operator with mismatched dimensions
    vector<int> dim2 = {2, 1};
    Tensor t5(dim2, data);
    Tensor t6 = t1 + t5;
    dim = t6.getDim();
    data = t6.getData();
    CPPUNIT_ASSERT(dim[0] == 2);
    CPPUNIT_ASSERT(dim[1] == 2);
    CPPUNIT_ASSERT(data[0] == 1.0);
    CPPUNIT_ASSERT(data[1] == 2.0);
    CPPUNIT_ASSERT(data[2] == 3.0);
    CPPUNIT_ASSERT(data[3] == 4.0);
    CPPUNIT_ASSERT(data.size() == 4);

    // test the - operator with mismatched dimensions
    t6 = t1 - t5;
    dim = t6.getDim();
    data = t6.getData();
    CPPUNIT_ASSERT(dim[0] == 2);
    CPPUNIT_ASSERT(dim[1] == 2);
    CPPUNIT_ASSERT(data[0] == 1.0);
    CPPUNIT_ASSERT(data[1] == 2.0);
    CPPUNIT_ASSERT(data[2] == 3.0);
    CPPUNIT_ASSERT(data[3] == 4.0);
    CPPUNIT_ASSERT(data.size() == 4);

}

void TestTensor::testAssesors(void){

    cout << "" << endl;
    // test the [] operator
    vector<int> dim = {2, 3};
    vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    Tensor t1(dim, data);
    CPPUNIT_ASSERT(t1[0][0] == 1.0);
    CPPUNIT_ASSERT(t1[0][1] == 2.0);
    CPPUNIT_ASSERT(t1[1][0] == 4.0);
    CPPUNIT_ASSERT(t1[1][2] == 6.0);
    CPPUNIT_ASSERT(t1[2][0] == 1.0);
    CPPUNIT_ASSERT(t1[-2][0] == 1.0);

}

void TestTensor::testMult(void){
    
        cout << "" << endl;
        // test the * operator
        vector<int> dim = {2, 2};
        vector<double> data = {1.0, 2.0, 3.0, 4.0};
        Tensor t1(dim, data);
        Tensor t2(dim, data);
        Tensor t3 = t1 * t2;
        data = t3.getData();
        CPPUNIT_ASSERT(data[0] == 7.0);
        CPPUNIT_ASSERT(data[1] == 10.0);
        CPPUNIT_ASSERT(data[2] == 15.0);
        CPPUNIT_ASSERT(data[3] == 22.0);
        CPPUNIT_ASSERT(data.size() == 4);

        vector<int> dim2 = {2, 1};
        data = {1.0, 2.0};
        Tensor t4(dim2, data);
        Tensor t5 = t1 * t4;
        dim = t5.getDim();
        data = t5.getData();
        CPPUNIT_ASSERT(dim[0] == 2);
        CPPUNIT_ASSERT(dim[1] == 1);
        CPPUNIT_ASSERT(data[0] == 5.0);
        cout << data[1] << endl;
        CPPUNIT_ASSERT(data[1] == 11.0);
        CPPUNIT_ASSERT(data.size() == 2);
    
        // test the * operator with mismatched dimensions
        dim2 = {1, 2};
        data = {1.0, 2.0, 3.0, 4.0};
        Tensor t6(dim2, data);
        Tensor t7 = t1 * t6;
        dim = t7.getDim();
        data = t7.getData();
        CPPUNIT_ASSERT(dim[0] == 2);
        CPPUNIT_ASSERT(dim[1] == 2);
        CPPUNIT_ASSERT(data[0] == 1.0);
        CPPUNIT_ASSERT(data[1] == 2.0);
        CPPUNIT_ASSERT(data[2] == 3.0);
        CPPUNIT_ASSERT(data[3] == 4.0);
        CPPUNIT_ASSERT(data.size() == 4);
}


void TestTensor::setUp(void)
{
	mTestObj = new Tensor();
}
void TestTensor::tearDown(void)
{
	delete mTestObj;
}
//-----------------------------------------------------------------------------
CPPUNIT_TEST_SUITE_REGISTRATION( TestTensor );
int main(int argc, char* argv[])
{
	// informs test-listener about testresults
	CPPUNIT_NS::TestResult testresult;
	// register listener for collecting the test-results
	CPPUNIT_NS::TestResultCollector collectedresults;
	testresult.addListener (&collectedresults);
	// register listener for per-test progress output
	CPPUNIT_NS::BriefTestProgressListener progress;
	testresult.addListener (&progress);
	// insert test-suite at test-runner by registry
	CPPUNIT_NS::TestRunner testrunner;
	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
	testrunner.run(testresult);
	// output results in compiler-format
	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
	compileroutputter.write ();
	// Output XML for Jenkins CPPunit plugin
	ofstream xmlFileOut("cppTestDeResults.xml");
	XmlOutputter xmlOut(&collectedresults, xmlFileOut);
	xmlOut.write();
	// return 0 if tests were successful
	return collectedresults.wasSuccessful() ? 0 : 1;
}