#include "tetris_tests.h"

START_TEST(bag_generation) {
  // Arrange
  int bag[7];
  // Act
  generate_bag(bag);
  // Assert
  ck_assert_int_ne(bag[0], bag[6]);
}
END_TEST

START_TEST(copying_tile) {
  // Arrange
  int piece = 3;
  Tile tile, copy;
  generate_piece_struct(piece, &tile);
  // Act
  copy_tile(&tile, &copy);
  // Assert
  ck_assert_int_eq(tile.center, copy.center);
}
END_TEST

Suite *matrix_tests() {
  Suite *s = suite_create("matrix_tests");
  TCase *universal_tc;

  universal_tc = tcase_create("Universal test case");
  tcase_add_test(universal_tc, bag_generation);
  tcase_add_test(universal_tc, copying_tile);
  suite_add_tcase(s, universal_tc);

  return s;
}

int main() {
  int failed = 0;
  Suite *s;
  SRunner *runner;

  s = matrix_tests();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
