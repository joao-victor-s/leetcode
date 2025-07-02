#include <iostream>

/*
    Método de resolução:

    Para inverter um número inteiro (int de 32 bits), utiliza-se a técnica de extração e reconstrução dos dígitos.

    - A extração do último dígito é feita por meio do operador de módulo:
        x % 10 → retorna o último dígito do número.
        Exemplo: 123 % 10 = 3

    - Em seguida, removemos esse dígito do número original por divisão inteira:
        x / 10 → descarta o último dígito.
        Exemplo: 123 / 10 = 12

    - O número invertido é reconstruído acumulando os dígitos extraídos:
        rec = rec * 10 + digito
        Esse processo empurra os dígitos anteriores uma casa decimal à esquerda e adiciona o novo dígito à direita.

    - Repetimos o processo até que x se torne 0.

    Essa abordagem é útil, por exemplo, para verificar se um número é palíndromo sem converter para string.
*/


class Solution {
    public:
        bool isPalindrome(int x) {
            if(x < 0 || (x % 10 == 0 && x != 0)) return false;
            int cp = x;
            u_int64_t rec = 0;
            while (cp > 0)
            {
                int digit = cp % 10;
                cp = cp / 10;
                rec = rec * 10 + digit;
            }
            return (rec == x);
        }

    };

int main()
{
    int x = -121;
    int y = 1001;
    Solution sol;
    std::cout << sol.isPalindrome(x) << std::endl;
    std::cout << sol.isPalindrome(y) << std::endl;
}
