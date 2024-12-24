#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;


bool checkUserStringIsCorrect(string userWord, int length)
{
	if (size(userWord) == length)
	{
		return 1;
	}
	else return 0;
}

bool isReverseEqualRecursiveSTRING(string original, string reversed, int length)
{
	if (original == " " || reversed == " ")
	{
		return false;
	}
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (original[i] == reversed[length - i - 1])
		{
			counter++;
		}
	}
	if (counter == length)
	{
		return true;
	}
	else return false;
}

bool randomTrue(int first, int second, int therth, int four, int five)
{
	int counter = 0;
	if (first != second && first != therth && first != four && first != five)
	{
		counter++;
	}
	if (second != therth && second != four && second != five)
	{
		counter++;
	}
	if (therth != four && therth != five)
	{
		counter++;
	}
	if (four != five)
	{
		counter++;
	}
	if (counter == 4)
	{
		return 1;
	}
	else return 0;
}


string toUPPERCase(const string& input) {
	std::string result = input;
	for (char& c : result) {
		c = toupper(static_cast<unsigned char>(c)); // ����������� ������ � ������� �������
	}
	return result;
}


void clearConsoleAfterDelay(int seconds) {
	this_thread::sleep_for(chrono::seconds(seconds)); // �������� � ��������
	system("CLS"); // ������� ������� � Windows
}

void firstTASK(string path, int size)
{
	int counterWork5 = 0;

	int numberOfWordFromFile;

	while (counterWork5 != 3)
	{
		system("color 07");

		cout << "---------------------\n ||    �����: " << counterWork5 << "   ||\n---------------------\n\n";


		string Line;
		fstream word_5;

		string wordFromFile;
		string userWord;

		int counterWORD = 1;
		srand(time(NULL));
		word_5.open(path, fstream::app | fstream::in | fstream::out);
		numberOfWordFromFile = 1 + rand() % 60;
		while (getline(word_5, Line))
		{

			if (counterWORD == numberOfWordFromFile)
			{
				wordFromFile = Line;
				break;
			}
			else counterWORD++;
		}
		word_5.close();

		string finalWordFromFile = toUPPERCase(wordFromFile);

		cout << "�����, ������� ����� ���������!\n\n ---> --->  " << finalWordFromFile << endl;

		clearConsoleAfterDelay(5);

		cout << "������� ����� ����� �������:\n";


		SetConsoleCP(1251);
		cin >> userWord;
		if (checkUserStringIsCorrect(userWord, size))
		{
			SetConsoleCP(866);

			string finalUserWord = toUPPERCase(userWord);

			if (isReverseEqualRecursiveSTRING(finalWordFromFile, finalUserWord, size))
			{
				system("color 02");
				cout << "���������! �� ������� =)";
				counterWork5++;
				clearConsoleAfterDelay(3);
			}
			else
			{
				system("color 04");
				cout << "����������� =(";
				counterWork5 = 0;
				clearConsoleAfterDelay(3);
			}
		}
		else
		{
			system("color 04");
			cout << "����������� =(";
			counterWork5 = 0;
			clearConsoleAfterDelay(3);
		}


	}
}

