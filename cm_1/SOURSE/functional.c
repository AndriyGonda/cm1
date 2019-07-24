//Memory dump void function//
void print_dump()
  {
   puts("\n                      ***MEMORY DUMP***              ");  
   puts("\n MEMORY: \n");
   
    for(unsigned int i=0;i<8;i++) printf("        %x",i);
     puts("");
     for(unsigned int i=1;i<MEMORY_SIZE+1;i++)
       {
         if(i==1) printf(" 0: ");
         printf("%08x ",memory[i-1]);
         if(i%8==0&&i!=MEMORY_SIZE)
           {
              printf("\n");
              printf("%2x: ",i);
           }
       }
    puts("\n\n REGISTERS: \n");
    printf("Acumulator register:  %04x\n",acumulator);
    printf("Counter register:     %04x\n",count_register);
    printf("Float register:      %+4.04f\n",float_reg);
    printf("Instruction counter:  %04d\n",instruction_counter);
    printf("Instruction register: %04x\n",instruction_register);
    printf("Stack pointer:        %02d\n",stack_pointer);
    printf("Operation code:       %02x\n",operation_code);
    printf("Operand:              %02x\n",operand);
    printf("Stack:                %04x\n",stack[stack_pointer]);
  }

//Enter program void function//
 void input_program()
  {
    printf("               *** Welcome to CM-1. ***\n"
           "Please enter your program on one command or word of data.\n");
    int memory_adress=0x0,operation,div=0xffff;
     while (memory_adress!=0xff&&operation!=-0x99999)
      {
        printf("%02x? ",memory_adress);
        scanf("%x",&operation);
        
        if (operation!=-0x99999&&operation<=0xffff) memory[memory_adress]=operation;
           else 
            if(memory[memory_adress-1]!=0x6500&&memory[memory_adress-1]!=0x6400)
            memory[memory_adress]=0x6500;
        if(operation>=0xffff)
         {  
            while(operation>0xffff)
            {
             operation/=div;
             div*=0xff;
            }
            memory[memory_adress]=operation;
          }
        memory_adress++;
      }
      printf("Data entry completed...\n\n"); 
    }
