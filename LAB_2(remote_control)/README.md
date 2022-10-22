# Отчет по лабораторной работе №2 по курсу "Фундаментальная информатика"
___Студент группы:___ М8О-108Б-22 \
___ФИО:___ Сибирцев Роман Денисович \
___Почта:___ sibirtsevr1@gmail.com \
___Преподаватель:___ Сахарин Никита Александрович 

### 1. Тема
__Сети и телекоммуникации в ОС__

### 2. Цель работы
__Изучение сетевых команд ОС UNIX__

### 3. Задание
__Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 3600 (12) @ 3.600GHz \
___ОП___: 15944MiB \
___HDD___: 1TB

### 5. Программное обеспечение
#### Устройство 1
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu Linux, ___версия___  Ubuntu 20.04 LTS
___Имя пользователя и устройства___ stud@it-10


#### Устройство 2
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu Linux, ___версия___  Ubuntu 20.04 LTS
___Имя пользователя и устройства___ stud@it-20
### 6. Идея, метод, алгоритм решения
 
* Собственноручно проделать основные примеры и продемонстрировать владение сетевыми средствами 

* Запротоколировать содержательное подмножество сеанса

### 7. Сценарий выполнения работы
#### Используемые команды

    ssh
_криптографический сетевой протокол, используемый для зашифрованного соединения между клиентом и сервером_

    logout
_завершение сеанса подключения_

    scp
_копирование файлов или директорий_

    tar
_ утилита для работы с архивами_   

### 8. Распечатка протокола

```
ssh ....
ls
cat > t.txt
ls
scp 
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
### 9. Выводы
Были изучены сетевые команды ОС UNIX
