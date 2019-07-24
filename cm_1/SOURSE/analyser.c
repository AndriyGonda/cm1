void float_in_int(float,int*,int*);
void read_char();
void read_str();
void write_str();
void load_freg(int,int);
float int_to_float(const int, const int);

/*interpreter of machine command*/
void exec_comand()
 {
   float buf;
   printf("*** Program started... ***\n\n");
  while(instruction_counter!=0xff&&operation_code!=HALT&&operation_code!=HALT_INFO)
     {
       instruction_register=memory[instruction_counter];
       operation_code=instruction_register/256;
       operand=instruction_register%256;
      switch (operation_code) 
       {
         case READ_DEC: 
                 scanf("%d",&memory[operand]);
                 break;
                 
         case WRITE_DEC:
               printf("%d",memory[operand]); 
                 break;
                 
         case READ_FLOAT:
                   
                 scanf("%f",&buf);
                 float_in_int(buf,&memory[operand],&memory[operand+1]);
                 break;
                 
         case  WRITE_FLOAT: 
                  printf("%.4f",int_to_float(memory[operand],memory[operand+1]));
                 break;
                 
         case READ_CHAR: 
                 read_char();
                 break;
         
         case WRITE_CHAR:
               printf("%c",memory[operand]);
              break;   
         
         case READ_STR: 
              read_str();
              break;
          
         case WRITE_STR:
               write_str();
              break;
              
         case READ_HEX: 
              scanf("%x",&memory[operand]);
              break;
              
         case WRITE_HEX:
              printf("%x",memory[operand]);
              break;
              
         case LOAD_ACUM: 
              acumulator=memory[operand];
              break;
              
         case STORE_ACUM:
              memory[operand]=acumulator;
              break;
          
         case LOAD_CREG:
               count_register=memory[operand];
              break;
          
         case STORE_CREG:
               memory[operand]=count_register;
              break;
              
         case LOAD_FREG:
               load_freg(memory[operand],memory[operand+1]);
              break;
              
         case  STORE_FREG:
                float_in_int(float_reg,&memory[operand],&memory[operand+1]);  
              break;
              
         case PUSH_STACK:
             if((stack_pointer+1)>64) 
                { 
                  printf("Fatal error! Stack overflow!\n");
                  operation_code=HALT_INFO;
                  print_dump();
                  }
               stack_pointer++;
               stack[stack_pointer]=memory[operand];
              break;
              
         case POP_STACK:
               memory[operand]=stack[stack_pointer];
               stack_pointer--;
              break;
         case ACUM_ADD:
              acumulator+=memory[operand];
              break; 
        
        case ACUM_SUB:
              acumulator-=memory[operand];
              break;
          
        case ACUM_MUL: 
               acumulator*=memory[operand];
              break;
        case ACUM_DIV: 
              if (memory[operand]!=0) acumulator/=memory[operand];
              else
               {
                 printf("Fatal error! Divide on zero!\n");
                 operation_code=HALT_INFO;
                 print_dump();
               }
               break;
            
         case ACUM_MOD:
              acumulator%=memory[operand];
              break;
        
         case ACUM_SHR:
              acumulator>>=memory[operand];
               break;
        
         case ACUM_SHL:
               acumulator<<=memory[operand];
               break;
               
         case FREG_ADD:
               float_reg+=int_to_float(memory[operand],memory[operand+1]);
               break;
         
         case FREG_SUB:
               float_reg-=int_to_float(memory[operand],memory[operand+1]);
               break;
               
         case FREG_MUL:
               float_reg*=int_to_float(memory[operand],memory[operand+1]);
               break;
         
         case FREG_DIV:
              if(int_to_float(memory[operand],memory[operand+1])!=0)
                float_reg/=int_to_float(memory[operand],memory[operand+1]);
                else
                 {
                   printf("Error! Divide on zero!");
                   operation_code=HALT_INFO;
                   print_dump();
                 }
              break;
         
         case BRANCH:
              instruction_counter=operand;
              break;
              
        case  BRANCH_NEG:
            if(acumulator<0)  instruction_counter=operand;
              break;
        
        case BRANCH_ZERO:
             if(acumulator==0) instruction_counter=operand;
              break;
        
        case LOOP:
             count_register--;
            if(count_register!=0) instruction_counter=operand;
            
              break;
         case HALT: operation_code=HALT; break;
         case HALT_INFO: print_dump(); break;
       }
       instruction_counter++;
     }
   printf("\n\n*** Program exited. ***\n\n");
 }

//float_in_int void function
 void float_in_int(const float num,int *integer, int *mantissa)
   {
     float number;
     number=num;
     float osn=10.0,mntss;
     *integer=(int) number;
     mntss=modff(num,&osn);
     while(modff(mntss,&osn)!=0)
       {
         mntss*=(float) 10;
       }
       *mantissa=mntss;
     }
     
//char read void//
 void read_char()
   {
      scanf("%s",keybuf);
      memory[operand]=keybuf[0];
     }
//read string void//     
void read_str()
   {
     printf("> ");
     scanf("%s",keybuf);
     for(unsigned int i=0; i<64; i++)
      memory[operand+i]=keybuf[i];
      for(unsigned int i=0; i<64; i++) 
        keybuf[i]=0;
     }

void write_str()
  {  
    unsigned int i=0;
    while(memory[operand+i])
     {
     printf("%c",memory[operand+i]);
     i++;
     }   
    }

void load_freg(int integer,int mantissa)
 {
   float mntss=mantissa;
   while(mntss>1||mntss<-1)
    {
      mntss/=10;
    }
    float_reg=integer+mntss;
 }

float int_to_float(const int integer,const int mantissa)
 {
    int num=integer;
    float mntss=mantissa;
    while(mntss>1||mntss<-1)
     {
       mntss/=(float) 10;
     }
  return num+mntss;
   }
