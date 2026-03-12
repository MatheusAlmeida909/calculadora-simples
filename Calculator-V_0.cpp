#include <iostream>

double getNumber()
{
    double number;

    std::cout << "Type a number: ";
    std::cin >> number;

    return number;
}

int main()
{
    constexpr int last_operation{ 5 };
    constexpr int first_operation{ 1 };

    int operation;

    do
    {
        std::cout << "Choose an operation\n ~ 1 = add\n ~ 2 = subtract\n ~ 3 = multiply\n ~ 4 = divide\n ~ 5 = power" << std::endl;
        std::cin >> operation;

        if (operation > last_operation || operation < first_operation)
        {
            std::cout << "This number doesn't correspond to a valid operation" << std::endl;
        }

    } while (operation > last_operation || operation < first_operation);

    double num1{ getNumber() };
    double num2{ getNumber() };
    double result{ 0 };

    switch (operation)
    {
        case 1:
        {
            result = num1 + num2;
            break;
        }
        case 2:
        {
            result = num1 - num2;
            break;
        }
        case 3:
            
            result = num1 * num2;
            break;
        
        case 4:
        {
            if (num2 != 0)
            {
                result = num1 / num2;
            }
            else
            {
                do
                {
                    std::cout << "Impossible to divide by zero" << std::endl;
                    num2 = getNumber();

                } while (num2 == 0);

                result = num1 / num2;
            }

            break;
        }

        case 5:
        {
            const double aux{ num1 };

            if (num2 < 0)
            {
                /*
                for (size_t i = 1; i < num2 * -1; i++)
                {
                    num1 = (1 / num1) * (1 / aux);
                }
                */

                for (int i = 1; i < num2 * -1; i++)
                {
                    num1 = num1 / aux;
                }

                result = num1;

            }
            else
            {
                for (int i = 1; i < num2; i++)
                {
                    num1 = num1 * aux;
                }

                result = num1;
            }

            break;
        }

        default:
        {
            std::cout << "Type only integer numbers from 1 to 5";
            break;
        }
    }

    std::cout << "The result is: " << result << std::endl;

    return 0;
}