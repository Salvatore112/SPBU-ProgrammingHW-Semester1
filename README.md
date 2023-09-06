
# Домашние задания и контрольные по программированию. 1-ый семестр.

# Swap

Поменять значения двух целочисленных переменных местами (без привлечения третьей переменной и файлов).

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task1Swap.c)

# Нулевые элементы

Напишите программу, считающую количество нулевых элементов в массиве.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task8.c)

# Неполное частное

Написать алгоритм нахождения неполного частного от деления a на b (целые числа), используя только операции сложения, вычитания и умножения. Убедиться, что программа корректно (в смысле определения неполного частного из википедии) работает на отрицательных значениях и ругается на некорректных. 

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task2.c)

# Счастливые билеты

Подсчитать число «счастливых билетов» из шести цифр, всего существующих в мире (билет считается «счастливым», если сумма первых трёх цифр его номера равна сумме трёх последних). Считать способом, придуманным на паре --- посчитать количество трёхзначных чисел со всеми возможными суммами цифр через массив, возвести в квадрат и сложить

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task4.c)

# Баланс скобок

Написать алгоритм проверки баланса скобок в исходной строке (т.е. число открывающих скобок равно числу закрывающих и выполняется правило вложенности скобок). Скобки бывают только одного типа.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task5.c)

# Простые числа

Напишите программу, печатающую все простые числа, не превосходящие заданного числа.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task7.c)

# Подстрока

Заданы две строки: S и S1 . Найдите количество вхождений S1 в S как подстроки.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework1/task6.c)

# Числа Фибоначчи

Реализовать вычисление чисел Фибоначчи рекурсивно, реализовать итеративно, выяснить, с какого номера числа Фибоначчи рекурсивный вариант заметно медленнее итеративного. 

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework2/Task1)

# Возведение в степень

Реализовать возведение в целую степень — в лоб (за линейное время) и за О(log n).

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework2/Task2)

# Пузырёк и подсчёт

Написать сортировки пузырьком и подсчётом. С помощью функции clock() из time.h сравнить времена их работы на массиве из 100000 элементов. 

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework2/Task3)

# Полукусорт

Написать программу, которая заполняет массив случайными значениями (с использованием функции rand из stdlib.h), потом преобразует его без использования дополнительных массивов так, что в начале массива будут элементы, меньшие первого, а в конце — большие либо равные первому. Программа должна работать за линейное время.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework2/task4.c)

# Умный QSort

Реализовать qsort, который для сортировки кусков массива размером меньше 10 использует сортировку вставкой.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework3/task1.c)

# Поиск
них проверить, содержится ли оно в массиве. Надо придумать алгоритм с временной сложностью O(n log n + k log n), или лучший.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework3/task2.c)

# Самый частый элемент

Найти наиболее часто встречающийся элемент в массиве быстрее, чем за O(n2). Если таких элементов несколько, надо вывести любой из них.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework3/task3.c)

# Двоичное представление

Ввести два числа, перевести в двоичное представление в дополнительном коде и напечатать, сложить в столбик в двоичном представлении, вывести сумму, перевести в десятичное, вывести сумму в десятичном виде. Все сообщения писать по-русски.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework4/task1.c)

# Модули и файлы

Переделать задачу 3 из прошлого задания так, чтобы сортировка была в отдельном модуле и читала входные данные из файла.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework4/Task2)

# Телефонный справочник

Написать программу — телефонный справочник. Она должна уметь хранить имена и номера телефонов, в интерактивном режиме осуществлять следующие операции:

0 - выйти
1 - добавить запись (имя и телефон)
2 - распечатать все имеющиеся записи
3 - найти телефон по имени
4 - найти имя по телефону
5 - сохранить текущие данные в файл
При запуске программа должна читать данные из файла (того самого, в который сохраняет данные), если файла нет — начинать с пустой базы номеров. Размер базы ограничен сотней записей.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework4/Task3)

# к/р 1, задача 1

Посчитать сумму всех чётных чисел Фибоначчи, не превосходящих миллиона. 

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Test/task1.c)

# к/р 1, задача 2

Реализовать сортировку выбором только элементов массива с чётными индексами. Например, массив [5, 4, 3, 2, 1] должен быть отсортирован как [1, 4, 3, 2, 5]. 

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Test/task2.c)

# к/р 1, задача 3

В некоторых языках программирования однострочные комментарии задаются не //, как в С++, а символом ";" (комментарий начинается с ; и заканчивается концом строки). Задача — вывести на консоль все комментарии такого вида из входного файла (вместе с символом ";"). До комментария в строке может быть значимый текст, его выводить не надо. Конец строки представляется символом \n, могут быть полезны функции fgetc и feof.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Test/task3.c)

# Постфиксный калькулятор

Написать программу для вычисления арифметического выражения в постфиксной форме. С клавиатуры вводится последовательность цифр (для простоты) и операций +, -, *, /, представляющая выражение в постфиксной форме, должен выводиться результат вычисления. Например, на тесте 9 6 - 1 2 + * должно получиться 9.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework6/Task1)

