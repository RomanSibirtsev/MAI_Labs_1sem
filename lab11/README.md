# Отчет по лабораторной работе №11 по курсу "Фундаментальная информатика"
___Студент группы:___ М8О-108Б-22 \
___ФИО:___ Сибирцев Роман Денисович \
___Почта:___ sibirtsevr1@gmail.com \
___Преподаватель:___ Сахарин Никита Александрович 

### 1. Тема

Обработка последовательности литер входного текстового файла. Простейшие приемы лексического анализа. Диаграммы состояний и переходов.
### 2. Цель работы

Составить программу на языке Си, выполняющую анализ и обработку вводимого текста в соответствии с выданным преподавателем вариантом задания.

### 3. Задание

Подсчитать количество слов, которые являются числами в римской системе счисления

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___SSD___: 1TB
___Монитор___: 1920:1080

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu Linux, ___версия___ 5.15.0-47-generic
___Интерпритатор команд___ bash, ___версия___ 5.1.16

### 6. Идея, метод, алгоритм решения
Считываем файл посимвольно, как только встречается слово начинающееся с римской цифры, начинается проверка на соблюдение всех правил записи римских чисел и проверка на отсутствие лишних символов в слове.

### 7. Сценарий выполнения работы

#### Тесты

##### Тест 1
```
#$%^&()&%^&()_() MMI%
MMMMMMMMMMM
DMDMDMD
III
MMMCMXCIX
MMMCMLXXXIX
MMMDCCXCIX
MMMDCCCXCIX
MMMDCCCXCIXX
4554656XCIXX
```
##### Ответ: 5

##### Тест 2
```
CCCLXXXIX
CMLXXI
CMLLXXI
CMMLXXII
```
##### Ответ: 2

#### Програма
```
#include <stdio.h>

enum State {
    TRUE,
    FALSE
};

int main(void){

  char alf[] = "IVXLCDM";
  int oldest_id = -1, old_id = -1, id = -1, k = 1, old_k = 0;
  int check_num = 1, res = 0, eow = 0, n = 0, slovo = 1;
  int n_V = 0, n_L = 0, n_D = 0;

  enum State check = FALSE;

  for (char ch = getchar(); ch != EOF; ch = getchar())
  {

    if ((ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n'))
    {
      eow = 1;
    }
    else
      eow = 0;
      
    oldest_id = old_id;
    old_id = id;
    check = FALSE;

    for (int i =  0; i < sizeof(alf)/sizeof(alf[0]); i++)
    {
      if (alf[i] == ch)
      {
        check = TRUE;
        id = i;
      }
    }


    switch (check)
    {
    case TRUE:
        if (ch == 'V')
        n_V++;
        if (ch == 'L')
            n_L++;
        if (ch == 'D')
            n_D++;

        n++;

        if (old_id == id)
            k++;
        else
        {
            old_k = k;
            k = 1;
        }

        if (k > 3) // IIII XXXX VVVV
        {
            check_num = 0;
        }

        else if ((k > 1) && ((id == 1) || (id == 3) || (id == 5))) // VV LL DD VVV LLL ...
        {
            check_num = 0;
        }

        else if ((old_k > 1) && (old_id < id)) // IIV VVX IIX ...
        {
            check_num = 0;
        }

        else if ((oldest_id == id) && (oldest_id != -1) && (oldest_id < old_id)) // IXI VXV ...
        {
            check_num = 0;
        }

        else if ((oldest_id < old_id) && (old_id <= id) && (oldest_id != -1) && (old_id != -1)) // CMM IXX
        {
            check_num = 0;
        }


        break;
    
    case FALSE:
        if (((ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n')) && (eow = 1) && (n > 0) && (slovo == 1))
        {
            res += check_num;
        }
        slovo = 0;
        n = 0;
        check_num = 1;
        oldest_id = -1;
        old_id = -1;
        id = -1;
        k = 1;
        n_V = 0;
        n_D = 0;
        n_L = 0;
        break;
    }

    if ((ch == ' ') || (ch == ',') || (ch == '\t') || (ch == '\n'))
      slovo = 1;
  }

  printf("res = %d\n", res);
  return 0;

}
```
### 8. Распечатка протокола

```
#$%^&()&%^&()_() MMI%
MMMMMMMMMMM
DMDMDMD
III
MMMCMXCIX
MMMCMLXXXIX
MMMDCCXCIX
MMMDCCCXCIX
MMMDCCCXCIXX
4554656XCIXX
res = 5

CCLXXXIX
CMLXXI
CMLLXXI
CMMLXXII
res = 2
```

### 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 21.10.22 | 13:00 | Выполнение лабораторной работы | - | - |

### 10. Замечания автора по существу работы 
-
### 11. Выводы
Были получены навыки написания программ на Си, для анализа и обработки вводимого текста.