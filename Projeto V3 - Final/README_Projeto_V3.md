**Gustavo Aragão Guedes**

**RA: 10376534**

Terceira e última versão do projeto feita na linguagem C.

Imprime 5000 casas decimais do Valor de Euler

## Diferenças dessa versão para a versão 2:

**1. Biblioteca Adicional: `#include <gmp.h>`**

  Inclusão da biblioteca GMP (GNU Multiple Precision Arithmetic Library)
  
  **Benefício**: 
  - A biblioteca GMP permite operações aritméticas de alta precisão, necessárias para calcular muitas casas decimais da constante 'e'. 
  - Usando `mpf_t`, a precisão pode ser configurada para operar com números de precisão arbitrária, muito superior à oferecida por tipos de dados nativos do C.

**2. Alteração na Função de Cálculo do Fatorial**

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

  `mpf_t *factorial_cache` é alocado usando `malloc` e inicializado com `mpf_init`.
  
  **Benefício**: 
  - Permite alocação dinâmica de memória para armazenamento de fatoriais com precisão arbitrária, garantindo que a memória é gerenciada corretamente para grandes valores de 'n'.

**7. Loop Paralelo com Redução Local e Crítica Global**

  Uso de variáveis locais para a soma parcial dentro do loop paralelo e adição crítica para somar os resultados parciais ao valor global de 'e'.
  
  **Benefício**: 
  - Reduz a contenção de threads na seção crítica, melhorando a eficiência do programa.
  - `#pragma omp for schedule(dynamic)` melhora o balanceamento de carga entre threads, especialmente útil quando os tempos de computação por iteração podem variar.

**8. Impressão com Alta Precisão**

  Uso de `gmp_printf` para imprimir 'e' com até 5000 casas decimais.
  
  **Benefício**: 
  - Permite a exibição de um grande número de casas decimais da constante 'e', demonstrando a precisão do cálculo.

**9. Limpeza de Memória**

  Uso de `mpf_clear` para liberar memória alocada para variáveis `mpf_t`.
  
  **Benefício**: 
  - Garante que toda a memória dinâmica é liberada corretamente, prevenindo vazamentos de memória.

## Bibliotecas utilizadas:

**1. <stdio.h>**

Proporciona funções de entrada e saída padrão.
    
  Exemplos no código:

  - printf("Digite o número de threads a serem usadas: "); exibe uma mensagem solicitando a entrada do usuário.

  - scanf("%d", &num_threads); lê o número de threads inserido pelo usuário.

  - printf("Tempo total: %f segundos\n", elapsed_time); exibe o tempo total de execução do programa.

**2. <omp.h>**

  Permite o uso de OpenMP para programação paralela, melhorando o desempenho ao dividir o trabalho entre múltiplas threads.
  
  Exemplos no código:
  
  - omp_set_num_threads(num_threads); configura o número de threads a serem usadas na execução paralela.

  - double start_time = omp_get_wtime(); obtém o tempo de início da execução paralela.

  - #pragma omp parallel inicia uma região paralela.

  - #pragma omp for schedule(dynamic) distribui dinamicamente as iterações do loop entre as threads.

  - #pragma omp critical garante que a adição à variável e seja realizada de forma segura em um ambiente multi-thread.

**3. <stdlib.h>**

  Fornece funções para gerenciamento de memória dinâmica.
  
  Exemplos no código:
  
  - mpf_t *factorial_cache = (mpf_t *)malloc((n + 1) * sizeof(mpf_t)); aloca memória para o cache dos fatoriais.

  - free(factorial_cache); libera a memória alocada para o cache dos fatoriais.

**4. <gmp.h>**

  Proporciona tipos e funções para aritmética de precisão arbitrária, essencial para cálculos que requerem alta precisão.
  
  Exemplos no código:

  - mpf_set_default_prec(4096); define a precisão padrão para 4096 bits.

  - mpf_t e; mpf_init(e); inicializa a variável e com precisão arbitrária.

  - mpf_set_ui(e, 0); define o valor inicial de e como 0.

  - mpf_mul_ui(factorial_cache[i], factorial_cache[i-1], i); calcula o fatorial usando multiplicação de precisão arbitrária.

  - mpf_ui_div(term, 1, factorial_cache[i]); calcula o inverso do fatorial para o termo da série.

  - gmp_printf("O valor final de e calculado: %.5000Ff\n", e); imprime o valor final de e com até 5000 casas decimais.

  - mpf_clear(e); libera a memória associada à variável e de precisão arbitrária.

## Funcionamento passo a passo do código:

**1. Importação de Bibliotecas:**

  Inclui bibliotecas para entrada/saída, programação paralela, alocação de memória e aritmética de precisão arbitrária.
  
**2. Função de Cálculo de Fatoriais:**

  Usa memoização para calcular e armazenar os fatoriais até o valor n, utilizando alta precisão, evitando cálculos repetidos.
  
**3. Solicitação do Número de Threads:**

  O programa solicita ao usuário o número de threads a serem utilizadas e valida a entrada.
  
**4. Configuração Inicial:**

  Define a precisão padrão para os cálculos com alta precisão e inicializa as variáveis necessárias, incluindo a variável de resultado e um array para armazenar os fatoriais.
  
**5. Alocação de Memória para Fatoriais:**

  Aloca memória dinamicamente para armazenar os fatoriais calculados com alta precisão.
  
**6. Cálculo de Fatoriais:**

  Calcula todos os fatoriais necessários antes do loop paralelo e os armazena no array alocado.

**7. Configuração e Execução de Paralelismo:**

  Configura o número de threads e utiliza programação paralela para somar os termos da série de Taylor, utilizando uma variável local para cada thread para evitar conflitos de escrita.
  
**8. Redução Crítica:**

  Soma os resultados parciais de cada thread em uma região crítica para obter o resultado final de forma segura.
  
**9. Medição e Impressão do Tempo de Execução:**

  Mede o tempo total de execução e imprime o valor calculado de e com alta precisão, além do tempo de execução total.

**10. Liberação de Memória:**

  Libera a memória alocada para os cálculos de alta precisão e outras variáveis utilizadas.

## Comando para compilar o código:

gcc -fopenmp -lgmp -o (nome) (nome).c


./(nome)
