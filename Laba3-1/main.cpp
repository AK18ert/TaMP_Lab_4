/** @file main.cpp
 * @author Кочегаров А. И.
 * @version 1.0
 * @brief Функция main
 * @date 15.12.2024
 * @copyright ИБСТ ПГУ
 */
#include "modAlphaCipher.h"
#include <stdexcept>
#include <cctype>
#include <iostream>
#include <locale>
#include <string>
#include <codecvt>


using namespace std;


void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{ 
	try {
		setlocale(LC_ALL, "ru_RU.UTF-8");
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text); /// зашифровывание
		if (destructCipherText) 
			cipherText.front() = tolower(cipherText.front()); 
		decryptedText = cipher.decrypt(cipherText); /// расшифровывание
		wcout<<"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		cerr<<"Error: "<<e.what()<<endl;
	}
}

int main(int argc, char **argv)
{ 
	setlocale(LC_ALL, "ru_RU.UTF-8");
	check(L"МАМАМЫЛАРАМУ", L"КОЛЯ");
	return 0;
}