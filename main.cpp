#include <iostream>
// задание "Реализовать функцию удаления элемента из динамического массива"
// в фунцию передаём ссылку на указатель на массив, чтобы обновить массив в функции; ссылка на размер массива, чтобы изменить его после удаления элемента;
void del_element(int*& mas, int& n, int ind) {
    int *mas2;
    int i, j;
    j = 0;
    mas2 = new int[n - 1]; // создаём массив меньшего размера

    for (i=0; i < n; ++i) {
        if (i != ind - 1) { // проверка на удаляемый элемент
            mas2[j] = mas[i];
            j++;
        }
    }
    delete [] mas; // удаляем старый массив
    mas = mas2; // указываем ссылку на новый
    n--; // уменьшаем размер
}

int main() {
    int *mas;
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    mas = new int[n]; // создаём первый массив
    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 100; // наполняем случайными числами от 0, до 99
        std::cout << mas[i] << " "; // выводим первый массив
    }
    std::cout << std::endl;

    std::cout << "Enter item number: ";
    int ind;
    std::cin >> ind;

    del_element(mas, n, ind); // вызываем функцию

    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " "; // выводим обновленный массив
    }

    return 0;
}