void secondTASK(string path, int size)
{

	int counterWork5 = 0;
	string userWords[5];
	string wordsFromFile[5];

	while (counterWork5 != 3)
	{
		system("color 07");
		cout << "---------------------\n ||    �����: " << counterWork5 << "   ||\n---------------------\n\n";
		string Line;
		fstream word_5;

		string wordFromFile;

		int counterWORD = 1;
		srand(time(NULL));
		word_5.open(path, fstream::app | fstream::in | fstream::out);

		int numberOfWordFromFile1 = 0;
		int numberOfWordFromFile2 = 0;
		int numberOfWordFromFile3 = 0;
		int numberOfWordFromFile4 = 0;
		int numberOfWordFromFile5 = 0;
		do
		{
			numberOfWordFromFile1 = 1 + rand() % 60;
			numberOfWordFromFile2 = 1 + rand() % 60;
			numberOfWordFromFile3 = 1 + rand() % 60;
			numberOfWordFromFile4 = 1 + rand() % 60;
			numberOfWordFromFile5 = 1 + rand() % 60;
		} while (!randomTrue(numberOfWordFromFile1, numberOfWordFromFile2, numberOfWordFromFile3, numberOfWordFromFile4, numberOfWordFromFile5));


		while (getline(word_5, Line))
		{

			if (counterWORD == numberOfWordFromFile1)
			{
				wordsFromFile[0] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile2)
			{
				wordsFromFile[1] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile3)
			{
				wordsFromFile[2] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile4)
			{
				wordsFromFile[3] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile5)
			{
				wordsFromFile[4] = Line;
				counterWORD++;
				continue;
			}

			counterWORD++;

		}
		word_5.close();

		for (int i = 0; i < 5; i++)
		{
			wordsFromFile[i] = toUPPERCase(wordsFromFile[i]);
		}
		cout << "�����, ������� ����� ���������!\n\n ---> --->  ";
		for (int i = 0; i < 5; i++)
		{
			cout << wordsFromFile[i] << " ";
		}
		cout << endl;

		clearConsoleAfterDelay(5);

		cout << "������� ��� ����� ������� �� ���������, ������� �� ����� ��������:\n";
		SetConsoleCP(1251);
		for (int i = 0; i < 5; i++)
		{
			cin >> userWords[i];
		}
		cin.clear();
		while (cin.get() != '\n');
		int counterCHECK = 0;
		for (int i = 0; i < 5; i++)
		{
			if (checkUserStringIsCorrect(userWords[i], size))
			{
				counterCHECK++;
			}
		}
		if (counterCHECK == 5)
		{
			SetConsoleCP(866);

			for (int i = 0; i < 5; i++)
			{
				userWords[i] = toUPPERCase(userWords[i]);
			}
			int counterTEMP = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (userWords[j] == wordsFromFile[i])
					{
						userWords[j] = " ";
						wordsFromFile[i] = " ";
						counterTEMP++;
						break;
					}
				}
			}
			if (counterTEMP == 5)
			{
				system("color 02");
				cout << "���������! �� ������� =)";
				counterWork5++;
				clearConsoleAfterDelay(3);
			}
			else
			{
				system("color 04");
				cout << "����������� =(";
				counterWork5 = 0;
				clearConsoleAfterDelay(3);
			}

		}
		else
		{
			system("color 04");
			cout << "����������� =(";
			counterWork5 = 0;
			clearConsoleAfterDelay(3);
		}

	}
}

void thirdTASK(string path, int size)
{
	int counterWork5 = 0;
	string userWords[5];
	string wordsFromFile[5];

	while (counterWork5 != 3)
	{
		system("color 07");
		cout << "---------------------\n ||    �����: " << counterWork5 << "   ||\n---------------------\n\n";
		string Line;
		fstream word_5;

		string wordFromFile;

		int counterWORD = 1;
		srand(time(NULL));
		word_5.open(path, fstream::app | fstream::in | fstream::out);

		int numberOfWordFromFile1 = 0;
		int numberOfWordFromFile2 = 0;
		int numberOfWordFromFile3 = 0;
		int numberOfWordFromFile4 = 0;
		int numberOfWordFromFile5 = 0;
		do
		{
			numberOfWordFromFile1 = 1 + rand() % 60;
			numberOfWordFromFile2 = 1 + rand() % 60;
			numberOfWordFromFile3 = 1 + rand() % 60;
			numberOfWordFromFile4 = 1 + rand() % 60;
			numberOfWordFromFile5 = 1 + rand() % 60;
		} while (!randomTrue(numberOfWordFromFile1, numberOfWordFromFile2, numberOfWordFromFile3, numberOfWordFromFile4, numberOfWordFromFile5));


		while (getline(word_5, Line))
		{

			if (counterWORD == numberOfWordFromFile1)
			{
				wordsFromFile[0] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile2)
			{
				wordsFromFile[1] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile3)
			{
				wordsFromFile[2] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile4)
			{
				wordsFromFile[3] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile5)
			{
				wordsFromFile[4] = Line;
				counterWORD++;
				continue;
			}

			counterWORD++;

		}
		word_5.close();

		for (int i = 0; i < 5; i++)
		{
			wordsFromFile[i] = toUPPERCase(wordsFromFile[i]);
		}
		cout << "�����, ������� ����� ���������!\n\n ---> --->  ";
		for (int i = 0; i < 5; i++)
		{
			cout << wordsFromFile[i] << " ";
		}
		cout << endl;

		clearConsoleAfterDelay(5);

		cout << "������� ��� ����� ������� �� ��������� � ������ �������:\n";


		SetConsoleCP(1251);
		for (int i = 0; i < 5; i++)
		{
			cin >> userWords[i];
		}
		int counterCHECK = 0;
		for (int i = 0; i < 5; i++)
		{
			if (checkUserStringIsCorrect(userWords[i], size))
			{
				counterCHECK++;
			}
		}
		if (counterCHECK == 5)
		{
			SetConsoleCP(866);

			for (int i = 0; i < 5; i++)
			{
				userWords[i] = toUPPERCase(userWords[i]);
			}

			int counterTEMP = 0;

			for (int i = 0; i < 5; i++)
			{
				if (userWords[i] == wordsFromFile[i])
				{
					counterTEMP++;
					continue;
				}
			}

			if (counterTEMP == 5)
			{
				system("color 02");
				cout << "���������! �� ������� =)";
				counterWork5++;
				clearConsoleAfterDelay(3);
			}
			else
			{
				system("color 04");
				cout << "����������� =(";
				counterWork5 = 0;
				clearConsoleAfterDelay(3);
			}


		}
		else
		{
			system("color 04");
			cout << "����������� =(";
			counterWork5 = 0;
			clearConsoleAfterDelay(3);
		}

	}



}

