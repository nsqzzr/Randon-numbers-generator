#include <iostream>
#include <time.h>
using namespace std;

void RandomNumber()
{
	cout << "\n====================================================================" << endl;
	cout << "\nСгенерировать случайное число" << endl;
	int number, start, end;
	cout << "\nВведите начало интервала, на котором будет выбираться число: ";
	cin >> start;
	cout << "\nВведите конец интервала, на котором будет выбираться число: ";
	cin >> end;
	if (start <= end)
	{
		number = rand() % end + start;
		cout << "\nСгенерированное число: " << number << "\n\n====================================================================\n" << endl;
	}
	else
	{
		cout << "\n====================================================================\n";
		cout << "\nОшибка: начало интервала меньше, чем конец интервала.\n" << endl;
	}		
}

void RandomArray()
{
	cout << "\n====================================================================" << endl;
	cout << "\nСгенерировать случайный одномерный массив" << endl;
	int number, start, end;
	cout << "\nВведите количество элементов в массиве: ";
	cin >> number;
	cout << "\nВведите начало интервала, на котором будет выбираться число: ";
	cin >> start;
	cout << "\nВведите конец интервала, на котором будет выбираться число: ";
	cin >> end;

	if (start <= end)
	{
		int *array = new int[number];
		for (int i = 0; i < number; i++)
		{
			array[i] = rand() % end + start;
		}
		cout << "\nСгенерированный массив: \n\narray = ";
		for (int i = 0; i < number; i++)
		{
			cout << array[i] << "\t";
		}
		cout << "\n\n====================================================================\n" << endl;
		delete[] array;
		array = nullptr;
	}
	else
	{
		cout << "\n====================================================================\n";
		cout << "\nОшибка: начало интервала меньше, чем конец интервала.\n" << endl;
	}
}

void RandomTwoDimensionalArray()
{
	cout << "\n====================================================================" << endl;
	cout << "\nСгенерировать случайный двумерный массив" << endl;
	int row, col, start, end;
	cout << "\nВведите количество строк в массиве: ";
	cin >> row;
	cout << "\nВведите количество столбцов в массиве: ";
	cin >> col;
	cout << "\nВведите начало интервала, на котором будет выбираться число: ";
	cin >> start;
	cout << "\nВведите конец интервала, на котором будет выбираться число: ";
	cin >> end;

	if (start <= end)
	{
		int **array = new int*[row];

		for (int i = 0; i < row; i++)
		{
			array[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				array[i][j] = rand() % end + start;
			}
		}
		cout << "\nСгенерированный массив: \n\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << array[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "\n====================================================================\n" << endl;
		for (int i = 0; i < row; i++)
		{
			delete[] array[i];
		}
		delete[] array;
		array = nullptr;
	}
	else
	{
		cout << "\n====================================================================\n";
		cout << "\nОшибка: начало интервала меньше, чем конец интервала.\n" << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	cout << "Выберите нужный вариант:\n"<< endl;
	cout << "1) Сгенерировать случайное число\n";
	cout << "2) Сгенерировать случайный одномерный массив\n";
	cout << "3) Сгенерировать случайный двумерый массив\n";
	cout << "\nВведите номер задачи: ";
	int checker;
	cin >> checker;

	switch (checker)
	{
	case 1:
		RandomNumber();
		break;

	case 2:
		RandomArray();
		break;

	case 3:
		RandomTwoDimensionalArray();
		break;

	default:
		cout << "\n====================================================================\n" << endl;
		cout << "Ошибка: вы ввели несуществующее число.\n\n";
		break;
	}
	
	system("Pause");
	return 0;
}