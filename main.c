#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]){
    // Please change the code below, I use command line arguments as input
    // k is the number you want to reverse
    // p is the base which k is in.
    //
    // For example, if k = 15, p = 3
    // The bits of k will be 120
    // and the expected reverse of k is 012
    int k = atoi(argv[1]);
    int p = atoi(argv[2]);

    int bit_array[1000];

    memset(bit_array, 0, sizeof(bit_array));
    
    int count = 1;
    int _k = k;
    while((_k /= p) >= p) ++count; 
    
    _k = k;
    double _pow;
    for(int i = count+1; i >= 0; --i){
        _pow = pow(p, i);
        while((_k - _pow) >= 0){
            _k -= _pow;
            ++bit_array[i];
        }
    }
    printf("k = ");
    for(int i = 0; i <= count; ++i){
        printf("%d", bit_array[i]);
    }
    printf(" in base %d\n", p);
    
    printf("----------The reverse of k is---------- \n");
    printf("j = ");
    for(int i = count; i >= 0; --i){
        printf("%d", bit_array[i]);
    }
    printf(" in base %d\n", p);
}