# Продвинутый баланс скобок

Продвинутый баланс скобок
Написать программу проверки баланса скобок в строке, скобки могут быть трёх видов: (), [], {}. Скобочная последовательность вида ({)} считается некорректной, ({}) - корректной.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework6/task2.c)

# Сортировочная станция

Написать программу, преобразующую выражение из инфиксной формы в постфиксную. В выражении могут быть знаки +, -, *, /, скобки и цифры. Пример: (1 + 1) * 2 должно преобразовываться в 1 1 + 2 *. Алгоритм перевода предлагается найти самостоятельно (алгоритм "сортировочной станции" Э. Дейкстры).

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework6/task3.c)

# Сортированный список

Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:

0 – выйти
1 – добавить значение в сортированный список
2 – удалить значение из списка
3 – распечатать список
Все операции должны сохранять сортированность. Начинаем с пустого списка.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework7/task1)


# Считалочка

Отряд из 41-го сикария, защищавший галилейскую крепость Массада, не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян. Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего, пока не погибнут все. Самоубийство – тяжкий грех, но тот, кто в конце концов останется последним, должен будет его совершить. Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал, где нужно стать ему и его другу, чтобы остаться последними, но не для того, чтобы убить друг друга, а чтобы сдать крепость римлянам. В нашем случае участвует n воинов и убивают каждого m-го. Требуется определить номер k начальной позиции воина, который должен будет остаться последним. Считать с помощью циклического списка.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework7/main.c)


# Сортировка слиянием

Реализовать сортировку слиянием. Во входном файле последовательность записей "имя — номер телефона". Программа должна отсортировать эти записи либо по имени, либо по номеру телефона, в зависимости от выбора пользователя, и вывести результат на экран. Количество записей заранее неизвестно, так что надо реализовывать списками на указателях.

Особо обращайте внимание на утечки памяти.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework7/task3)

# Дерево поиска

Реализовать АТД "словарь" на основе двоичного дерева поиска, хранящий ключи типа int и связанные с ними значения типа char *. Должны поддерживаться следующие операции:

Добавить значение по заданному ключу в словарь. Если такой ключ уже есть, значение заменяется на новое.
Получить значение по заданному ключу из словаря. Если такого ключа нет, возвращается NULL.
Проверить наличие заданного ключа в словаре.
Удалить заданный ключ и связанное с ним значение из словаря. Если такого ключа нет, функция ничего не делает.
Программа должна работать в интерактивном режиме, то есть пользователю должно предоставляться меню, позволяющее выполнить эти операции. 

Особое внимание уделяйте работе с памятью (рекомендуется использовать отладчик памяти, чтобы проверить, что всё удаляется как надо).

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Homework8/main.c)

# Дерево разбора

По дереву разбора арифметического выражения вычислить его значение. Дерево разбора хранится в файле в виде (<операция> <операнд1> <операнд2>), где <операнд1> и <операнд2> сами могут быть деревьями, либо числами. Например, выражение (1 + 1) * 2 представляется в виде (* (+ 1 1) 2). Должны поддерживаться операции +, -, *, / и целые числа в качестве аргументов. Требуется построить дерево в явном виде, распечатать его (не обязательно так же, как в файле), и посчитать значение выражения обходом дерева.

Может быть полезна функция ungetc (если не '(', возвращаем символ в поток и читаем число fscanf-ом). Можно считать, что входной файл корректен. Пример: по входному файлу (* (+ 1 1) 2) может печататься ( * ( + 1 1 ) 2 ) и выводиться 4.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework8/task2)

# к/р 1.1, задача 1

В массиве целых чисел найти число, сумма цифр которого была бы наибольшей. Если таких чисел несколько, вывести на экран все эти числа. 

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Test1Rewrite/task1.c)


# к/р 1.1, задача 2

Реализовать "Обезьянью сортировку" — сортировку, которая случайно перемешивает массив до тех пор, пока он не окажется отсортирован.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Test1Rewrite/task2.c)


# к/р 1.1, задача 3

Посчитать, сколько раз встречается каждый символ в файле и вывести на экран. Если символ в файле не встречается, его можно не выводить.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/blob/master/Test1Rewrite/task3.c)

# АВЛ-дерево

Реализовать словарь с ключами типа char * и значениями типа char * , на основе АВЛ-дерева. Должны поддерживаться следующие операции.

Добавить значение по заданному ключу в словарь. Если такой ключ уже есть, значение заменяется на новое.
Получить значение по заданному ключу из словаря. Если такого ключа нет, возвращается NULL.
Проверить наличие заданного ключа.
Удалить заданный ключ и связанное с ним значение из словаря. Если такого ключа нет, функция ничего не делает.
Программа должна работать в интерактивном режиме, то есть пользователю должно предоставляться меню, позволяющее выполнить эти операции.

[Решение](https://github.com/Salvatore112/SPBU-ProgrammingHW-Semester1/tree/master/Homework9)



