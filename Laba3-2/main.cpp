/** @file main.cpp
 * @author Кочегаров А. И.
 * @version 1.0
 * @brief Функция main
 * @date 15.12.2024
 * @copyright ИБСТ ПГУ
 */
#include <GammaCiper.h>
#include <iostream>
#include <limits>
#include <locale>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <codecvt>
using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int key;
	wstring text;
	unsigned op;
	while(true) { 
		wcout << L"Введите ключ: ";
		if(wcin >> key) {
			if(key == 0) {
				wcout << L"Ключ не должен быть равен 0. Попробуйте снова.\n";
				wcin.clear();
				wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
				continue;
			}
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
			break;
		} else {
			wcout << L"Неверный ввод ключа. Ключ - число больше нуля.\n";
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
		}
	}
	GammaCipher cipher(key);
	wcout << L"Ключ загружен\n";
	do {
		wcout << L"Шифр готов. Выберите операцию (0-выход, 1-зашифровать, 2-расшифровать, 3-сменить ключ): ";
		if(wcin >> op) {
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
			if(op > 3) {
				wcout << L"Неправильная операция\n";
			} else if(op == 3) {
				while(true) { 
					wcout << L"Введите новый ключ: ";
					if(wcin >> key) {
						if(key == 0) {
							wcout << L"Ключ не должен быть равен 0. Попробуйте снова.\n";
							wcin.clear();
							wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
							continue;
						}
						wcin.ignore(numeric_limits<streamsize>::max(),L'\n');
						cipher = GammaCipher(key);
						wcout << L"Ключ успешно изменён\n";
						break;
					} else {
					wcout << L"Неверный ввод ключа. Попробуйте снова.\n";
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					}
				}
			} else if(op > 0) {
				wcout << L"Введите текст: ";
				getline(wcin, text);
				if (key > text.length()){
					wcout << L"Операция отменена: Ключ не соответствует размеру текста\n";
					wcin.clear();
					wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
					continue;
					}
				if(op == 1) {
					wcout << L"Зашифрованный текст: " << endl;
					wcout << cipher.encrypt(text) << endl;
				} else {
					wcout << L"Расшифрованный текст: " <<
					cipher.decrypt(text) << endl;
				}
			} else {
				wcout << L"Операция отменена: неправильный текст\n";
			}
		} else {
			wcout << L"Неверный ввод операции. Попробуйте снова.\n";
			wcin.clear();
			wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
		}
	} while(op != 0);
	return 0;
}