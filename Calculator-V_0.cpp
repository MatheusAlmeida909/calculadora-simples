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
    const int last_operacao{ 5 };
    const int first_operacao{ 1 };

    int operacao;

    do
    {
        std::cout << "Choose an operation\n ~ 1 = add\n ~ 2 = subtract\n ~ 3 = multiply\n ~ 4 = divide\n ~ 5 = power" << std::endl;
        std::cin >> operacao;

        if (operacao > last_operacao || operacao < first_operacao)
        {
            std::cout << "This number doesn't correspond to a valid operation" << std::endl;
        }

    } while (operacao > last_operacao || operacao < first_operacao);

    double num1{ getNumber() };
    double num2{ getNumber() };
    double result{ 0 };

    switch (operacao)
    {
        case 1:
            
            result = num1 + num2;
            break;
        
        case 2:

            result = num1 - num2;
            break;
        
        case 3:
            
            result = num1 * num2;
            break;
        
        case 4:
            
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

        case 5:

            double aux{ num1 };
            
            if (num2 < 0)
            {
                /*
                for (size_t i = 1; i < num2 * -1; i++)
                {
                    num1 = (1 / num1) * (1 / aux);
                }
                */
                
                for (size_t i = 1; i < num2 * -1; i++)
                {
                    num1 = num1 / aux;
                }

                result = num1;
                
            }
            else
            {
                for (size_t i = 1; i < num2; i++)
                {
                    num1 = num1 * aux;
                }

                result = num1;
            }

            break;
    }
    std::cout << "The result is: " << result << std::endl;

    return 0;
}