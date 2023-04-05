# Отчет по лабораторной работе №20 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «5» апреля 2023 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Входной контроль знаний с оценкой:___  \
___Отчет сдан___ «8» апреля 2023 г., ___итоговая оценка:___ 

Подпись преподавателя: ________________ 

## 1. Тема

__Стандартные утилиты UNIX для обработки файлов__

## 2. Цель работы

> 1. _Изучить основные команды обработки текстовых файлов ОС UNIX по литературным источникам, системным электронным мануалам, Wikipedia и т. п. публикациям в сети Интернет. Обратить внимание на некоторые различия в реализациях команд на разных платформах и в разных версиях UNIX._

> 2. _В среде ОС UNIX опробовать указанные ниже утилиты и получить навыки работы с ними. Исследовать возможности применения кириллицы в обрабатываемых файлах. Для генерации тестовых данных в необходимых случаях использовать специально написанные программы._

> 3. _Подготовить нетривиальные текстовые файлы для иллюстрации работы трёх утилит, допускающих неинтерактивный режим. Распределение утилит по студентам производится преподавателем. При выполнении работы рекомендуется использовать простые командные файлы или последовательности команд в командной строке и конвейеры._

> 4. _Запротоколировать подготовленные примеры и иллюстрации работы для не менее, чем 20 «обязательных» утилит пакетного режима с распечаткой используемых текстовых файлов._

## 3. Задание

_Детально изучить утилиты: indent, mktemp, ed._

## 4. Оборудование

___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB

## 5. Программное обеспечение

___Операционная система семейства___ UNIX, ___наименование___ Arch Linux, ___версия___  6.2.2-arch1-1
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano

## 6. Идея, метод, алгоритм решения

_При помощи команд и ключей, приведенных в пункте 7, провести операции над текстовыми файлами и директориями_

## 7. Сценарий выполнения работы

|Команда|Синтаксис|Описание|
|--|--|--|
| `cmp` | cmp [параметры] <первый файл> <второй файл> |Позволяет использовать утилиту для побайтового сравнения двух произвольных файлов |
|`dd`|dd if=<имя исходного файла> of=<имя целевого файла> [параметры]|предназначена для задействования одноименной утилиты, предназначенной для низкоуровневого копирования и преобразования данных|
|`tail`|tail [параметры] <имя файла>|Вывод последней части файла|
|`cut`|cut [параметры] <путь к файлу>|Позволяет вырезать часть строк из указанных файлов или данных по конвейеру|
|`paste`|paste [параметры] <файл1> <файл2>|Объединение строк файлов|
|`cpp`|cpp [праметры] <файл> |Препроцессор языка C|
|`split`|split [параметры] <файл>|Разделяет файл на несколько|
|`tar`|tar [параметры] <файл.tar> <файлы_для_архивации>|Архивирование файлов|
|`od`|od [параметры] <файл>|Преобразование содержимого входных данных в различные форматы с восьмеричным форматом по умолчанию|
|`tee`|tee [параметры] <файл>|Считывание стандартного ввода и записывание его в файл|
|`comm`|comm [параметры] <файл1> <файл2>|Сравнение двух отсортированных файлов построчно|
|`head`|head [параметры] <файл>|Выводит начальные строки (по умолчанию — 10)  из одного или нескольких документов|
|`find`|find [дирретория] [пареметры] (критерий: имя, дата, права)|Поиск файлов и каталогов|
|`df`|df [параметры]|Выводит информацию о занятом месте|
|`touch`|touch <файл>|Создание пустого файла|
|`xargs`|< command1> xargs < command2>|вывод предыдущей команды передается в аргументы следующей|
|`sed`|sed [параметры] <файл>|Потоковый редактор текста|
|`grep`|grep 'string' <файл>|Поиск образца в файле|
|`sort`|sort [параметры] <файл>|Вывод текстовых строк в определенном порядке|
|`uniq`|uniq [параметры] <файл1> <файл2>|Поиск одинаковых строк в массивах текста|

## 8. Распечатка протокола

```bash
[roman@archlinux lab20]$ cat t1.txt 
abcdeee
[roman@archlinux lab20]$ cat t2.txt 
abcd
[roman@archlinux lab20]$ cmp t1.txt t2.txt 
t1.txt t2.txt differ: byte 5, line 1
```

