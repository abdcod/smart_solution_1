/*
Решение задачи:
Парсим массив. Проходимся по нему. И в процессе вычисляем некоторые данные:

1) Нужен счётчик, который будет считать сколько всего было отрицательных
2) Нужна переменная в которую будет перезаписываться наименьше из всех
отрицательных.
3) Переменная, которая ответит на вопрос, был ли среди
массива ноль.
4) Переменная, в которую будет записываться наибольшее из
отрицательных (то есть ближе к нулю...
5) Переменная, в которую будет
записываться наименьшее из неотрицательных

И потом с помощью полученной информации реализуем вот это:

1. Если отрицательных чисел четное количество (в том числе их количество -
ноль), и при этом есть неотрицательные числа (в том числе возможно нолик) -
отдаем наименьшее из неотрицательных [этот вариант учитывает и те варианты,
когда отрицательных чисел нет, потому что ноль тоже чётное]
2. Если отрицательных четное количество, и при этом неотрицательных нет, отдаем
наименьшее из отрицательных [этот вариант учитывает и те варианты,
когда отрицательных чисел нет, потому что ноль тоже чётное]
3. Если отрицательных нечетное количество, и при этом есть ноль, отдавать любое
неотрицательное
4. Если отрицательных нечетное количество, и при этом нет ноля, но есть другие
неотрицательные, тогда отдавать наибольшее из отрицательных (то есть ближайшее к
нулю)
5. Если отрицательных нечётное количество, и при этом больше нет чисел, отдавать
наибольшее из отрицательных (ближайшее к нулю)
 */

#include <stdio.h>

int main() {
  int count;
  int scanf_counter = 0;
  scanf("%d", &count);
  int array[count];
  while (scanf_counter < count) {
    scanf("%d", &array[scanf_counter]);
    scanf_counter++;
  }
  // на этом моменте мы спарсили массив

  int counter_of_negative = 0;  // счётчик отрицательных чисел
  int counter_of_positive = 0;  // счётчик неотрицательных чисел
  int low_negative_buf = 1;  // наименьшее отрицательное число (наиболее близкое
                             // к минус бесконечности)
  int have_null = 0;         // есть ли ноль в массиве
  int high_negative_buf =
      1;  // наибольшее отрицательно число (наиболее близкое к нулю)
  int low_nonegative_buf = -1;  // наименьшее неотрицательное число
  int i = 0;                    // счётчик ячейки массива
  int output = 666;  // вывод

  while (i < count) {  // побежали по массиву анализировать его
    if (array[i] < 0) {  // если элемент массива - отрицательное число
      counter_of_negative++;
      if (array[i] < low_negative_buf) {
        low_negative_buf = array[i];
      }
      if (high_negative_buf == 1) {
        high_negative_buf = array[i];
      }
      if (array[i] > high_negative_buf) {
        high_negative_buf = array[i];
      }
    } else if (array[i] == 0) {  // если элемент массива - ноль
      have_null++;
      counter_of_positive++;
      low_nonegative_buf = array[i];
    } else {  // если элемент массива - положительное число
      counter_of_positive++;
      if (low_nonegative_buf == -1) {
        low_nonegative_buf = array[i];
      }
      if ((low_nonegative_buf != -1) && (array[i] < low_nonegative_buf)) {
        low_nonegative_buf = array[i];
      }
    }
    i++;
  }

  if (counter_of_negative % 2 == 0 && counter_of_positive != 0) {
    output = low_nonegative_buf;
  }
  if (counter_of_negative % 2 == 0 && counter_of_positive == 0) {
    output = low_negative_buf;
  }
  if (counter_of_negative % 2 != 0 && have_null > 0) {
    output = high_negative_buf;
  }
  if (counter_of_negative % 2 != 0 && have_null == 0 &&
      counter_of_positive > 0) {
    output = high_negative_buf;
  }
  if (counter_of_negative % 2 != 0 && counter_of_positive == 0) {
    output = high_negative_buf;
  }
  printf("%d\n", output);
}
