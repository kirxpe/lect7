#include "mycode.h"


std::string strip(const std::string& str) {
    // Находим первый непробельный символ с начала строки
    size_t start = str.find_first_not_of(" \t\n\r\f\v");

    // Если строка состоит только из пробельных символов, возвращаем пустую строку
    if (start == std::string::npos)
        return "";

    // Находим последний непробельный символ с конца строки
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    // Возвращаем подстроку без пробелов с начала и конца
    return str.substr(start, end - start + 1);
}
void hello(istream &ist, ostream& ost) {
    std::string name;

    ist >> name;
    name = strip(name);
    ost << "hello " << name;
}
