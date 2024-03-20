**Gustavo Aragão Guedes**

**RA: 10376534**

Laboratório 2b foi feito na linguagem c, com o uso da AWS para testes e Livegap Charts (https://charts.livegap.com/) para a criação dos gráficos.

### Testes

**1 processador (AWS):**

![Configuração 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/1ac61e5f-eba8-493f-938c-798cfa8fce66)


* Serial: 0,30 segundos

  ![Teste S 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/0d0e081e-a4d4-4167-8e46-b8c7a0e88b83)

  ![Tempo S  1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/161c6fb3-5ab5-4ecf-8249-16c46f6cd598)


* Paralelo com threads: 1,890 segundos

  ![Teste P 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/f3d972bd-73fe-4f38-8a77-9fe6f39eead4)

  ![setup P 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/b5786f61-ae89-4765-abee-0e679ecfea17)

  ![Tempo P 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/73c31f55-bcd3-45c0-ae3f-b3a8b3f8746d)


**2 processadores:  Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 0,30 segundos

* Paralelo com threads: 0,95 segundos

**4 processadores:  Intel(R) Xeon(R) i7-3612QM CPU @ 2.10GHz**

![312434718-f59d2790-14d1-4f47-93b3-95a59d3130a9](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/91ab9e16-1096-41b4-a9fd-c00fff71262f)

* Serial: 0,30 segundos

* Paralelo com threads: 0,474 segundos


**6 processadores: Intel(R) Xeon(R) CPU E-2236 @ 3.40GHz**

* Serial: 0,30 segundos

* Paralelo com threads: 0,317 segundos

**8 processadores: Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 0,30 segundos
  
* Paralelo com threads: 0,236 segundos

## Tempo de execução:

![Multiplicação Matriz-vetor](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/8cb16406-3f14-4058-936d-a79aa5b83fda)

## Speedup

* 1P = 0,30 / 1,89 = 0,159

* 2P = 0,30 / 0,95 = 0,316

* 4P = 0,30 / 0,474 = 0,633

* 6P = 0,30 / 0,317 = 0,946

* 8P = 0,30 / 0,236 = 1,271

![Multiplicação matriz-vetor-speedup](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/fc585eea-f8bd-4444-8db2-37f9f8ffad68)

## Forma de melhorar o paralelismo do algorítmo: Escalonamento dinâmico

Em vez de dividir o trabalho de forma estática entre as threads, como anteriormente, agora os trabalhos serão divididos em blocos menores e distribuidos conforme as threads ficam disponíveis.

Foi adicionado o mutex ao algorítmo, ele é um mecanismo de sincronização usado em programação concorrente para controlar o acesso a recursos compartilhados por múltiplas threads. Ele permite que apenas uma thread por vez execute uma seção crítica do código.

No novo algorítmo, cada thread bloqueia o mutex, verifica se há blocos restantes para processar e, em seguida, pega um bloco da variável next_block para processar. A variável next_block é atualizada atomicamente usando o mutex. Dessa forma, as threads obtêm blocos de trabalho dinamicamente conforme concluem seus blocos anteriores e melhoram o desempenho do programa.

### Resultados novos na AWS:

![Novo Setup P](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/68088b02-c567-4c94-8be3-9f3ef5101c59)

![Novo teste P](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/9d928827-98e2-4f76-9e52-c4132c521c6a)

![Novo tempo P](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/3e63fc4c-c6a2-4b73-8644-f6dc91924fec)

Diferença: De 1,890 segundos para 1,235 segundos

## Novo Speedup

* 1P = 0,30 / 1,235 = 0,243

* 2P = 0,30 / 0,619 = 0,485

* 4P = 0,30 / 0,309 = 0,971

* 6P = 0,30 / 0,206 = 1,456

* 8P = 0,30 / 0,155 = 1,935

![Multiplicação matriz-vetor Speedup Novo(1)](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/2601df55-bde6-491f-b490-e7ee240bbd57)



