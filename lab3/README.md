# Отчет по лабораторной работе №3 по курсу "Фундаментальная информатика"

___Студент группы:___ М80-108Б-22 Сибирцев Роман Денисович \
___Контакты e-mail:___ sibirtsevr1@gmail.com \
___Работа выполнена:___ «1» октября 2022 г. \
___Преподаватель:___ асп. каф. 806 Сахарин Никита Александрович \
___Входной контроль знаний с оценкой:___ 5 (отлично) \
___Отчет сдан___ «1» октября 2022 г., ___итоговая оценка___ 5 (отлично)

Подпись преподавателя: ________________ 

## 1. Тема
_Сети и телекоммуникации в ОС UNIX_

## 2. Цель работы
_Изучение и освоение удалённых команд UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX_

## 3. Задание
_Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX_

## 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB

## 5. Программное обеспечение
### Устройство 1
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu Linux, ___версия___  Ubuntu 20.04 LTS
___Имя пользователя и устройства___ stud@it-10


### Устройство 2
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu Linux, ___версия___  Ubuntu 20.04 LTS
___Имя пользователя и устройства___ stud@it-20
## 6. Идея, метод, алгоритм решения
 
* Собственноручно проделать основные примеры и продемонстрировать владение сетевыми средствами 

* Запротоколировать содержательное подмножество сеанса

## 7. Сценарий выполнения работы
### Используемые команды

    ssh
_криптографический сетевой протокол, используемый для зашифрованного соединения между клиентом и сервером_

    logout
_завершение сеанса подключения_

    scp
_копирование файлов или директорий_

    tar
_утилита для работы с архивами_   

## 8. Распечатка протокола

```bash
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:30:42 2022 from 192.168.2.140
stud@it-20:~$ ls
106B_11        767        Downloads      hello.txt  Pictures  Templates  Videos
192.168.2.140  Desktop    _file.txt      lll.gz     Public    test
4444.txt       Documents  file.txt.save  Music      snap      test1
stud@it-20:~$ cat > testssh.txt
hello
123456
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Pictures   test
192.168.2.140  Documents  hello.txt      Public     test1
4444.txt       Downloads  lll.gz         snap       testssh.txt
767            _file.txt  Music          Templates  Videos
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ ls
1          Downloads     file.txt   homestud  Public     test1
4444.txt   f5            fl.gz      Kochev    snap       Untitled.ipynb
and        file2345.txt  gnuplot    misha     spasibo    Videos
Desktop    filesh_zh     hello      Music     Templates  zh_hz.gz
Documents  _file.txt     hello.txt  Pictures  test
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:42:33 2022 from 192.168.2.140
stud@it-20:~$ scp testssh.txt stud@192.168.2.140:./
stud@192.168.2.140's password: 
testssh.txt                                   100%   12    13.2KB/s   00:00    
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ ls
1          Downloads     file.txt   homestud  Public     test1
4444.txt   f5            fl.gz      Kochev    snap       testssh.txt
and        file2345.txt  gnuplot    misha     spasibo    Untitled.ipynb
Desktop    filesh_zh     hello      Music     Templates  Videos
Documents  _file.txt     hello.txt  Pictures  test       zh_hz.gz
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:43:04 2022 from 192.168.2.140
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Pictures   test
192.168.2.140  Documents  hello.txt      Public     test1
4444.txt       Downloads  lll.gz         snap       testssh.txt
767            _file.txt  Music          Templates  Videos
stud@it-20:~$ ls ./Desktop/
f1.txt  ppy.py
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ scp -r stud@192.168.2.224:./Desktop ./
stud@192.168.2.224's password: 
f1.txt                                        100%    4     7.4KB/s   00:00    
ppy.py                                        100%   54   219.8KB/s   00:00    
stud@it-10:~$ ls
1          Downloads     file.txt   homestud  Public     test1
4444.txt   f5            fl.gz      Kochev    snap       testssh.txt
and        file2345.txt  gnuplot    misha     spasibo    Untitled.ipynb
Desktop    filesh_zh     hello      Music     Templates  Videos
Documents  _file.txt     hello.txt  Pictures  test       zh_hz.gz
stud@it-10:~$ ls ./Desktop/
f1.txt  ppy.py
stud@it-10:~$ ssh stud@192.168.2.224
stud@192.168.2.224's password: 
Welcome to Ubuntu 22.04.1 LTS (GNU/Linux 5.15.0-48-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

81 updates can be applied immediately.
To see these additional updates run: apt list --upgradable

Last login: Sat Oct  1 10:47:06 2022 from 192.168.2.140
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Pictures   test
192.168.2.140  Documents  hello.txt      Public     test1
4444.txt       Downloads  lll.gz         snap       testssh.txt
767            _file.txt  Music          Templates  Videos
stud@it-20:~$ mkdir midir
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Music     Templates    Videos
192.168.2.140  Documents  hello.txt      Pictures  test
4444.txt       Downloads  lll.gz         Public    test1
767            _file.txt  midir          snap      testssh.txt
stud@it-20:~$ cd midir/
stud@it-20:~/midir$ cat > file1.txt
1233456
stud@it-20:~/midir$ cat > file2.txt
7891011
stud@it-20:~/midir$ cd ..
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  Music     Templates    Videos
192.168.2.140  Documents  hello.txt      Pictures  test
4444.txt       Downloads  lll.gz         Public    test1
767            _file.txt  midir          snap      testssh.txt
stud@it-20:~$ tar -cf miarh.tar midir/
stud@it-20:~$ ls
106B_11        Desktop    file.txt.save  midir     snap       testssh.txt
192.168.2.140  Documents  hello.txt      Music     Templates  Videos
4444.txt       Downloads  lll.gz         Pictures  test
767            _file.txt  miarh.tar      Public    test1
stud@it-20:~$ logout
Connection to 192.168.2.224 closed.
stud@it-10:~$ scp -r stud@192.168.2.224:./miarh.tar ./
stud@192.168.2.224's password: 
miarh.tar                                     100%   10KB 267.1KB/s   00:00    
stud@it-10:~$ ls
1          Downloads     fl.gz      miarh.tar  spasibo         Videos
4444.txt   f5            gnuplot    misha      Templates       zh_hz.gz
and        file2345.txt  hello      Music      test
arh.tar    filesh_zh     hello.txt  Pictures   test1
Desktop    _file.txt     homestud   Public     testssh.txt
Documents  file.txt      Kochev     snap       Untitled.ipynb
stud@it-10:~$ tar -xf miarh.tar 
stud@it-10:~$ ls
1          Downloads     fl.gz      miarh.tar  snap         Untitled.ipynb
4444.txt   f5            gnuplot    midir      spasibo      Videos
and        file2345.txt  hello      misha      Templates    zh_hz.gz
arh.tar    filesh_zh     hello.txt  Music      test
Desktop    _file.txt     homestud   Pictures   test1
Documents  file.txt      Kochev     Public     testssh.txt
stud@it-10:~$ cd midir/
stud@it-10:~/midir$ ls
file1.txt  file2.txt
stud@it-10:~/midir$ cat file1.txt 
1233456
stud@it-10:~/midir$ cat file2.txt 
7891011
stud@it-10:~/midir$ 
stud@it-10:~/midir$ cd ..
stud@it-10:~$ 

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 01.10.22 | 13:00 | Выполнение лабораторной работы | - | - |

## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита была проведена без замечаний.

## 11. Выводы
Было выяснено, что в OC UNIX есть возможность удалённого подключения к другим машинам. Были освоены команды, необходимые для установления соединения и удалённых манипуляций с файлами. В результате выполнения лабораторной работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Подпись студента _________________