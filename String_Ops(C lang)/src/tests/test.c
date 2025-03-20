#include "test.h"

START_TEST(memchr_test) {
  char *s1 = "This is a s21_memchr test";

  ck_assert_ptr_eq(s21_memchr(s1, 's', 0), memchr(s1, 's', 0));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 2), memchr(s1, 's', 2));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 50), memchr(s1, 's', 50));
  ck_assert_ptr_eq(s21_memchr(s1, 'u', 50), memchr(s1, 'u', 50));
  ck_assert_ptr_eq(s21_memchr(s1, 'u', 32), memchr(s1, 'u', 32));
}
END_TEST

START_TEST(memcmp_test) {
  char *arr1 = "Let's find out how it works";
  char *arr2 = "It will work if it works";
  char *s1 = "Let's find out how it works";
  char *s2 = "It will work if it works";
  ck_assert_msg(s21_memcmp(s1, s2, 256) == memcmp(arr1, arr2, 256),
                "1st memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 2) == memcmp(arr1, arr2, 2),
                "2nd memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 123) == memcmp(arr1, arr2, 123),
                "3rd memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 0) == memcmp(arr1, arr2, 0),
                "4rth memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 36) == memcmp(arr1, arr2, 36),
                "5rth memcmp test failed.");
}
END_TEST

START_TEST(memcpy_test) {
  char *src1 = "abcdefghi";
  int len = s21_strlen(src1);
  char arr1[100] = {0};
  char arr2[100] = {0};
  char arr3[100] = {0};
  char arr4[100] = {0};
  char arr5[100] = {0};
  char arr6[100] = {0};
  char arr7[100] = {0};
  char arr8[100] = {0};

  s21_memcpy(arr1, src1, len + 1);
  memcpy(arr2, src1, len + 1);

  s21_memcpy(arr3, src1, 5);
  memcpy(arr4, src1, 5);

  s21_memcpy(arr5, src1, 0);
  memcpy(arr6, src1, 0);

  s21_memcpy(arr7, src1, 18);
  memcpy(arr8, src1, 18);

  ck_assert_str_eq(arr1, arr2);
  ck_assert_str_eq(arr3, arr4);
  ck_assert_str_eq(arr5, arr6);
  ck_assert_str_eq(arr7, arr8);
}
END_TEST

START_TEST(memset_test) {
  char str1[] = "Is it dark?";
  char str2[] = "No this is a white colour";
  char str3[] = "Ummm...";
  char str4[] = "Just look at this man";
  char str5[] = "Compare to my white shirt it's a black colour dude";
  char arr1[] = "Is it dark?";
  char arr2[] = "No this is a white colour";
  char arr3[] = "Ummm...";
  char arr4[] = "Just look at this man";
  char arr5[] = "Compare to my white shirt it's a black colour dude";

  s21_memset(str1, '_', 5);
  s21_memset(str2, '_', 4);
  s21_memset(str3, 'A', 2);
  s21_memset(str4, '-', 1);
  s21_memset(str5, 'C', 1);

  memset(arr1, '_', 5);
  memset(arr2, '_', 4);
  memset(arr3, 'A', 2);
  memset(arr4, '-', 1);
  memset(arr5, 'C', 1);

  ck_assert_msg(memcmp(str1, arr1, sizeof(str1)) == 0,
                "It's not good for the 1st attempt");
  ck_assert_msg(memcmp(str2, arr2, sizeof(str2)) == 0,
                "It's not good for the 2nd attempt");
  ck_assert_msg(memcmp(str3, arr3, sizeof(str3)) == 0,
                "It's not good for the 3rd attempt");
  ck_assert_msg(memcmp(str4, arr4, sizeof(str4)) == 0,
                "It's not good for the 4th attempt");
  ck_assert_msg(memcmp(str5, arr5, sizeof(str5)) == 0,
                "It's not good for the 5th attempt");
}
END_TEST

