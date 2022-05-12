#include <mem/mem.h>

/*                                                                                                   
 * memcpy                                                                                            
 * copies num bytes from src to dest                                                                 
 * @param num: number of bytes to copy                                                               
 * @param src: src buffer to copy from                                                               
 * @param dest: destination buffer to copy to                                                        
 */                                                                                                  
void* memcpy(void* dest, const void* src, size_t num) {                                              
    char* d = dest;                                                                                  
    const char* s = src;                                                                             
    for (size_t i = 0; i < num; i++) {                                                               
        d[i] = s[i];                                                                                 
    }                                                                                                

    return dest;
}                                                                                                    
                                                                                                     
/*                                                                                                   
 * memmove                                                                                           
 * moves num bytes from src to dest. Deals with case where dest and src                              
 * addresses partially overlap                                                                       
 * @param num: number of bytes to copy                                                               
 * @param src: src buffer to copy from                                                               
 * @param dest: destination buffer to copy to                                                        
 */                                                                                                  
void* memmove(void* dest, const void* src, size_t num) {                                             
    char* d = dest;                                                                                  
    const char* s = src;                                                                             
    char temp[num];                                                                                  
                                                                                                     
    for (size_t i = 0; i < num; i++) {                                                               
        temp[i] = s[i];                                                                              
    }                                                                                                
                                                                                                     
    for (size_t i = 0; i < num; i++) {                                                               
        d[i] = temp[i];                                                                              
    }

    return dest;                                                                            
}                           

/*                                                                                                   
 * memset
 * sets n bytes of memory in buf to c
 * @param buf: memory buffer                                                               
 * @param c: data to set memory to                                                                
 * @param n: number of bytes to set
 */                                                                                                  
void memset(void* buf, int c, size_t n) {
    char* b = (char*) buf;
    for (size_t i = 0; i < n; i++) {
        b[i] = (char) c;
    }
}


/*                                                                                                   
 * strcpy                                                                                            
 * copies string from src to dest                                                                    
 * @param src: src buffer to copy from                                                               
 * @param dest: destination buffer to copy to                                                        
 */                                                                                                  
char* strcpy(char* dest, const char* src) {                                                          
    int i = 0;                                                                                       
    while (src[i] != '\0') {                                                                         
        dest[i] = src[i];                                                                            
        i++;                                                                                         
    }
    dest[i] = '\0';

    return dest;
}

/*
 * strlen
 * gives length of string src
 * @param src: string to find length of 
 */
size_t strlen(const char* src) {
    size_t len = 0;
    while (src[len] != '\0') {
        len++;
    }
    return len;
}