```bash
[roman@archlinux lab20]$ ls
README.md  t1.txt  t2.txt
[roman@archlinux lab20]$ cat t1.txt 
abcdeee
[roman@archlinux lab20]$ dd if=t1.txt of=t3.txt
0+1 records in
0+1 records out
8 bytes copied, 9.407e-05 s, 85.0 kB/s
[roman@archlinux lab20]$ cat t3.txt 
abcdeee

```

```bash
[roman@archlinux lab20]$ cat t1.txt 
abcdeee
ahaahha
aaabbb
abb
[roman@archlinux lab20]$ tail -n 2 t1.txt 
aaabbb
abb
```

```bash
[roman@archlinux lab20]$ cat t2.txt 
abcd
[roman@archlinux lab20]$ cut -c 2 t2.txt 
b
```

```bash
[roman@archlinux lab20]$ cat t2.txt 
abcd
[roman@archlinux lab20]$ cat t3.txt 
abcdeee
[roman@archlinux lab20]$ paste t2.txt t3.txt 
abcd    abcdeee
```

```bash
[roman@archlinux lab20]$ cat t1.txt 
abcdeee
ahaahha
aaabbb
abb
[roman@archlinux lab20]$ split -l 2 t1.txt split_file
[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt
[roman@archlinux lab20]$ cat split_fileaa
abcdeee
ahaahha
[roman@archlinux lab20]$ cat split_fileab
aaabbb
abb
```

```bash
[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt
[roman@archlinux lab20]$ tar -cf t.tar t1.txt t2.txt 
[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt  t.tar
[roman@archlinux lab20]$ tar -tf t.tar t1.txt t2.txt 
t1.txt
t2.txt
```

```bash
[roman@archlinux lab20]$ cat t1.txt 
abcdeee
ahaahha
aaabbb
abb
[roman@archlinux lab20]$ od t1.txt 
0000000 061141 062143 062545 005145 064141 060541 064150 005141
0000020 060541 061141 061142 060412 061142 000012
0000033
```

```bash
[roman@archlinux lab20]$ tee t4.txt
hi
hi
[roman@archlinux lab20]$ cat t4.txt 
hi
```

```bash
[roman@archlinux lab20]$ cat t1.txt 
aab
bbb
cde
dd
[roman@archlinux lab20]$ cat t2.txt 
aaaaaaa
abababa
abbbaaaba
bcdef
[roman@archlinux lab20]$ comm t1.txt t2.txt 
        aaaaaaa
aab
        abababa
        abbbaaaba
bbb
        bcdef
cde
dd
```

```bash
[roman@archlinux lab20]$ cat t1.txt 
aab
bbb
cde
dd
[roman@archlinux lab20]$ head --lines 2 t1.txt 
aab
bbb
```

```bash
[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t.tar
[roman@archlinux lab20]$ find ./ -name '*.txt'
./t1.txt
./t2.txt
```

```bash
[roman@archlinux lab20]$ df
Filesystem     1K-blocks     Used Available Use% Mounted on
dev              8154192        0   8154192   0% /dev
run              8162568     1592   8160976   1% /run
/dev/sda2      976236544 78244404 897361868   9% /
tmpfs            8162568   127312   8035256   2% /dev/shm
tmpfs            8162568     4832   8157736   1% /tmp
/dev/sda1         522204   120012    402192  23% /boot
/dev/sda2      976236544 78244404 897361868   9% /.snapshots
/dev/sda2      976236544 78244404 897361868   9% /var/log
/dev/sda2      976236544 78244404 897361868   9% /var/cache/pacman/pkg
/dev/sda2      976236544 78244404 897361868   9% /home
tmpfs            1632512       88   1632424   1% /run/user/1000
```

```bash
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t.tar
[roman@archlinux lab20]$ touch t3.txt
[roman@archlinux lab20]$ cat t3.txt 
[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt  t.tar
```

```bash
[roman@archlinux lab20]$ cat t4.txt

[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt  t4.txt  t.tar
[roman@archlinux lab20]$ ls | xargs echo > t4.txt 
[roman@archlinux lab20]$ cat t4.txt
README.md split_fileaa split_fileab t1.txt t2.txt t3.txt t4.txt t.tar
```

```bash
[roman@archlinux lab20]$ cat t2.txt 
aaaaaaa
abababa
abbbaaaba
bcdef
[roman@archlinux lab20]$ sed -n '2,4p' t2.txt 
abababa
abbbaaaba
bcdef
```

