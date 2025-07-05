#include <iostream>
#include <string>
#include <map>

/*
    Metódo de resolução:

     A ideia é encontrar a maior substring sem caracteres repetidos dentro de uma string.
    Além disso, foi adiciona uma string passada por referência para obter a substring gerada.

    Para isso, usamos duas ferramentas principais:

    1. Hash map (`map<char, int>`):
        - Serve para guardar a última posição onde cada caractere apareceu.
        - Exemplo: Para a string "pwe", o map ficaria:
            'p' -> 0
            'w' -> 1
            'e' -> 2

    2. Janela deslizante (ou sliding window):
        - Usamos dois ponteiros, `start` e `end`, para definir a janela atual da substring.
        - `start` marca o início da substring atual sem repetições.
        - `end` percorre a string letra por letra.
        - Quando encontramos um caractere repetido dentro da janela, movemos `start` para a posição após a última ocorrência desse caractere.

        Obs: Sliding window é uma técnica útil quando você precisa analisar partes contínuas de uma lista ou string,
             como achar o maior trecho sem repetir letras ou a maior soma de números em sequência.
             Ela funciona bem quando dá pra resolver o problema só movendo o começo e o fim de uma janela dentro da sequência.
             Mas não serve quando o problema envolve combinações espalhadas ou fora de ordem, tipo subsequências que pulam elementos.

    A cada passo, calculamos o tamanho da janela com a com diferença dos index (fim - inicio + 1) para chegar no tamanho:
        `window_size = end - start + 1`
    E se essa for a maior janela até o momento, salvamos o tamanho da maior substring em max_len.

    Passo a passo:
    - Iteramos sobre a string usando um ponteiro end, que percorre cada caractere.
    - Para cada caractere atual s[end], verificamos duas condições:
        - Se ele já existe no hash map (map.count(s[end]))
        - E se a posição armazenada é maior ou igual ao start atual (ou seja, ainda está dentro da janela de análise).
        - Isso indica que há uma repetição dentro da substring atual, o que invalida a sequência sem caracteres duplicados.

        if (map.count(s[end]) && map[s[end]] >= start)
        Exemplo:
            abba :  map['a'] = 0  -> end = 0, não está no mapa, start = 0, max_len = 1, map['a'] = 0
                    map['b'] = 1  -> end = 1, não está no mapa, start = 0, max_len = 2
                    map['b'] = 2  -> end = 2, está no mapa, start = 2, max_len = 2
                                     map['b'] >= start (1 > 0) -> repetição dentro da janela.
                    map['a'] = 3  -> end = 3,  está no mapa, start = 2, max_len = 2
                                     map['a'] < start (0 < 2) -> repetição fora da janela.

    - Atualizamos o hash map com a posição atual do caractere: map[s[end]] = end;
    - Calculamos o tamanho da janela atual: window_size = end - start + 1;
    - Se o tamanho atual da substring for maior que o tamanho da ultima substring armazenada, atualizamos max_len
    - Dentro desse if de verificação da maior substring, limpamos a string passada por referência, e copiamos os elementos de start a end para ela,
      sub += s[i]
*/

class Solution {
    public:
        int lengthOfLongestSubstring(std::string s, std::string &sub) {
            std::map<char, int> map;
            int start = 0;
            int max_len = 0;
            for (int end = 0; end < s.size(); end++)
            {
                if(map.count(s[end]) && map[s[end]] >= start)
                {
                    start = map[s[end]] + 1;
                }
                map[s[end]] = end;
                int window_size = end - start + 1;
                if(window_size > max_len)
                {
                    max_len = window_size;
                    sub = "";
                    for(int i = start; i <= end; i++)
                    {
                        sub += s[i];
                    }
                }
            }
            return max_len;
        }
};

int main()
{
    std::string s = "pwwkew";
    std::string sub = "";
    Solution sol;
    std::cout << sol.lengthOfLongestSubstring(s, sub) << std::endl;
    std::cout << sub << std::endl;
}
