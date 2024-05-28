**Gustavo Aragão Guedes**

**RA: 10376534**

Terceira e última versão do projeto foi feita na linguagem c.



## Mudanças da versão 2:

Escalonamento de Laços:

A cláusula schedule(dynamic) foi adicionada ao pragma omp parallel for para testar o escalonamento dinâmico

Benefícios 
Escalonamento Dinâmico:
Pode melhorar o balanceamento de carga entre as threads, especialmente se algumas iterações do loop levarem mais tempo para serem calculadas do que outras.
Redução do Overhead de Sincronização:
A cláusula reduction reduz a necessidade de seções críticas, diminuindo o overhead de sincronização e potencialmente melhorando o desempenho.

Uso da Biblioteca GMP:

A biblioteca GMP é usada para realizar cálculos de precisão arbitrária. Certifique-se de instalar a biblioteca GMP (sudo apt-get install libgmp-dev no Linux).
Aumento do Número de Termos:

O valor de n foi aumentado para 1000, o que permitirá uma maior precisão no cálculo de 𝑒
e.
Configuração da Precisão:

A precisão é configurada para 1024 bits com mpf_set_default_prec(1024).
Cálculo Paralelo:

O cálculo do valor de 
𝑒
e é paralelizado usando OpenMP, com redução manual dos valores calculados em cada thread.
Impressão com Alta Precisão:

gmp_printf é usado para imprimir o valor de 
𝑒
e com 50 casas decimais.

## Explicação do código:





## Comando para compilar o código:

gcc -fopenmp -lgmp -o (nome) (nome).c


./(nome)