```bash
[roman@archlinux lab20]$ ls
README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt  t4.txt  t.tar
[roman@archlinux lab20]$ ls | grep t
split_fileaa
split_fileab
t1.txt
t2.txt
t3.txt
t4.txt
t.tar
```

```bash
[roman@archlinux lab20]$ cat t3.txt 
ahahahaha
abbbssdaf
abcdef
yayyaya
aaaaaaa
[roman@archlinux lab20]$ sort t3.txt 
aaaaaaa
abbbssdaf
abcdef
ahahahaha
yayyaya
```

```bash
[roman@archlinux lab20]$ cat t5.txt 
hello
hello
ghghg
ghghg
sdssd
fdgdy
sdssd
[roman@archlinux lab20]$ uniq t5.txt 
hello
ghghg
sdssd
fdgdy
sdssd
```

|Команда|Синтаксис|Описание|
|--|--|--|
|`indent`|indent file [-o outfile ] [ options ] | Измените внешний вид программы C/C++, вставив или удалив пробелы. |
|`mktemp`|mktemp [OPTION]... [TEMPLATE]|Создание временных фалов и директорий|
|`ed`|ed [options] [file]|Строчный текстовый редактор|

```bash
[roman@archlinux lab20]$ cat program.c 
#include <stdio.h>

int main(void){
    int a=12,s=0;
    for (int i=0;i<a;++i){
printf("%d\n", i);
s+=i;
    }
printf("%d",s);
}
[roman@archlinux lab20]$ indent --linux-style program.c 
[roman@archlinux lab20]$ cat program.c
#include <stdio.h>

int main(void)
{
        int a = 12, s = 0;
        for (int i = 0; i < a; ++i) {
                printf("%d\n", i);
                s += i;
        }
        printf("%d", s);
}
[roman@archlinux lab20]$ indent program.c  -nbad -nbap -bc -br -c33 -cd33 -cdb -ce -ci4 -cli0 -di16 -fc1 -i4
[roman@archlinux lab20]$ cat program.c
#include <stdio.h>

int
main (void)
{
    int             a = 12,
        s = 0;
    for (int i = 0; i < a; ++i) {
        printf ("%d\n", i);
        s += i;
    }
    printf ("%d", s);
}
```

```bash 
[roman@archlinux lab20]$ mktemp 
/tmp/tmp.1K4QbMqutQ
[roman@archlinux lab20]$ ls  /tmp/tmp.*
/tmp/tmp.1K4QbMqutQ
[roman@archlinux lab20]$ mktemp 
/tmp/tmp.6YS5ldGIrC
[roman@archlinux lab20]$ ls  /tmp/tmp.*
/tmp/tmp.1K4QbMqutQ  /tmp/tmp.6YS5ldGIrC
[roman@archlinux lab20]$ mktemp --suffix=+suff
/tmp/tmp.0dDYyvnH0P+suff
[roman@archlinux lab20]$ ls  /tmp/tmp.*
/tmp/tmp.0dDYyvnH0P+suff  /tmp/tmp.1K4QbMqutQ  /tmp/tmp.6YS5ldGIrC
[roman@archlinux lab20]$ ls
program.c  program.c~  README.md  split_fileaa  split_fileab  t1.txt  t2.txt  t3.txt  t4.txt  t5.txt  t.tar
[roman@archlinux lab20]$ mktemp tempfile_XXXXX.tmp
tempfile_MAmxT.tmp
[roman@archlinux lab20]$ mktemp tempfile_XXXXX.tmp
tempfile_pGpbt.tmp
[roman@archlinux lab20]$ ls
program.c   README.md     split_fileab  t2.txt  t4.txt  tempfile_MAmxT.tmp  t.tar
program.c~  split_fileaa  t1.txt        t3.txt  t5.txt  tempfile_pGpbt.tmp
```

```bash
[roman@archlinux lab20]$ touch file.txt
[roman@archlinux lab20]$ ed file.txt 
0

?

?

?
P
*a
first line
second line
.
*p
second line
*,pn         
1       first line
2       second line
*1
first line
*w file.txt
*q
[roman@archlinux lab20]$ cat file.txt 
first line
second line
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 09.03.23 | 16:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы

Подпись студента _________________