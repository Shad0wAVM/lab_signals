# Guião 8: Signals

![IST](img/IST_DEI.png)  

## Objectivos

No final deste guião, deverá ser capaz de:

- explicar o que é um Signal e como se usa para controlar processos do sistema operativo; (?)
- programar o tratamento de sinais assíncronos. (?)
- usar os Jobs para a gestão de vários programas numa mesma sessão de shell. (?)

## Introdução

Um sinal (signal) é mensagem definida e **assíncrona** enviada para um processo ativo com o objetivo de provocar um comportamento específico (como a sua terminação, por exemplo).
O sistema operativo interrompe o fluxo normal de execução do processo para este tratar o sinal.
O tratamento de um sinal está predefinido, mas pode ser criada uma rotina para tratar este sinal como vamos ver a seguir. 

### 1 - Comando `kill`

O envio de sinais pode ser feito com o comando `kill`.
```sh
$ kill -s TERM 1234
$ kill -TERM 1234
```
`TERM` corresponde ao sinal que pretendemos enviar.
Observe os possíveis sinais com `kill -L`.

`1234` corresponde ao identificador do processo (PID) a que pretendemos enviar o sinal.
Observe os processos ativos com `ps` (ou `top` ou `pgrep`).

Pergunta: Qual é o sinal enviado por omissão com o comando `kill 1234`?
(Sugestão: consulte a página no manual `man kill`)

### 2 - Exemplo `intquit.c`

1. GIT CLONE
2. LER PROGRAMA:
    - Repare em A;
    - Repare em B;
3. COMPILAR PROGRAMA
4. CORRER PROGRAMA
5. programa inicia e fica num ciclo infinido ou parado
6. fazer CTRL-C (ou SIGINT) e observar resultado
7. repetir passo 2
8. enviar CTRL-\ (ou SIGQUIT) e observar resultado

Pergunta: distinguir mensagens impressas

### 3 - Exercício `intquitstop.c`

1. copiar intquit.c e adicionar intquitstop.c à Makefile
2. tratar sinal SIGSTP (ou CTRL-Z)
3. compilar e testar

Contactos para sugestões/correções: [LEIC-Alameda](mailto:leic-so-alameda@disciplinas.tecnico.ulisboa.pt), [LEIC-Tagus](mailto:leic-so-tagus@disciplinas.tecnico.ulisboa.pt), [LETI](mailto:leti-so-tagus@disciplinas.tecnico.ulisboa.pt)