void fourthTASK(string path, int size)
{
	int counterWork5 = 0;
	string userWords[5];
	string wordsFromFile[5];

	while (counterWork5 != 3)
	{
		system("color 07");
		cout << "---------------------\n ||    �����: " << counterWork5 << "   ||\n---------------------\n\n";
		string Line;
		fstream word_5;

		string wordFromFile;

		int counterWORD = 1;
		srand(time(NULL));
		word_5.open(path, fstream::app | fstream::in | fstream::out);

		int numberOfWordFromFile1 = 0;
		int numberOfWordFromFile2 = 0;
		int numberOfWordFromFile3 = 0;
		int numberOfWordFromFile4 = 0;
		int numberOfWordFromFile5 = 0;
		do
		{
			numberOfWordFromFile1 = 1 + rand() % 60;
			numberOfWordFromFile2 = 1 + rand() % 60;
			numberOfWordFromFile3 = 1 + rand() % 60;
			numberOfWordFromFile4 = 1 + rand() % 60;
			numberOfWordFromFile5 = 1 + rand() % 60;
		} while (!randomTrue(numberOfWordFromFile1, numberOfWordFromFile2, numberOfWordFromFile3, numberOfWordFromFile4, numberOfWordFromFile5));


		while (getline(word_5, Line))
		{

			if (counterWORD == numberOfWordFromFile1)
			{
				wordsFromFile[0] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile2)
			{
				wordsFromFile[1] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile3)
			{
				wordsFromFile[2] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile4)
			{
				wordsFromFile[3] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile5)
			{
				wordsFromFile[4] = Line;
				counterWORD++;
				continue;
			}

			counterWORD++;

		}
		word_5.close();

		for (int i = 0; i < 5; i++)
		{
			wordsFromFile[i] = toUPPERCase(wordsFromFile[i]);
		}
		cout << "�����, ������� ����� ���������!\n\n ---> --->  ";
		for (int i = 0; i < 5; i++)
		{
			cout << wordsFromFile[i] << " ";
		}
		cout << endl;

		clearConsoleAfterDelay(5);

		cout << "������� ��� ����� ������� �� ��������� ����� ������, ������� �� ����� ��������:\n";
		SetConsoleCP(1251);
		for (int i = 0; i < 5; i++)
		{
			cin >> userWords[i];
		}
		int counterCHECK = 0;
		for (int i = 0; i < 5; i++)
		{
			if (checkUserStringIsCorrect(userWords[i], size))
			{
				counterCHECK++;
			}
		}
		if (counterCHECK == 5)
		{
			SetConsoleCP(866);

			for (int i = 0; i < 5; i++)
			{
				userWords[i] = toUPPERCase(userWords[i]);
			}

			int counterTEMP = 0;

			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{

					if (isReverseEqualRecursiveSTRING(wordsFromFile[i], userWords[j], size))
					{
						userWords[j] = " ";
						wordsFromFile[i] = " ";
						counterTEMP++;
						break;
					}
				}
			}
			if (counterTEMP == 5)
			{
				system("color 02");
				cout << "���������!";
				counterWork5++;
				clearConsoleAfterDelay(3);
			}
			else
			{
				system("color 04");
				cout << "����������� =(";
				counterWork5 = 0;
				clearConsoleAfterDelay(3);
			}
		}
		else
		{
			system("color 04");
			cout << "����������� =(";
			counterWork5 = 0;
			clearConsoleAfterDelay(3);
		}

	}


}