START_TEST(strncat_test) {
  char dest1[12] = "Hello ";
  char dest2[12] = "Hello ";
  char dest5[12] = "";
  char dest6[12] = "";
  char dest7[30] = "Hello\n";
  char dest8[30] = "Hello\n";
  char src_1[] = "World";
  char src_2[] = "";
  char src_3[] = "\tWorld!";
  char str1[16] = "HelloWorld";
  char str2[16] = "HelloWorld";
  char str3[16] = "HelloWorld";
  char str4[16] = "HelloWorld";

  ck_assert_str_eq(s21_strncat(dest1, src_1, 5),
                   strncat(dest2, src_1, 5));  // Hello World
  memset(dest1, 0, sizeof(dest1));
  memset(dest2, 0, sizeof(dest2));
  strcpy(dest1, "Hello ");
  strcpy(dest2, "Hello ");
  ck_assert_str_eq(s21_strncat(dest1, src_1, 3),
                   strncat(dest2, src_1, 3));  // Hello Wor
  memset(dest1, 0, sizeof(dest1));
  memset(dest2, 0, sizeof(dest2));
  strcpy(dest1, "Hello ");
  strcpy(dest2, "Hello ");
  ck_assert_str_eq(s21_strncat(dest1, src_1, 0),
                   strncat(dest2, src_1, 0));  // Hello
  memset(dest1, 0, sizeof(dest1));
  memset(dest2, 0, sizeof(dest2));
  strcpy(dest1, "Hello ");
  strcpy(dest2, "Hello ");
  ck_assert_str_eq(s21_strncat(dest1, src_2, 5),
                   strncat(dest2, src_2, 5));  // Hello
  ck_assert_str_eq(s21_strncat(str1, str3, 5),
                   strncat(str2, str4, 5));  // HelloWorldHello
  memset(str1, 0, sizeof(str1));
  memset(str2, 0, sizeof(str2));
  strcpy(str1, "HelloWorld");
  strcpy(str2, "HelloWorld");
  ck_assert_str_eq(s21_strncat(str1, str1 + 5, 5),
                   strncat(str2, str2 + 5, 5));  // HelloWorldWorld
  ck_assert_str_eq(s21_strncat(dest5, src_1, 10),
                   strncat(dest6, src_1, 10));  // World
  memset(dest5, 0, sizeof(dest5));
  memset(dest6, 0, sizeof(dest6));
  strcpy(dest5, "");
  strcpy(dest6, "");
  ck_assert_str_eq(s21_strncat(dest5, src_2, 5), strncat(dest6, src_2, 5));
  ck_assert_str_eq(s21_strncat(dest7, src_3, 7), strncat(dest8, src_3, 7));
}
END_TEST

START_TEST(strchr_test) {
  char *s1 = "This is a test string";
  char *s2 = "A";
  char *s3 = "";
  char ch1 = 'g';
  char ch2 = 'A';
  ck_assert_ptr_eq(s21_strchr(s1, 't'), strchr(s1, 't'));
  ck_assert_ptr_eq(s21_strchr(s1, 'z'), strchr(s1, 'z'));
  ck_assert_ptr_eq(s21_strchr(s1, ch1), strchr(s1, ch1));
  ck_assert_ptr_eq(s21_strchr(s2, ch2), strchr(s2, ch2));
  ck_assert_ptr_eq(s21_strchr(s3, ch2), strchr(s3, ch2));
}
END_TEST

START_TEST(strncmp_test) {
  char *s1 = "Hello, world!";
  char *s2 = "Hello, universe!";
  char *s3 = "Hello, world";
  char *s4 = "";
  char *s5 = "";
  char *s6 = "hello, world!";
  char *s7 = " Hello, world!";
  char *s8 = "Hello, world! ";
  char *s9 = "Hello,\0 world!";

  ck_assert_int_eq(s21_strncmp(s1, s2, 5), strncmp(s1, s2, 5));    // 0
  ck_assert_int_eq(s21_strncmp(s1, s2, 7), strncmp(s1, s2, 7));    // 0
  ck_assert_int_eq(s21_strncmp(s1, s2, 0), strncmp(s1, s2, 0));    // 0
  ck_assert_int_eq(s21_strncmp(s1, s2, 20), strncmp(s1, s2, 20));  // 2
  ck_assert_int_eq(s21_strncmp(s2, s1, 20), strncmp(s2, s1, 20));  // -2
  ck_assert_int_eq(s21_strncmp(s1, s1, 20), strncmp(s1, s1, 20));  // 0
  ck_assert_int_eq(
      s21_strncmp(s1, s3, 20),
      strncmp(s1, s3, 20));  // Должен вернуть Asci код символа !, т.е. 33
  ck_assert_int_eq(s21_strncmp(s4, s5, 5), strncmp(s4, s5, 5));  // 0
  ck_assert_int_eq(s21_strncmp(s4, s2, 5), strncmp(s4, s2, 5));  // -72
  ck_assert_int_eq(s21_strncmp(s1, s6, 5), strncmp(s1, s6, 5));  // -32
  ck_assert_int_eq(s21_strncmp(s1, s7, 20), strncmp(s1, s7, 20));
  ck_assert_int_eq(s21_strncmp(s1, s8, 20), strncmp(s1, s8, 20));  // -32
  ck_assert_int_eq(s21_strncmp(s1, s9, 20), strncmp(s1, s9, 20));
}

