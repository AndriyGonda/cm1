/*Архітектура віртуальної машини*/
#define MEMORY_SIZE 256
int memory[MEMORY_SIZE]={0}; //Оперативна пам’ять
int acumulator=0;            //Акумулятор
int count_register=0;        //Регістр циклу  з параметром
float float_reg=0;           //регістр обробки чисел з плаваючою точкою
char keybuf[64]={0};         //буфер потоку введення/виведення
int instruction_counter=0;   //лічильник команд
int instruction_register=0;  //виконувана команда
int operation_code=0;        //код операції
int operand=0;               //операнд операції
int stack[64];               //стек
int stack_pointer=0;         // вказівник стеку


