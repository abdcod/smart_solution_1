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

  int counter_of_negative = 0;
  int counter_of_positive = 0;
  int low_negative_buf = 1;
                       
  int have_null = 0;
  int high_negative_buf = 1; 
  int low_nonegative_buf = -1;
  int i = 0;
  int output = 666;

  while (i < count) {
    if (array[i] < 0) {
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
    } else if (array[i] == 0) {
      have_null++;
      counter_of_positive++;
      low_nonegative_buf = array[i];
    } else {
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
