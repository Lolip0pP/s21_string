#include <stdio.h>

// Макрос для определения операционной системы
#ifdef __APPLE__
    #define S21_OS_MACOS
#endif

#ifdef __linux__
    #define S21_OS_LINUX
#endif

// Макросы с сообщениями об ошибках для macOS
#ifdef S21_OS_MACOS
    static const char *mac_error_messages[] = {
        "No error",            // 0
        "Operation not permitted",  // 1
        "No such file or directory", // 2
        // Добавьте другие сообщения об ошибках для macOS
    };
#endif

// Макросы с сообщениями об ошибках для Linux
#ifdef S21_OS_LINUX
    static const char *linux_error_messages[] = {
        "Success",              // 0
        "Operation not permitted",  // 1
        "No such file or directory", // 2
        // Добавьте другие сообщения об ошибках для Linux
    };
#endif

char *s21_strerror(int errnum) {
    // Инициализируем указатель на строку с сообщением об ошибке
    const char *error_message = NULL;

#ifdef S21_OS_MACOS
    // Поиск сообщения об ошибке в массиве для macOS
    if (errnum >= 0 && errnum < sizeof(mac_error_messages) / sizeof(mac_error_messages[0])) {
        error_message = mac_error_messages[errnum];
    }
#endif

#ifdef S21_OS_LINUX
    // Поиск сообщения об ошибке в массиве для Linux
    if (errnum >= 0 && errnum < sizeof(linux_error_messages) / sizeof(linux_error_messages[0])) {
        error_message = linux_error_messages[errnum];
    }
#endif

    // Если сообщение об ошибке найдено, возвращаем его
    if (error_message != NULL) {
        return (char *)error_message;
    } else {
        // Если сообщение об ошибке не найдено, возвращаем "Unknown error"
        return "Unknown error";
    }
}

int main() {
    // Пример использования функции s21_strerror
    printf("%s\n", s21_strerror(1)); // Для операционной системы macOS: "Operation not permitted"
    printf("%s\n", s21_strerror(2)); // Для операционной системы Linux: "No such file or directory"
    printf("%s\n", s21_strerror(100)); // "Unknown error"

    return 0;
}

