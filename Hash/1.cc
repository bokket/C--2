#include <sys/types.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>
#include <iostream>

using namespace std;
 
int main( void )  
{  
    FILE   *stream;  
    FILE    *wstream;
    char   buf[1024]; 
    
    wstream = fopen( "file_example", "w+"); 

    memset( buf, '/0', sizeof(buf) );
    stream = popen( "cat file_example | grep root", "r" ); 
 
    fread( buf, sizeof(char), sizeof(buf),  stream);  
    fwrite( buf, 1, sizeof(buf), wstream );
    
    pclose( stream );  
    fclose( wstream );
    
    return 0;
}   