END_TEST

START_TEST(strncpy_test) {
  char src[] = "Copy this!";
  char src2[] = "";
  char src3[] = "\0";
  char src4[] = "Line 1\nLine 2\tTab";
  char dest1[50] = {0};
  char dest2[50] = {0};
  char dest3[50] = "Initial";
  char dest4[50] = "Initial";

  ck_assert_str_eq(s21_strncpy(dest1, src, 5), strncpy(dest2, src, 5));
  ck_assert_str_eq(s21_strncpy(dest1, src, 10), strncpy(dest2, src, 10));
  ck_assert_str_eq(s21_strncpy(dest1, src, 11), strncpy(dest2, src, 11));
  ck_assert_str_eq(s21_strncpy(dest1, src, 50), strncpy(dest2, src, 50));
  ck_assert_str_eq(s21_strncpy(dest1, src2, 20), strncpy(dest2, src2, 20));
  ck_assert_str_eq(s21_strncpy(dest1, src3, 50), strncpy(dest2, src3, 50));
  ck_assert_str_eq(s21_strncpy(dest1, src4, 50), strncpy(dest2, src4, 50));
  ck_assert_str_eq(s21_strncpy(dest3, src, 50), strncpy(dest4, src, 50));
  ck_assert_str_eq(s21_strncpy(dest3, src2, 50), strncpy(dest4, src2, 50));
  ck_assert_str_eq(s21_strncpy(dest3, src3, 50), strncpy(dest4, src3, 50));
  ck_assert_str_eq(s21_strncpy(dest3, src4, 50), strncpy(dest4, src4, 50));
}
END_TEST

START_TEST(strcspn_test) {
  char *str1 = "Hello Ben_;";
  char *str2 = "n";
  char *str3 = "what is your name";
  char *str4 = "r";
  char *str5 = "klon hr ___ fff L";
  char *str6 = "L";
  char *str7 = "     hrom out ! home";
  char *str8 = "!";
  char *str9 = "japonis of strong";
  char *str10 = "SG";
  char *str11 = "Billi Gin nasral v kuvshin";
  char *str12 = " ";
  char *str13 = "";
  char *str14 = "o!$_";
  char *str15 = "Help!";
  char *str16 = " ";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
  ck_assert_int_eq(s21_strcspn(str3, str4), strcspn(str3, str4));
  ck_assert_int_eq(s21_strcspn(str5, str6), strcspn(str5, str6));
  ck_assert_int_eq(s21_strcspn(str7, str8), strcspn(str7, str8));
  ck_assert_int_eq(s21_strcspn(str9, str10), strcspn(str9, str10));
  ck_assert_int_eq(s21_strcspn(str11, str12), strcspn(str11, str12));
  ck_assert_int_eq(s21_strcspn(str13, str14), strcspn(str13, str14));
  ck_assert_int_eq(s21_strcspn(str15, str16), strcspn(str15, str16));
}
END_TEST

START_TEST(strerror_test) {
  for (int i = 0; i <= MAX; i++) {
    ck_assert_str_eq(s21_strerror(i), strerror(i));
  }

  char unknown_error_neg[128];
  sprintf(unknown_error_neg, "Unknown error %d", -1);
  ck_assert_str_eq(s21_strerror(-1), unknown_error_neg);

  char unknown_error_pos[128];
  sprintf(unknown_error_pos, "Unknown error %d", 134);
  ck_assert_str_eq(s21_strerror(134), unknown_error_pos);
}
END_TEST

