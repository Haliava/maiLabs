00, ,<,01


// перемещаем головку в начало ленты


01,|,<,01 // сначала пропускаем второе число
01, ,<,02 

02,|,<,02 // затем пропускаем первое число
02, ,>,99


// забираем одну | из первого числа


99,|, ,99
99, ,>,11

11,|,>,11
11, ,>,20


// копируем второе число


29,|,>,20 // при вставке | после копирования надо переместиться на одну клетку вправо

20,|, ,22
22, ,>,21 // забираем | и переносим её в итоговое число

21,|,>,21
21, ,>,50

50, ,|,55
50,|,>,50

55,|,<,55
55, ,<,40 // вставили |, возвращаемся обратно

40, ,|,31
40,|,<,32

32,|,<,32
32, ,|,29


// возвращаемся к первому числу и делаем ещё одну итерацию


31,|,<,31
31, ,<,05

05,|,<,04
04,|,<,04
04, ,|,44

44,|,>,99


// конец


// если вместо первой | после пробела идёт " ", это значит, что умножение было произведено т.к.
// программа идёт слева направо 

05, ,|,91 // переходим в самую правую ячейку ленты для завершения программы
91,|,>,91
91, ,>,92

92,|,>,92
92, ,>,93

93,|,>,93
93, ,#,93



