#include <iostream>
#include <stack>
#include <string>

/*
    Método de resolução:

    Estrutura utilizada: Pilha (stack)

    Justificativa do uso:
        A pilha é uma estrutura LIFO (Last-In, First-Out), ideal para problemas com dependência de ordem reversa ou aninhamentos.
        É amplamente utilizada em:
            - Reversão de ordem (ex: inversão de strings ou listas ligadas)
            - Avaliação de expressões matemáticas
            - Balanceamento de símbolos aninhados (parênteses, colchetes, chaves)
            - Monotonic stacks (ex: próximo maior elemento, histograma, desfazer ações)

    Objetivo:
        Verificar se a string de entrada contém uma sequência válida de parênteses, colchetes e chaves, considerando
        regras de abertura e fechamento corretas e bem-aninhadas.

    Etapas do algoritmo:

    1. Inicializar uma pilha vazia para armazenar os caracteres de abertura.

    2. Percorrer cada caractere da string:
        - Se for um caractere de abertura ('(', '{', '['):
            → Empilhar (push) na pilha.

        - Se for um caractere de fechamento (')', '}', ']'):
            → Se a pilha estiver vazia, a sequência é inválida (não há abertura correspondente).
            → Verificar se o topo da pilha corresponde ao caractere de abertura esperado:
                - ')' → espera '('
                - '}' → espera '{'
                - ']' → espera '['
            → Se corresponder, remover o topo da pilha (pop).
            → Caso contrário, a sequência é inválida.

    3. Após o loop, a pilha deve estar vazia:
        - Se estiver vazia → todos os pares foram corretamente fechados → válido.
        - Se não estiver vazia → há aberturas sem fechamento → inválido.
*/


class Solution {
public:
    bool isValid(string s)
    {
        std::stack<int> pilha;
        for (char c: s)
        {
            if(c == '(' || c == '{' || c == '['){
                pilha.push(c);
            }

            else if(c == ')' || c ==  '}' || c == ']'){
                if (pilha.empty())
                {
                    return false;
                }
                if (
                    (c == ')' && pilha.top() != '(') ||
                    (c == '}' && pilha.top() != '{') ||
                    (c == ']' && pilha.top() != '['))
                {
                    return false;
                }
                pilha.pop();
            }
        }
        return pilha.empty();
    }
};

int main()
{
    Solution sol;
    std::string s = "()";
    std::cout << sol.isValid(s) << std::endl;
    return 0;
}
