#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define SYS_CALL_S2_ENCRYPT 548

long s2_encrypt_sys_call(char* data, int key)
{
    
    return syscall(SYS_CALL_S2_ENCRYPT,data,key);
}



int main (int argc, char* argv[])
{
    long status = -1;
    int option;
    char* str;
    int key ;

    while((option = getopt(argc, argv, ":s:k:lrx")) != -1)
    {
        switch(option)
        {
            case 's':
                str = strdup(optarg);
               
                break;
            case 'k':
                key = atoi(strdup(optarg));
               
                break;
        }
    }

    
    status = s2_encrypt_sys_call(str, key);
    printf("STATUS: %ld\n", status);        
    return 0;
    
}
