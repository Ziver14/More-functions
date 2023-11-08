#include<iostream>


int NUM;// глобальная переменная
const double PI = 3.14;//глобальная константа
const int SIZE = 5;
int ARR[SIZE];
void num_inc() {
	NUM++;
}
void func() {	
	static int a = 0;//Статическая переменная, которая не удаляеться призавершении работe программы.
	a++;
		std::cout << a << std::endl;
		if (a % 5 == 0)
			std::cout << "---- \n";
}
inline double absolut(double num) {
	return(num < 0.0 ? -num : num);
}

int power(int num1, int num2=2) {
	int result = 1;
	for (int i = 1; i <= num2; i++)
		result *= num1;
	return result;

}

//Перегруженные функции

int max(int num1, int num2) {
	std::cout << " TWO INTS\n";
	return num1 > num2 ? num1 : num2;
}

double max(double num1, double num2) {
	std::cout << " TWO DOUBELS\n";
	return num1 > num2 ? num1 : num2;
}

char max(char sym1, char sym2) {
	std::cout << " TWO CHARS\n";
	return sym1 > sym2 ? sym1 : sym2;
}

int max(int num1, int num2, int num3) {
	std::cout << "THREE INTS\n";
	return num1 > max(num2, num3) ? num1 : max(num2, num3);
}

//Шаблонная функция


template <typename T>
void print_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	int n;

	//Области видимости данных.
	
	// Все локальные переменные ограничиваються тем блоком и теми фигурными скобочками
	//в рамках которых они были созданы.
	std::cout << NUM << std::endl;
	num_inc();
	std::cout << NUM << std::endl;
	std::cout << "PI = " << PI;

	func();
	func();
	func();

	for (int i = 0; i < 15; i++)
		func();

	//Области применения статичесих элементов
	//1.Сохранение данных из вызова в вызов функции;
	//2.Экономия памяти и времени выполнения.
	//3.Создание общих элементов относящихся к конкретным группам объектов.

	//Параметры по умолчанию.
	std::cout << "5^3 = " << power(5, 3) << std::endl;
	std::cout << "7^2 = " << power(7) << std::endl;
	std::cout << "4^4 = " << power(4, 4) << std::endl;
	std::cout << "11^2 = " << power(11) << std::endl;

	//Встраиваемые,перегруженные и шаблонные функции

	//Встраиваемая функция.
	std::cout << "Введите число -> ";
	std::cin >> n;
	std::cout << '|' << n << " | = " << absolut(n)<<'\n';
	//Функцию не возможно встроить ,если место в котором она вызываеться ,не может содержать в себе код ,описанный в теле функции.

	//Пеерегруженная функция
	std::cout << max(5, 7) << std::endl;
	std::cout << max(1.3, 1.03) << std::endl;
	std::cout << max('k', 'K') << std::endl;
	std::cout << max(5, 7, 4) << std::endl;

	//Шаблонная функция
	const int size = 5;
	int arr[size]{10,2,32,15,5};
	std::cout << " Массив:\n";
	print_arr(arr, size);


	return 0;
}


