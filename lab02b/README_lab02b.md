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

![Multiplicação Matriz-vetor](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/a9b1d593-e6da-4f65-bc66-4fe24a054317)

## Speedup

* 1P = 0,30 / 1,89 = 0,159

* 2P = 0,30 / 0,95 = 0,316

* 4P = 0,30 / 0,474 = 0,633

* 6P = 0,30 / 0,317 = 0,946

* 8P = 0,30 / 0,236 = 1,271

![Multiplicação matriz-vetor-speedup](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/fc585eea-f8bd-4444-8db2-37f9f8ffad68)








