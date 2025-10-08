#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    FILE *file;
    char username_from_file[100]; // Giả sử tên người dùng không quá 100 ký tự

    // Mở file để đọc
    file = fopen("conf/username.txt", "r");
    TEST_ASSERT_NOT_NULL_MESSAGE(file, "Could not open username.txt");

    // Đọc tên người dùng từ file
    fgets(username_from_file, sizeof(username_from_file), file);
    fclose(file);

    // Xóa ký tự newline nếu có
    username_from_file[strcspn(username_from_file, "\n")] = 0;

    // So sánh tên người dùng từ file với tên người dùng từ hàm
    TEST_ASSERT_EQUAL_STRING_MESSAGE(username_from_file, "tuanhuu309", "Usernames do not match!");
}
