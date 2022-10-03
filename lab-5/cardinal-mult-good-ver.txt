00, ,<,aa


// перемещаем головку в начало ленты


// CHECK IF FIRST NUM IS ZERO
aa,|,<,aa
aa, ,<,bb
bb,|, ,bb1
bb1, ,<,bb2
bb2, ,>,BACK
BACK, ,|,BACK
BACK,|,>,BACK_ZERO
BACK_ZERO, ,>,BACK_ZERO_2
BACK_ZERO_2,|,>,BACK_ZERO_2
BACK_ZERO_2, ,>,PLACE_ZERO
PLACE_ZERO, ,|,EXIT_ZERO
EXIT_ZERO,|,>,EXIT_ZERO_SUPER
EXIT_ZERO_SUPER, ,#,EXIT_ZERO_SUPER

bb2,|,>,bb3
bb3, ,|,BACK_GOOD              // IS NOT ZERO
BACK_GOOD,|,>,BACK_GOOD_2
BACK_GOOD_2, ,>,BACK_GOOD_3
BACK_GOOD_3,|,>,BACK_GOOD_3
BACK_GOOD_3, ,<,NUM2


NUM2,|, ,NUM2_0_0 // сначала пропускаем второе число
NUM2_0_0, ,<,NUM2_0_1
NUM2_0_1,|, ,NUM2_0

NUM2_0_1, ,>,MULT_ZERO_PRE // ZERO IS THE SECOND NUMBER
MULT_ZERO_PRE, ,|,MULT_ZERO
MULT_ZERO,|,>,MULT_ZERO
MULT_ZERO, ,>,MULT_ZERO_END
MULT_ZERO_END, ,|,MULT_ZERO_SUPEREND
MULT_ZERO_SUPEREND,|,>,MULT_ZERO_SUPEREND_2
MULT_ZERO_SUPEREND_2, ,#,MULT_ZERO_SUPEREND_2

NUM2_0, ,<,NUM2_1
NUM2_1,|,<,NUM2_1
NUM2_1, ,|,NUM1-pre

NUM1-pre,|,<,NUM1-prep
NUM1-prep,|, ,NUM1-prep-prep
NUM1-prep-prep, ,<,NUM1


NUM1,|,<,NUM1 // затем пропускаем первое число
NUM1, ,>,START


// забираем одну | из первого числа


START,|, ,START
START, ,>,go_through_num1

go_through_num1,|,>,go_through_num1
go_through_num1, ,>,copy_num2


// копируем второе число


copy_num2_pre,|,>,copy_num2 // при вставке | после копирования надо переместиться на одну клетку вправо

copy_num2,|, ,skip_num2_2 
skip_num2_2, ,>,skip_num2 // забираем | и переносим её в итоговое число

skip_num2,|,>,skip_num2
skip_num2, ,>,insert_nums

insert_nums, ,|,temp
insert_nums,|,>,insert_nums

temp,|,<,temp
temp, ,<,return_to_num2_pre // вставили |, возвращаемся обратно

return_to_num2_pre, ,|,back_to_num2
return_to_num2_pre,|,<,return_to_num2

return_to_num2,|,<,return_to_num2
return_to_num2, ,|,copy_num2_pre


// возвращаемся к первому числу и делаем ещё одну итерацию


back_to_num2,|,<,back_to_num2
back_to_num2, ,<,pre_back_to_start

pre_back_to_start,|,<,back_to_start
back_to_start,|,<,back_to_start
back_to_start, ,|,START_pre

START_pre,|,>,START


// конец


// если вместо первой | после пробела идёт " ", это значит, что умножение было произведено т.к. программа идёт слева направо 

pre_back_to_start, ,|,END1 // переходим в самую правую ячейку ленты для завершения программы
END1,|,>,END1
END1, ,|,END2_0

END2_0,|,>,END2_1
END2_1,|, ,END2

END2,|,>,END2
END2, ,>,END3

END3,|,>,END3
END3, ,|,END4
END4,|,>,END5_0_0
END5_0_0,|,>,END5_0

END5_0,|, ,END5_1


END5_0, ,>,END_ONE_PRE
END_ONE_PRE, ,|,END_ONE
END_ONE,|,>,END_ONE1
END_ONE1, ,|,SUPEREND


END5_1, ,>,END5

END5,|,>,END5
END5, ,|,SUPEREND_PRE
SUPEREND_PRE,|,>,SUPEREND_PRE2
SUPEREND_PRE2, ,|,SUPEREND_PRE3
SUPEREND_PRE3,|,>,SUPEREND_PRE4
SUPEREND_PRE4, ,|,SUPEREND

SUPEREND,|,>,SUPEREND
SUPEREND, ,#,SUPEREND