START_TEST(strlen_test) {
  char *str1 = "Hello world!";
  char *str2 = "_Hello!";
  char *str3 = "I am Groot!_";
  char *str4 = "Good boy";
  char *str5 = "Sweet gay";
  char *str6 = "Viktor Petrov";
  char *str7 = "I'm alone!";

  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
  ck_assert_int_eq(s21_strlen(str2), strlen(str2));
  ck_assert_int_eq(s21_strlen(str3), strlen(str3));
  ck_assert_int_eq(s21_strlen(str4), strlen(str4));
  ck_assert_int_eq(s21_strlen(str5), strlen(str5));
  ck_assert_int_eq(s21_strlen(str6), strlen(str6));
  ck_assert_int_eq(s21_strlen(str7), strlen(str7));
}
END_TEST

START_TEST(strpbrk_test) {
  char *str1 = "Hello Ben_;";
  char *str2 = "n";
  char *str3 = "what is your name";
  char *str4 = "r";
  char *str5 = "klon hr ___ fff L";
  char *str6 = "L";
  char *str7 = "     hrom out ! home";
  char *str8 = "!";
  char *str9 = "japonis of strong";
  char *str10 = "of";
  char *str11 = "Billi Gin nasral v kuvshin";
  char *str12 = " ";

  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_str_eq(s21_strpbrk(str3, str4), strpbrk(str3, str4));
  ck_assert_str_eq(s21_strpbrk(str5, str6), strpbrk(str5, str6));
  ck_assert_str_eq(s21_strpbrk(str7, str8), strpbrk(str7, str8));
  ck_assert_str_eq(s21_strpbrk(str9, str10), strpbrk(str9, str10));
  ck_assert_str_eq(s21_strpbrk(str11, str12), strpbrk(str11, str12));
}
END_TEST

START_TEST(test_strrchr) {
  char test1[12] = "01234543434";
  char test2[25] = ".../,,, / ,  / ";
  _ck_assert_ptr(s21_strrchr(test1, '3'), ==, strrchr(test1, '3'));
  _ck_assert_ptr(s21_strrchr(test2, ' '), ==, strrchr(test2, ' '));
}
END_TEST

START_TEST(test_strstr) {
  char test1[12] = "01234543434";
  char test2[25] = "hello aaa hello helloy";
  _ck_assert_ptr(s21_strstr(test1, "3"), ==, strstr(test1, "3"));
  _ck_assert_ptr(s21_strstr(test2, "hello"), ==, strstr(test2, "hello"));
}
END_TEST

START_TEST(test_strtok) {
  char test1[12] = "0 1 2 3";
  char test2[30] = "1234/4321/1234///";
  _ck_assert_ptr(s21_strtok(test1, " "), ==, strtok(test1, " "));
  _ck_assert_ptr(s21_strtok(test2, "/"), ==, strtok(test2, "/"));
}

END_TEST

