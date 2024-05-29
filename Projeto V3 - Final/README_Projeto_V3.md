**Gustavo Aragão Guedes**

**RA: 10376534**

Terceira e última versão do projeto feita na linguagem C.

Imprime 5000 casas decimais do Valor de Euler

## Diferenças dessa versão para a versão 2:

**1. Biblioteca Adicional: `#include <gmp.h>`**

  Inclusão da biblioteca GMP (GNU Multiple Precision Arithmetic Library).
  
  **Benefício**: 
  - A biblioteca GMP permite operações aritméticas de alta precisão, necessárias para calcular muitas casas decimais da constante 'e'. 
  - Usando `mpf_t`, a precisão pode ser configurada para operar com números de precisão arbitrária, muito superior à oferecida por tipos de dados nativos do C.

**2. **Alteração na Função de Cálculo do Fatorial**

  A função `calculate_factorials` foi modificada para usar `mpf_t` em vez de `unsigned long long`.
  
  **Benefício**: 
  - Permite calcular e armazenar fatoriais com precisão arbitrária, necessária para cálculos precisos em séries de Taylor com muitos termos.

**3. Alteração no Número de Termos da Série de Taylor**

  O número de termos 'n' foi aumentado de 100 para 20000.
  
  **Benefício**: 
  - Aumentar o número de termos melhora a precisão do cálculo da constante 'e', permitindo a geração de mais casas decimais corretas.

**4. Configuração da Precisão**

  Uso de `mpf_set_default_prec(4096)` para definir a precisão padrão para 4096 bits.
  
  **Benefício**: 
  - Permite que as operações aritméticas com `mpf_t` sejam realizadas com alta precisão, essencial para cálculos que requerem um grande número de casas decimais.

**5. Alteração na Inicialização da Variável `e`**

  `mpf_t e` é inicializado com `mpf_init(e)` e `mpf_set_ui(e, 0)`.
  
  **Benefício**: 
  - Usa um tipo de dado de precisão arbitrária para armazenar o valor de 'e', melhorando a precisão do cálculo.

**6. Uso de `malloc` e `mpf_init` para Alocar Memória**

  - `mpf_t *factorial_cache` é alocado usando `malloc` e inicializado com `mpf_init`.
  
  **Benefício**: 
  - Permite alocação dinâmica de memória para armazenamento de fatoriais com precisão arbitrária, garantindo que a memória é gerenciada corretamente para grandes valores de 'n'.

**7. Loop Paralelo com Redução Local e Crítica Global**

  - Uso de variáveis locais para a soma parcial dentro do loop paralelo e adição crítica para somar os resultados parciais ao valor global de 'e'.
  
  **Benefício**: 
  - Reduz a contenção de threads na seção crítica, melhorando a eficiência do programa.
  - `#pragma omp for schedule(dynamic)` melhora o balanceamento de carga entre threads, especialmente útil quando os tempos de computação por iteração podem variar.

**8. Impressão com Alta Precisão**

  - Uso de `gmp_printf` para imprimir 'e' com até 5000 casas decimais.
  
  **Benefício**: 
  - Permite a exibição de um grande número de casas decimais da constante 'e', demonstrando a precisão do cálculo.

**9. Limpeza de Memória**

  - Uso de `mpf_clear` para liberar memória alocada para variáveis `mpf_t`.
  
  **Benefício**: 
  - Garante que toda a memória dinâmica é liberada corretamente, prevenindo vazamentos de memória.

## Bibliotecas utilizadas:



## Funcionamento do código:







## Comando para compilar o código:

gcc -fopenmp -lgmp -o (nome) (nome).c


./(nome)
