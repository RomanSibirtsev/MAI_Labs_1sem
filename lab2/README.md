# Отчет по лабораторной работе №1 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «24» сентября 2022 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Входной контроль знаний с оценкой:___ 5 (отлично) \
___Отчет сдан___ «24» сентября 2022 г., ___итоговая оценка___ 5 (отлично)

Подпись преподавателя: ________________ 

## 1. Тема
_Операционная среда ОС UNIX_
## 2. Цель работы
_Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX_
## 3. Задание
_Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX_
## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB
## 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Manjaro Linux, ___версия___  5.15.65-1-MANJARO
___Интерпритатор команд___ bash, ___версия___ 5.1.16
___Редактор текстов___ nano
## 6. Идея, метод, алгоритм решения
_Для достижения поставленной цели используем основные команды bash для работы с каталогами, текстовыми файлами, тектовыми редакторами и некоторыми утилитами._
## 7. Сценарий выполнения работы
### Используемые команды
    date
_выводит текущее время_

    who
_выводит информацию о пользователях, которые подключены к системе, в том числе и об терминальных сессиях, через которые происходит подключение_

    pwd 

_выводит полный путь текущего рабочего каталога_

    ls 
_выводит содержимое каталогов и информацию о файлах_

    cd
_используется для изменения текущего рабочего каталога_

    cp
_используется для копирования файлов и каталогов_

    mv
_применяется для перемещения и переименования файлов и каталогов_
    
    mkdir
_используемая для создания каталога_

    rmdir
_используется для удаления каталогов из файловой системы. Можно заменить на команду rm с флагом -r_

    rm
_используется для удаления файлов и целых деревьев каталогов_

    man
_используется для просмотра справочных руководств системы_

    cat
_используется для отображения текстовых файлов, копирования текстовых файлов в новый документ, присоединения содержимого текстового файла в конце другого текстового файла для их объединения._

    nano
_текстовый редактор_

#### Скрипт для создания протокола
```
#!/bin/bash
echo "Hi $(whoami)"
echo "Time is now: $(date)"
echo "You are in the folder: $(pwd)"
echo  "There are folder here: $(ls -l)"
```


## 8. Распечатка протокола

```bash
[roman@admin ~]$ date 
Fri Sep 23 13:00:13 PM GMT 2022
(base) [roman@admin ~]$ who
roman    tty1         2022-09-23 13:56 (:0)
roman    pts/0        2022-09-23 13:56 (:0)
roman    pts/1        2022-09-23 13:50 (:0)
roman    pts/2        2022-09-23 13:58 (:0)
[roman@admin ~]$ whoami
roman
[roman@admin ~]$ pwd
/home/roman
[roman@admin ~]$ ls -l
total 4
drwxr-xr-x 1 roman roman  436 Sep 14 21:01 anaconda3
drwxr-xr-x 1 roman roman   70 Sep 14 22:21 Desktop
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Documents
drwxr-xr-x 1 roman roman 2098 Sep 14 23:52 Downloads
drwxr-xr-x 1 roman roman   32 Sep  2 22:59 Games
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Music
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Pictures
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Public
-rwxr-xr-x 1 roman roman  138 Sep 16 23:02 script.sh
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Templates
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Videos
[roman@admin ~]$ cd Documents/
[roman@admin Documents]$ ls
[roman@admin Documents]$ cd ..
[roman@admin ~]$ ls
anaconda3  Documents  Games  Public   script.sh  Templates
Desktop    Downloads  Music  Pictures Videos
[roman@admin ~]$ nano text1.txt
[roman@admin ~]$ cat text1.txt 
Hello world!!!
[roman@admin ~]$ cp text1.txt Documents/text2.txt
[roman@admin ~]$ cd Documents/
[roman@admin Documents]$ ls
text2.txt
[roman@admin Documents]$ cat text2.txt 
Hello world!!!
[roman@admin Documents]$ rm text2.txt 
[roman@admin Documents]$ ls
[roman@admin Documents]$ cd ..
[roman@admin ~]$ mkdir Dir1/
[roman@admin ~]$ ls
anaconda3  Dir1       Downloads  Music   Pictures  text1.txt
Desktop    Documents  Games      Public  script.sh Templates  Videos
[roman@admin ~]$ cd Dir1/
[roman@admin Dir1]$ ls
[roman@admin Dir1]$ cd ..
[roman@admin ~]$ rm -r Dir1/
[roman@admin ~]$ ls
anaconda3  Documents  Games  Public   script.sh  Templates  Videos
Desktop    Downloads  Music  Pictures  pybox2d   text1.txt
```

___Запуск скрипта:___

```bash
[roman@admin ~]$ ./script.sh 
Hi roman
Fri Sep 23 13:00:13 PM GMT 2022
You are in the folder: /home/roman
There are folder here: total 4
drwxr-xr-x 1 roman roman  436 Sep 14 21:01 anaconda3
drwxr-xr-x 1 roman roman   70 Sep 14 22:21 Desktop
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Documents
drwxr-xr-x 1 roman roman 2098 Sep 14 23:52 Downloads
drwxr-xr-x 1 roman roman   32 Sep  2 22:59 Games
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Music
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Pictures
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Public
-rwxr-xr-x 1 roman roman  138 Sep 16 23:02 script.sh
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Templates
drwxr-xr-x 1 roman roman    0 Sep 19 23:01 Videos
```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 24.09.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита была проведена без замечаний.

## 11. Выводы
Была написана программа на языке на Си, выполняющая анализ и обработку текста. В результате выполнения работы, были приобретены навыки для работы с текстовыми входными данными и машинами состояний.


