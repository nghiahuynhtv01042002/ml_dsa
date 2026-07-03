#include "test/test_runner/test_runner.h"
#include "test/math/modq/test_mod_q.h"
int main(void)
{
    test_runner_add_suite(&g_mod_q_suite);
    return test_runner_run_all();
}