void fifthTASK(string path, int size)
{

	int counterWork5 = 0;
	string userWords[5];
	string wordsFromFile[5];

	while (counterWork5 != 3)
	{
		system("color 07");
		cout << "---------------------\n ||    �����: " << counterWork5 << "   ||\n---------------------\n\n";
		string Line;
		fstream word_5;

		string wordFromFile;

		int counterWORD = 1;
		srand(time(NULL));
		word_5.open(path, fstream::app | fstream::in | fstream::out);

		int numberOfWordFromFile1 = 0;
		int numberOfWordFromFile2 = 0;
		int numberOfWordFromFile3 = 0;
		int numberOfWordFromFile4 = 0;
		int numberOfWordFromFile5 = 0;
		do
		{
			numberOfWordFromFile1 = 1 + rand() % 60;
			numberOfWordFromFile2 = 1 + rand() % 60;
			numberOfWordFromFile3 = 1 + rand() % 60;
			numberOfWordFromFile4 = 1 + rand() % 60;
			numberOfWordFromFile5 = 1 + rand() % 60;
		} while (!randomTrue(numberOfWordFromFile1, numberOfWordFromFile2, numberOfWordFromFile3, numberOfWordFromFile4, numberOfWordFromFile5));


		while (getline(word_5, Line))
		{

			if (counterWORD == numberOfWordFromFile1)
			{
				wordsFromFile[0] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile2)
			{
				wordsFromFile[1] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile3)
			{
				wordsFromFile[2] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile4)
			{
				wordsFromFile[3] = Line;
				counterWORD++;
				continue;
			}
			if (counterWORD == numberOfWordFromFile5)
			{
				wordsFromFile[4] = Line;
				counterWORD++;
				continue;
			}

			counterWORD++;

		}
		word_5.close();

		for (int i = 0; i < 5; i++)
		{
			wordsFromFile[i] = toUPPERCase(wordsFromFile[i]);
		}
		cout << "�����, ������� ����� ���������!\n\n ---> --->  ";
		for (int i = 0; i < 5; i++)
		{
			cout << wordsFromFile[i] << " ";
		}
		cout << endl;

		clearConsoleAfterDelay(5);

		cout << "������� ��� ����� ������� �� ��������� ����� ������ � ������ �������:\n";
		SetConsoleCP(1251);
		for (int i = 0; i < 5; i++)
		{
			cin >> userWords[i];
		}
		int counterCHECK = 0;
		for (int i = 0; i < 5; i++)
		{
			if (checkUserStringIsCorrect(userWords[i], size))
			{
				counterCHECK++;
			}
		}
		if (counterCHECK == 5)
		{
			SetConsoleCP(866);

			for (int i = 0; i < 5; i++)
			{
				userWords[i] = toUPPERCase(userWords[i]);
			}

			int counterTEMP = 0;

			for (int i = 0; i < 5; i++)
			{

				if (isReverseEqualRecursiveSTRING(wordsFromFile[i], userWords[i], size))
				{
					userWords[i] = " ";
					wordsFromFile[i] = " ";
					counterTEMP++;
				}
			}
			if (counterTEMP == 5)
			{
				system("color 02");
				cout << "���������!";
				counterWork5++;
				clearConsoleAfterDelay(3);
			}
			else
			{
				system("color 04");
				cout << "����������� =(";
				counterWork5 = 0;
				clearConsoleAfterDelay(3);
			}
		}
		else
		{
			system("color 04");
			cout << "����������� =(";
			counterWork5 = 0;
			clearConsoleAfterDelay(3);
		}

	}



}


