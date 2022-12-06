# Guião 8: Signals

![IST](img/IST_DEI.png)  

## Objectivos

No final deste guião, deverá ser capaz de:

- Explicar o que é um Signal e como se usa para controlar processos do sistema operativo;
- Programar o tratamento de sinais assíncronos;

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

1. Clone este repositório, usando o git: `git clone https://github.com/tecnico-so/lab_ferramentas.git`
2. Estude o programa `intquit.c`:
    - Repare na definição da função `sigHandler()`, chamada assincronamenente para tratar o sinal quando o processo o receber;
    - Repare nos tratamentos do SIGINT (linha 16) e SIGQUIT (linha 27);
    - A função signal() regista a rotina de tratamento para estes sinais (linhas 37 e 39). Neste caso a mesma rotina `sigHandler()` vai ser registada para tratar dois eventos diferentes (`SIGINT` e `SIGQUI`),mas poderiam ser rotinas diferentes;
3. Compile o programa com a ferramenta `make` (dentro da pasta `src/`).
4. Corra o programa (`./intquit.c` ou `make run`).
5. Observe que o programa inicia e fica num ciclo infinito ou parado.
6. Experimente fazer CTRL-C (ou SIGINT) e observe o resultado.
7. Repita o passo 6.
8. Experimente fazer CTRL-\ (ou SIGQUIT) e observe o resultado.

### 3 - Exercício CTRL-Z

1. Adicione o tratamento do sinal SIGSTP (ou CTRL-Z) numa nova função `stopHandler()`.
2. Compile e teste

Contactos para sugestões/correções: [LEIC-Alameda](mailto:leic-so-alameda@disciplinas.tecnico.ulisboa.pt), [LEIC-Tagus](mailto:leic-so-tagus@disciplinas.tecnico.ulisboa.pt), [LETI](mailto:leti-so-tagus@disciplinas.tecnico.ulisboa.pt)