START_TEST(sprintf_test) {
  char buffer1[10000];
  char buffer2[10000];
  int n1, n2;

  // Basic string and character tests
  n1 = s21_sprintf(buffer1, "Hello %s!", "World");
  n2 = sprintf(buffer2, "Hello %s!", "World");
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  // Clear buffers after each test
  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "Character: %c", 'A');
  n2 = sprintf(buffer2, "Character: %c", 'A');
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Integer tests
  n1 = s21_sprintf(buffer1, "%d", 123);
  n2 = sprintf(buffer2, "%d", 123);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%i", -123);
  n2 = sprintf(buffer2, "%i", -123);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Floating point tests
  n1 = s21_sprintf(buffer1, "%.0f", 3.14159);
  n2 = sprintf(buffer2, "%.0f", 3.14159);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Multi-format test
  n1 = s21_sprintf(buffer1, "%s %d %f %c %x", "Test", 123, 3.14, 'A', 0xFF);
  n2 = sprintf(buffer2, "%s %d %f %c %x", "Test", 123, 3.14, 'A', 0xFF);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%s%d%f%c%x", "Test", 123, 3.14, 'A', 0xFF);
  n2 = sprintf(buffer2, "%s%d%f%c%x", "Test", 123, 3.14, 'A', 0xFF);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %d
  n1 = s21_sprintf(buffer1, "%d", 123);
  n2 = sprintf(buffer2, "%d", 123);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%d", -456);
  n2 = sprintf(buffer2, "%d", -456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %i
  n1 = s21_sprintf(buffer1, "%i", 789);
  n2 = sprintf(buffer2, "%i", 789);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%i", -101112);
  n2 = sprintf(buffer2, "%i", -101112);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %c
  n1 = s21_sprintf(buffer1, "%c", 'A');
  n2 = sprintf(buffer2, "%c", 'A');
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%c", 'Z');
  n2 = sprintf(buffer2, "%c", 'Z');
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %s
  n1 = s21_sprintf(buffer1, "%s", "Hello");
  n2 = sprintf(buffer2, "%s", "Hello");
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%s", "World");
  n2 = sprintf(buffer2, "%s", "World");
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %f
  n1 = s21_sprintf(buffer1, "%f", 123.456);
  n2 = sprintf(buffer2, "%f", 123.456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%f", -789.012);
  n2 = sprintf(buffer2, "%f", -789.012);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %u
  n1 = s21_sprintf(buffer1, "%u", 123);
  n2 = sprintf(buffer2, "%u", 123);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%u", 456);
  n2 = sprintf(buffer2, "%u", 456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %x
  n1 = s21_sprintf(buffer1, "%x", 0x1A3);
  n2 = sprintf(buffer2, "%x", 0x1A3);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%x", 0x456);
  n2 = sprintf(buffer2, "%x", 0x456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %X
  n1 = s21_sprintf(buffer1, "%X", 0x1A3);
  n2 = sprintf(buffer2, "%X", 0x1A3);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%X", 0x456);
  n2 = sprintf(buffer2, "%X", 0x456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %o
  n1 = s21_sprintf(buffer1, "%o", 123);
  n2 = sprintf(buffer2, "%o", 123);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%o", 456);
  n2 = sprintf(buffer2, "%o", 456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %e
  n1 = s21_sprintf(buffer1, "%e", 123.456);
  n2 = sprintf(buffer2, "%e", 123.456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%e", -789.012);
  n2 = sprintf(buffer2, "%e", -789.012);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %E
  n1 = s21_sprintf(buffer1, "%E", 123.456);
  n2 = sprintf(buffer2, "%E", 123.456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%E", -789.012);
  n2 = sprintf(buffer2, "%E", -789.012);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %g
  n1 = s21_sprintf(buffer1, "%g", 123.456);
  n2 = sprintf(buffer2, "%g", 123.456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%g", -789.012);
  n2 = sprintf(buffer2, "%g", -789.012);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  // Test for %G
  n1 = s21_sprintf(buffer1, "%G", 123.456);
  n2 = sprintf(buffer2, "%G", 123.456);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));

  n1 = s21_sprintf(buffer1, "%G", -789.012);
  n2 = sprintf(buffer2, "%G", -789.012);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(n1, n2);

  memset(buffer1, 0, sizeof(buffer1));
  memset(buffer2, 0, sizeof(buffer2));
}
END_TEST

int main(void) {
  Suite *s = suite_create("String Functions");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, memchr_test);
  tcase_add_test(tc_core, memcmp_test);
  tcase_add_test(tc_core, memcpy_test);
  tcase_add_test(tc_core, memset_test);
  tcase_add_test(tc_core, strncat_test);
  tcase_add_test(tc_core, strchr_test);
  tcase_add_test(tc_core, strncmp_test);
  tcase_add_test(tc_core, strncpy_test);
  tcase_add_test(tc_core, strcspn_test);
  tcase_add_test(tc_core, strerror_test);
  tcase_add_test(tc_core, strlen_test);
  tcase_add_test(tc_core, strpbrk_test);
  tcase_add_test(tc_core, test_strrchr);
  tcase_add_test(tc_core, test_strstr);
  tcase_add_test(tc_core, test_strtok);
  tcase_add_test(tc_core, sprintf_test);

  suite_add_tcase(s, tc_core);

  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
