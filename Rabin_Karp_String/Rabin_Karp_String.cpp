#include <iostream>
#include <string>

int find_substring_light_rabin_karp(std::string source, std::string substring) {

    int sub_hash, hash;
    sub_hash = hash = 0;

    for (int i = 0; i < substring.length(); i++) {
        sub_hash += static_cast<int>(substring[i]);
    }

    for (int i = 0; i <= source.length() - substring.length(); i++) {

        if (i == 0) {
            for (int i = 0; i < substring.length(); i++) {
                hash += static_cast<int>(source[i]);
            }
        }
        else {
            hash -= static_cast<int>(source[i - 1]);
            hash += static_cast<int>(source[i + substring.length() - 1]);
        }

        if (hash == sub_hash) {
            for (int j = 0; j < substring.length(); j++) {
                if (source[i + j] != substring[j]) {
                    break;
                }
            }
            return i;
        }
    }

    return -1;
}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    std::string source, substring;

    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::getline(std::cin, source);

    do {
        std::cout << "Введите подстроку, которую нужно найти:  ";
        std::getline(std::cin, substring);

        if (find_substring_light_rabin_karp(source, substring) != -1) {
            std::cout << "Подстрока " << substring << " найдена по индексу " << find_substring_light_rabin_karp(source, substring) << std::endl;
        }
        else {
            std::cout << "Подстрока " << substring << " не найдена" << std::endl;
        }

    } while (substring != "exit");

    return 0;
}