#lucianopinheirob
#Como um desafio a mais, esse código foi feito com um loop mais "pythonico".

class Solution:
    def romanToInt(self, s: str) -> int:
       
        dicio = {
            'M': 1000,
            'D': 500,
            'C': 100,
            'L': 50,
            'X': 10,
            'V': 5,
            'I': 1
            }
        
        indice_max = len(s) - 1
        numero_inteiro = 0
        ocorreu_excecao = False

        for indice, letra in enumerate(s):
            
            #Skipa um índice quando ocorre uma exceção
            if ocorreu_excecao:
                ocorreu_excecao = False
                continue
            
            #Checa se já chegou no final da string
            if indice != indice_max:
                valor_atual = dicio[s[indice]]
                valor_proximo = dicio[s[indice+1]]
                delta_valor = valor_atual - valor_proximo
            else:
                valor_atual = dicio[s[indice]]
                valor_proximo = 0
                delta_valor = valor_atual - valor_proximo
            
            #Trata exceção
            if delta_valor < 0:
                ocorreu_excecao = True
                numero_inteiro -= delta_valor
                continue
            
            numero_inteiro += valor_atual
            
        return numero_inteiro
            
solucao = Solution()
print(solucao.romanToInt('CMXIV'))
