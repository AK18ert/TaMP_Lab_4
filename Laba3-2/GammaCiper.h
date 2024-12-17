/** @brief Шифрование методом маршрутной перестановки
* @details Ключ устанавливается в конструкторе.
* Для зашифровывания и расшифровывания предназначены методы encrypt и decrypt.
* @warning Реализация только для русского языка(Наверное)
*/
#pragma once
#include <locale>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <codecvt>
class GammaCipher
{
	private:
		int key; /// Ключ
	public:
		GammaCipher() = delete; ///запрет конструктор без параметров
		GammaCipher(int key); ///конструктор для установки ключа
		std::wstring encrypt(const std::wstring& text); ///Метод шифрования
		std::wstring decrypt(const std::wstring& encrypted_text);///Метод расшифрования
		std::wstring getValidKey(const std::wstring & s); /// Метод обработок ошибок связанных с ключами
		std::wstring getValidOpenText(const std::wstring & s); /// Метод обработок ошибок связанных с текстом для шифрования
		std::wstring getValidCipherText(const std::wstring & s);/// Метод обработок ошибок связанных с текстом для расшифрования 
};
/** @brief Обработка ошибок
* @details Оно работает
* @warning Я не знаю как
*/
class cipher_error: public std::invalid_argument {
public:
	explicit cipher_error (const std::string& what_arg):
		std::invalid_argument(what_arg) {}
	explicit cipher_error (const char* what_arg):
		std::invalid_argument(what_arg) {}
};
