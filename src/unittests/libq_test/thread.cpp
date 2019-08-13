/*

libq threaded unit test

Author: Jeremy L.

*/
#include "platform.h"
#include "threadtools.h"
#include "tests.h"

#include "unitlib2.hpp"

int threadproc(void* param)
{
	CUnitTestSuite* suite = (CUnitTestSuite*)param;
	CUnitTest* test = new CUnitTest("CThread_ExecTest");
	test->eval(true);
	suite->insert_test(*test);
	return 69;
}

void thread_test()
{
	CUnitTestSuite tests = CUnitTestSuite("CThread tests");

	CThread thread(threadproc);
	thread.Start(&tests);

	while(!thread.IsComplete()) {};

	CUnitTest test = CUnitTest("CThread_ReturnTest");
	test.eval(thread.GetReturnCode() == 69);
	tests.insert_test(test);

	tests.print_results();
}