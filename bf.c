#include <stdio.h>
#include <bf.h>


int skip(int pointer, char str[], int direction)
{
    pointer += direction;
    while (str[pointer] != (direction > 0 ? ']' : '['))
    {
        if (str[pointer] == (direction > 0 ? '[' : ']'))
        {
            pointer = skip(pointer, str, direction);
        }
        pointer += direction;
    }

    return pointer;
};
void inter(char str[])
{
    
    int arr[500] = {0};
    int pointerOfArr = 250;
    int pointerOfStr = 0;
    char ch = '!';
    strncat(str, &ch, 1);
    while (str[pointerOfStr] != '!')
    {
        switch (str[pointerOfStr])
        {
        case '+':
            arr[pointerOfArr]++;
            break;

        case '-':
            arr[pointerOfArr]--;
            break;

        case '.':
            printf("%c", (char)arr[pointerOfArr]);
            break;

        case '<':
            pointerOfArr--;
            break;

        case '>':
            pointerOfArr++;
            break;

        case '[':
            if (!arr[pointerOfArr])
            {
                pointerOfStr = skip(pointerOfStr, str, 1);
            }
            break;

        case ']':
            if (arr[pointerOfArr])
            {
                pointerOfStr = skip(pointerOfStr, str, -1);
            }
            break;
        }
        pointerOfStr++;
    }
}