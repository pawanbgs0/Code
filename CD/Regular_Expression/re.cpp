#include "re.h"

bool one(string input)
{
    bool valid = false;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != 'a')
            return false;
    }

    return true;
}


bool two(string input)
{
    bool valid = false;
    int state = 1;

    for (int i = 0; i < input.size(); i++)
    {
        switch(state)
        {
            case 1:
                if (input[i] == 'b')
                {
                    state = 2;
                }
                else if (input[i] != 'a')
                {
                    return false;
                }
                else 
                    break;

                break;

            case 2:
                if (input[i] != 'b')
                {
                    return false;
                }
                
                break;
        }
    }

    if (state == 2)
        return true;

    else 
        return false;
}

bool three(string input)
{
    int i = 0;

    if (input.size() != 3)
        return false;
    
    if (input[0] == 'a' && input[1] == 'b' && input[2] == 'b')
        return true;
    
    return false;
}