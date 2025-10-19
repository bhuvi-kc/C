#include <stdio.h>
#include <math.h>

    float a;
    float b;

            float sum (float a, float b)
            {
                return a+b;
            }

            float difference (float a, float b)
            {
                return a-b;
            } 

            float product (float a, float b)
            {
                return a*b;
            }

            float division (float a, float b)
            {
                return a/b;
            }

            int modulus (int a, int b)
            {
                return a % b;
            }

int main()    //can't put main() or any other inside another main()
{
    int choice;
    
    printf("enter a: ");
    scanf("%f", &a);
    printf("enter b: ");
    scanf("%f", &b);
    while (getchar() != '\n');  // clears leftover newline from buffer   //this line is necessary because when we enter a number and press enter, the newline character remains in the input buffer. so when we use scanf again to take input, it reads the newline character instead of waiting for new input. this line clears the buffer by reading and discarding all characters until a newline is found.  //'\n' is the newline character, which is generated when the user presses the Enter key.

    //while (1)  //infinite loop   //we wrote (1) because 1 is always true, so the loop will run infinitely  //(1) is always true because 1 is a non-zero value.
    while (1)
    {          
        printf("1.addition\n");
        printf("2.subtraction:\n");
        printf("3.product:\n");
        printf("4.quotient\n");
        printf("5.remainder\n");
        printf("enter 0 to exit.\n");

        printf("enter your desired operation's number: ");
               
        if ( scanf("%d", &choice) != 1 )   //here, (1) can be replaced with (true) if we include <stdbool.h> library
        {
            printf("Invalid input. Please enter an integer between the range of 0 to 5 coinciding with your choice.");
            while(getchar() != '\n');   
            continue;  
        }

        if ( choice > 5 || choice < 0 )   //just if instead of else if because if the input is invalid, we want to print the error message and go back to the start of the loop, not check for other conditions.   //acc to chargpt (and what i understood), first if has a continue, so no need to write else if, just if is fine.
        {
            printf("invalid input. Please enter an integer in the range of 0 to 5 coinciding with your choice.");
            continue;
        }

        else if ( choice == 0 )
        {
            printf("program exited seccessfully.");
            break;
        }
        
        switch ( choice )  //switch doesn't work with multiple variables. to make it work for more than one variable, use "choice" with nested switch statements inside it.  //it must be inside the while loop.
        {
        case 1:
        printf("sum:%.2f\n", sum(a,b));
        break;

        case 2:
        printf("diffetence:%.2f\n", difference(a,b));
        break;

        case 3:
        printf("product:%.2f\n", product(a,b));
        break;

        case 4:
    if (b!=0)
    {
        printf("quotient:%.2f\n", division(a,b));
    }
    else
    {
        printf("division isn't allowed if the denominator equals 0.");
    }
    break;   

        case 5:
    if (b != 0)
        printf("remainder: %d\n", modulus((int)a, (int)b));
    else
        printf("modulus not allowed if denominator is 0.\n");
    break;

        }
    }    
    return 0;
}