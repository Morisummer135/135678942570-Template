#pragma comment(linker, "/STACK:102400000,102400000")  // C++

const long long STACK_SIZE = 10000000 * 5;   // G++  热身赛可以试试
static long long stack[STACK_SIZE], bak;  
 asm __volatile__  
(  
    "movl %%esp, %0\n"  
    "movl %1, %%esp\n":   
    "=g"(bak):  
    "g"(stack + STACK_SIZE - 1):  
);
dfs2(1,0,0);
asm __volatile__  
(  
    "movl %0, %%esp\n" :  
    :  
    "g"(bak)  
);