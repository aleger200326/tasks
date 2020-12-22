//

#include <iostream>
#include <fstream>

char Base64Char(unsigned char b) {
	b &= 0x3F;
/*	char Base64Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	return Base64Alphabet[b];
*/
	if (b < 26) return 'A' + b;
	if (b < 52) return 'a' + (b - 26);
	if (b < 62) return '0' + (b - 52);
	if (b == 62) return '+';
	return '/';
}

int Base64Encode(char *inStr, int Len, char *outStr) {
	/*
		inStr - РІС…РѕРґРЅРѕР№ СЃС‚СЂРѕРєРѕР№
		Len - РґР»РёРЅР° РІС…РѕРґРЅРѕР№ СЃС‚СЂРѕРєРё, РєРѕР»РёС‡РµСЃС‚РІРѕ СЃРёРјРІРѕР»РѕРІ, РєРѕС‚РѕСЂС‹Рµ РЅСѓР¶РЅРѕ РєРѕРґРёСЂРѕРІР°С‚СЊ
		outStr - РІС‹С…РѕРґРЅР°СЏ СЃС‚СЂРѕРєР°
		Р¤СѓРЅРєС†РёСЏ РІРѕР·РІСЂР°С‰Р°РµС‚ РєРѕР»РёС‡РµСЃС‚РІРѕ СЃРёРјРІРѕР»РѕРІ РІ РІС‹С…РѕРґРЅРѕР№ СЃС‚СЂРѕРєРµ.
	*/
	int i = 0, j = 0; // i - РёРЅРґРµРєСЃ РІРѕ РІС…РѕРґРЅРѕР№ СЃС‚СЂРѕРєРµ, j - РёРЅРґРµРєСЃ РІ РІС‹С…РѕРґРЅРѕР№ СЃС‚СЂРѕРєРµ
	unsigned char a1, a2, a3;
	unsigned char b1, b2, b3, b4;

	for (i = 0; i < Len; i += 3) {
		a1 = a2 = a3 = 0;
		b1 = b2 = b3 = b4 = 0;
		
		a1 = inStr[i];
		if (i+1 < Len) a2 = inStr[i + 1];
		if (i+2 < Len) a3 = inStr[i + 2];

		b1 = a1 >> 2;
		b2 = ((a1 & 0x3) << 4) | (a2 >> 4);
		b3 = ((a2 & 0xF) << 2) | (a3 >> 6);
		b4 = a3 & 0x3F;

		outStr[j++] = Base64Char(b1);
		outStr[j++] = Base64Char(b2);
		outStr[j++] = (i + 1 < Len) ? Base64Char(b3) : '=';
		outStr[j++] = (i + 2 < Len) ? Base64Char(b4) : '=';
	}
	
	return j;
}

int main()
{
/*	char input[] = "Hello world! ";
	char output[256];
	int result;
	result = Base64Encode(input, strlen(input), output);
	output[result] = '\0';
	std::cout << output << std::endl;
*/
	char inputFileName[1024];
	char outputFileName[1024];
	std::cout << "Input source file name: ";
	std::cin.getline(inputFileName, 1024);
	
	std::ifstream inFile(inputFileName, std::ios_base::binary);
	if (!inFile) {
		std::cout << "Can not open file " << inputFileName << std::endl;
		return 1;
	}

	std::cout << "Input destination file name: ";
	std::cin.getline(outputFileName, 1024);

	std::ofstream outFile(outputFileName);
	if (!outFile) {
		inFile.close();
		std::cout << "Can not write to file " << outputFileName << std::endl;
		return 2;
	}
	const int block_size = 19;
	char inStr[3*block_size], outStr[4*block_size];
	int s;
	while (inFile.peek()!=EOF) {
		inFile.read(inStr, 3*block_size); // РџРѕРїС‹С‚Р°РµРјСЃСЏ РїСЂРѕС‡РёС‚Р°С‚СЊ РёР· С„Р°Р№Р»Р° 3*block_size Р±Р°Р№С‚ Рё Р·Р°РїРёСЃР°С‚СЊ РІ inStr
		s = inFile.gcount(); // РЎРєРѕР»СЊРєРѕ Р±С‹Р»Рѕ РїСЂРѕС‡РёС‚Р°РЅРѕ РїСЂРё РїРѕСЃР»РµРґРЅРµР№ РїРѕРїС‹С‚РєРµ
		s = Base64Encode(inStr, s, outStr);
		outFile.write(outStr, s);
		outFile << std::endl;
	}

	inFile.close();
	outFile.close();
	std::cout << "Encoded - OK" << std::endl;
}
