/*Команди зчитування даних*/
#define READ_DEC   0x10
#define READ_FLOAT 0x11
#define READ_CHAR  0x12
#define READ_STR   0x13
#define READ_HEX   0x14

/*Команди виведення на консоль*/
#define WRITE_DEC   0x20
#define WRITE_FLOAT 0x21
#define WRITE_CHAR  0x22
#define WRITE_STR   0x23
#define WRITE_HEX   0x24

/*Команди завантаження/вивантаження даних*/
#define LOAD_ACUM   0x30
#define STORE_ACUM  0x31
#define LOAD_FREG   0x32
#define STORE_FREG  0x33
#define PUSH_STACK  0x34
#define POP_STACK   0x35
#define LOAD_CREG   0x36
#define STORE_CREG  0x37

/*Арифметичні операції з акумулятором*/
#define ACUM_ADD   0x40
#define ACUM_SUB   0x41
#define ACUM_DIV   0x42
#define ACUM_MOD   0x43
#define ACUM_MUL   0x44
#define ACUM_SHR   0x45
#define ACUM_SHL   0x46

/*Арифметичні операції з регістром обробки дійсних чисел*/
#define FREG_ADD  0x50
#define FREG_SUB  0x51
#define FREG_DIV  0x52
#define FREG_MUL  0x53

/*Команди передачі керування*/
#define BRANCH       0x60
#define BRANCH_ZERO  0x61
#define BRANCH_NEG   0x62
#define LOOP         0x63
#define HALT         0x64
#define HALT_INFO    0x65