int main()
{
	while (true) {
		setlocale(LC_ALL, "ru");
		int programm;
		cout << "������� 1 ��� ������ ����" << endl;
		cout << "������� 0 ����� �����" << endl;
		cin >> programm;

		srand(time(NULL));

		if (programm == 1) {

			int TASK = 2;

			int size = 5;

			int wordsIsNow = 5;

			string words5 = "words5.txt";
			string words6 = "words6.txt";
			string words7 = "words7.txt";
			string words8 = "words8.txt";

			while (TASK == 1) {

				if (wordsIsNow == 5)
				{
					system("color 07");
					system("cls");
					cout << "������� �� 5 ����!";
					clearConsoleAfterDelay(3);
					firstTASK(words5, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 5 ����";
				}

				if (wordsIsNow == 6)
				{
					system("color 07");
					cout << "\n������� �� 6 ����!";
					clearConsoleAfterDelay(3);
					firstTASK(words6, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 6 ����";
				}

				if (wordsIsNow == 7)
				{
					system("color 07");
					cout << "\n������� �� 7 ����!";
					clearConsoleAfterDelay(3);
					firstTASK(words7, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 7 ����";
				}

				if (wordsIsNow == 8)
				{
					system("color 07");
					cout << "\n������� �� 8 ����!";
					clearConsoleAfterDelay(3);
					firstTASK(words8, size);
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 8 ����\n";
					cout << "������ ���� �������!";
					TASK = 2;
					wordsIsNow = 5;

				}

			}

			while (TASK == 2)
			{
				wordsIsNow = 5;
				size = 5;
				if (wordsIsNow == 5)
				{
					system("color 07");
					clearConsoleAfterDelay(2);
					cout << "���� 2\n������� �� 5 ����!";
					clearConsoleAfterDelay(3);
					secondTASK(words5, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 5 ����";
				}

				if (wordsIsNow == 6)
				{
					system("color 07");
					cout << "\n������� �� 6 ����!";
					clearConsoleAfterDelay(3);
					secondTASK(words6, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 6 ����";
				}

				if (wordsIsNow == 7)
				{
					system("color 07");
					cout << "\n������� �� 7 ����!";
					clearConsoleAfterDelay(3);
					secondTASK(words7, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 7 ����";
				}

				if (wordsIsNow == 8)
				{
					system("color 07");
					cout << "\n������� �� 8 ����!";
					clearConsoleAfterDelay(3);
					secondTASK(words8, size);
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 8 ����\n";
					cout << "������ ���� �������!";
					TASK = 3;

				}

			}

			while (TASK == 3)
			{
				wordsIsNow = 5;
				size = 5;
				if (wordsIsNow == 5)
				{
					system("color 07");
					clearConsoleAfterDelay(2);
					cout << "���� 3\n������� �� 5 ����!";
					clearConsoleAfterDelay(3);
					thirdTASK(words5, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 5 ����";
				}

				if (wordsIsNow == 6)
				{
					system("color 07");
					cout << "\n������� �� 6 ����!";
					clearConsoleAfterDelay(3);
					thirdTASK(words6, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 6 ����";
				}

				if (wordsIsNow == 7)
				{
					system("color 07");
					cout << "\n������� �� 7 ����!";
					clearConsoleAfterDelay(3);
					thirdTASK(words7, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 7 ����";
				}

				if (wordsIsNow == 8)
				{
					system("color 07");
					cout << "\n������� �� 8 ����!";
					clearConsoleAfterDelay(3);
					thirdTASK(words8, size);
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 8 ����\n";
					cout << "������ ���� �������!";
					TASK = 4;

				}


			}

			while (TASK == 4)
			{
				wordsIsNow = 5;
				size = 5;
				if (wordsIsNow == 5)
				{
					system("color 07");
					clearConsoleAfterDelay(2);
					cout << "���� 4\n������� �� 5 ����!";
					clearConsoleAfterDelay(3);
					fourthTASK(words5, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 5 ����";
				}

				if (wordsIsNow == 6)
				{
					system("color 07");
					cout << "\n������� �� 6 ����!";
					clearConsoleAfterDelay(3);
					fourthTASK(words6, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 6 ����";
				}

				if (wordsIsNow == 7)
				{
					system("color 07");
					cout << "\n������� �� 7 ����!";
					clearConsoleAfterDelay(3);
					fourthTASK(words7, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 7 ����";
				}

				if (wordsIsNow == 8)
				{
					system("color 07");
					cout << "\n������� �� 8 ����!";
					clearConsoleAfterDelay(3);
					fourthTASK(words8, size);
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 8 ����\n";
					cout << "�������� ���� �������!";
					TASK = 5;

				}
			}

			while (TASK == 5)
			{
				wordsIsNow = 5;
				size = 5;
				if (wordsIsNow == 5)
				{
					system("color 07");
					clearConsoleAfterDelay(2);
					cout << "���� 5\n������� �� 5 ����!";
					clearConsoleAfterDelay(3);
					fifthTASK(words5, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 5 ����";
				}

				if (wordsIsNow == 6)
				{
					system("color 07");
					cout << "\n������� �� 6 ����!";
					clearConsoleAfterDelay(3);
					fifthTASK(words6, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 6 ����";
				}

				if (wordsIsNow == 7)
				{
					system("color 07");
					cout << "\n������� �� 7 ����!";
					clearConsoleAfterDelay(3);
					fifthTASK(words7, size);
					size++;
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 7 ����";
				}

				if (wordsIsNow == 8)
				{
					system("color 07");
					cout << "\n������� �� 8 ����!";
					clearConsoleAfterDelay(3);
					fifthTASK(words8, size);
					wordsIsNow++;
					system("cls");
					cout << "�� ������ ����� ��������� �� 8 ����\n";
					cout << "����� ���� �������!";
					TASK = 0;

				}
			}

			clearConsoleAfterDelay(3);
			cout << "���� ��������! �����������!";

		}
	}

}






