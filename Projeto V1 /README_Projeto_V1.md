**Gustavo Aragão Guede**

**RA: 10376534**

Laboratório V1 foi feito na linguagem c, com o uso da AWS para testes e Livegap Charts (https://charts.livegap.com/) para a criação dos gráficos.

Inclusão da API OpenMP.

Para os testes, foram calculados 50 números depois da vírgula e usadas 50 threads.

Alguns dos valores de tempo e speedups foram arredondados para ficarem com apenas 3 casas decimais depois da vírgula.


### Testes

**1 processador (AWS):**

![Configuração 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/1ac61e5f-eba8-493f-938c-798cfa8fce66)

* Serial: 1 segundo

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/8c1466af-0b6d-4e0a-b86c-17bacc97b2db)

* Paralelo: 6 segundos

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/87ec5578-c618-45ef-bd77-e9540b1012ab)

**2 processadores:  Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 1 segundo

* Paralelo: 3 segundo

**4 processadores:  Intel(R) Xeon(R) i7-3612QM CPU @ 2.10GHz**

![312434718-f59d2790-14d1-4f47-93b3-95a59d3130a9](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/91ab9e16-1096-41b4-a9fd-c00fff71262f)

* Serial: 1 segundo

* Paralelo: 1,5 segundos

**6 processadores: Intel(R) Xeon(R) CPU E-2236 @ 3.40GHz**

* Serial: 1 segundo

* Paralelo: 1 segundos

**8 processadores: Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 1 segundo
  
* Paralelo: 0,75 segundos

## Tempo de execução:

![Problema da Tartaruga Tempo](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/f35b67ab-4e87-4390-904a-e22ed4b55860)

## Speedup

* 1P = 1 / 6 = 0,166

* 2P = 1 / 3 = 0,333

* 4P = 1 / 1,5 = 0,666

* 6P = 1 / 1 = 1

* 8P = 1 / 0,75 = 1,333

![Problema da Tartaruga speedup](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/5289bcad-e6e3-4b09-a9ee-048a790b71f8)


## Diretiva critical

A seção crítica #pragma omp critical garante que apenas uma thread por vez execute a atualização das variáveis globais n, e_atual e tempo. Isso evita problemas de corrida que podem ocorrer quando várias threads tentam acessar e modificar as mesmas variáveis simultaneamente.

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/84040619-575d-4552-b62e-ace549c5cb62)

Sem critical: 6 segundos

Com critical: 6 segundos

* 1P = 6 segundos

* 2P = 3 segundos

* 4P = 1,5 segundos

* 6P = 1 segundos

* 8P = 0,75 segundos

## Novo Speedup 

Permance igual pois os tempos foram iguais

* 1P = 1 / 6 = 0,166

* 2P = 1 / 3 = 0,333

* 4P = 1 / 1,5 = 0,666

* 6P = 1 / 1 = 1

* 8P = 1 / 0,75 = 1,333

![Problema da Tartaruga speedup critical](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/23b4433f-754c-42aa-9966-b8b27b9b8618)


