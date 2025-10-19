#include <stdio.h>

int fibbonacci (int n)

{
    if (n==0)
    {
        return 0;
    }
    
    else if (n==1)
    {
        return 1;
    }

    else
    {
        return fibbonacci(n-1) + fibbonacci(n-2);
    }
}

int main()

{
    int n, i;
    printf("number of terms= ");
    scanf("%d", &n);

    printf("fibbonacci sequence: ");
   
    for (i=0; i<n; i++)   //don't put a semicolon after for loop, it'll consider the next line as garbage and the loop will run infinitely         //instead put semi colon between the conditions inside the brackets
    {
        printf("%d ", fibbonacci(i));
    }

 return 0;
}