# Отчет по лабораторной работе №7 по курсу "Фундаментальная информатика"
___Студент группы:___ М8О-108Б-22 \
___ФИО:___ Сибирцев Роман Денисович \
___Почта:___ sibirtsevr1@gmail.com \
___Преподаватель:___ Сахарин Никита Александрович 

### 1. Тема
 __Нормальные алгоритмы Маркова__

### 2. Цель работы
__Составить алгоритм Маркова для решения задачи__

### 3. Задание
__Входное слово представляет собойпроизвольную последовательность десятичных чисел без знака, разделенных знаками "#". Составить алгоритм вычисления числа слов в последовательности__
### 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___SSD___: 1TB
___Монитор___: 1920:1080

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu Linux, ___версия___ 5.15.0-47-generic
___Интерпритатор команд___ bash, ___версия___ 5.1.16

### 6. Идея, метод, алгоритм решения
Для решения задачи воспользуемся интерпритатором алгоритмов Маркова
- Заменим все знаки "#" на "#?"
- Перенесем все символы "?" напрвво 
- Посчитаем количество символов "?" и прибавим к полученному числу один, отдельно рассмотрим случай, когда количество слов равно одному (т.е. количество символов "#" ровно нулю)

### 7. Сценарий выполнения работы
### Тесты
"*101#12"->"101#12 2"
"*123"->"123 1"
"*12#23#45"->"12#23#45 3"

### Напишем алгоритм Маркова
```
*0->0*
*1->1*
*2->2*
*3->3*
*4->4*
*5->5*
*6->6*
*7->7*
*8->8*
*9->9*

*#->#?*

?0->0?
?1->1?
?2->2?
?3->3?
?4->4?
?5->5?
?6->6?
?7->7?
?8->8?
?9->9?
?#->#?

*?->*-
?*->?(
-?->--

1?->1 *-?
2?->2 *-?
3?->3 *-?
4?->4 *-?
5?->5 *-?
6?->6 *-?
7?->7 *-? 
8?->8 *-? 
9?->9 *-? 



*-->1
1-->2
2-->3
3-->4
4-->5
5-->6
6-->7
7-->8
8-->9
9-->&0
0-->1


0*->0 )
1*->1 )
2*->2 )
3*->3 )
4*->4 )
5*->5 )
6*->6 )
7*->7 )
8*->8 )
9*->9 )
)->1

&->-
 -->*-
*-> 
(-> 
```


### 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 21.10.22 | 13:00 | Выполнение лабораторной работы | - | - |

### 9. Выводы
Были получены принципы написания нормальных алгоритмов Маркова