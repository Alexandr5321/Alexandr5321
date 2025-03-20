// // #include "s21_check.h"
// #include "tests.h"

// START_TEST(greater_test_1) {
//   s21_decimal t1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
//   s21_decimal t2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
//   ck_assert_int_eq(0, s21_is_greater(t1, t2));
// }
// END_TEST

// START_TEST(greater_test_2) {
//   s21_decimal t1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
//   s21_decimal t2 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
//   ck_assert_int_eq(0, s21_is_greater(t1, t2));
// }
// END_TEST

// START_TEST(greater_test_3) {
//   s21_decimal q1 = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};
//   s21_decimal q2 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
//   ck_assert_int_eq(1, s21_is_greater(q1, q2));
// }
// END_TEST

// START_TEST(greater_test_4) {
//   s21_decimal w1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
//   s21_decimal w2 = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};
//   ck_assert_int_eq(0, s21_is_greater(w1, w2));
// }
// END_TEST

// START_TEST(greater_test_5) {
//   s21_decimal r1 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
//   s21_decimal r2 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
//   ck_assert_int_eq(0, s21_is_greater(r1, r2));
// }
// END_TEST

// START_TEST(greater_test_6) {
//   s21_decimal n1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
//   s21_decimal n2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
//   n1.bits[0] = 257;
//   n2.bits[0] = 257;
//   n1.bits[2] = 256;
//   n2.bits[2] = 257;
//   set_scale(&n1, 10);
//   set_scale(&n2, 11);
//   ck_assert_int_eq(1, s21_is_greater(n1, n2));
// }
// END_TEST

// START_TEST(greater_test_7) {
//   s21_decimal n1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
//   s21_decimal n2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
//   n1.bits[0] = 257;
//   n2.bits[0] = 257;
//   n1.bits[2] = 256;
//   n2.bits[2] = 257;
//   set_scale(&n1, 11);
//   set_scale(&n2, 11);
//   ck_assert_int_eq(0, s21_is_greater(n1, n2));
// }
// END_TEST

// START_TEST(greater_test_8) {
//   s21_decimal r1 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
//   s21_decimal r2 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
//   ck_assert_int_eq(0, s21_is_greater(r1, r2));
// }
// END_TEST

// START_TEST(greater_test_9) {
//   s21_decimal r1 = {{0x00000002, 0x00000000, 0x00000000, 0x80000000}};
//   s21_decimal r2 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
//   ck_assert_int_eq(0, s21_is_greater(r1, r2));
// }
// END_TEST

// Suite *suite_greater(void) {
//   Suite *s1 = suite_create("greater_suite");
//   TCase *tc1_1 = tcase_create("greater_tcase");

//   suite_add_tcase(s1, tc1_1);
//   tcase_add_test(tc1_1, greater_test_1);
//   tcase_add_test(tc1_1, greater_test_2);
//   tcase_add_test(tc1_1, greater_test_3);
//   tcase_add_test(tc1_1, greater_test_4);
//   tcase_add_test(tc1_1, greater_test_5);
//   tcase_add_test(tc1_1, greater_test_6);
//   tcase_add_test(tc1_1, greater_test_7);
//   tcase_add_test(tc1_1, greater_test_8);
//   tcase_add_test(tc1_1, greater_test_9);

//   return s1;
// }