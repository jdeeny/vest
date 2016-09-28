#include <stdio.h>
#include <check.h>
#include <stdlib.h>

#include "vest.h"

#define TEST_FAIL 1
#define TEST_PASS 0

START_TEST (test_bytes_required)
{
  fail_if( VEST_bytes_required(1) != 16, "Wrong number of bytes");
}
END_TEST

Suite* vest_suite (void) {
  Suite *suite = suite_create("vest_ref");
  TCase *tcase = tcase_create("case");
  tcase_add_test(tcase, test_bytes_required);
  suite_add_tcase(suite, tcase);
  return suite;
}

int main (int argc, char *argv[]) {
  int number_failed;
  Suite *suite = vest_suite();
  SRunner *runner = srunner_create(suite);
  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return number_failed;
}
