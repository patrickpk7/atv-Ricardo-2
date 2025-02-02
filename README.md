# ATIVIDADE 2 - PROFESSOR RICARDO PRATES

---

### Descrição

Este código liga os 3 LEDs RGB da placa Raspberry Pi Pico W quando o **Botão A** é pressionado. Após a ativação dos LEDs, o código executa a seguinte sequência:
1. Todos os LEDs (Vermelho, Verde e Azul) acendem.
2. Após 3 segundos, o LED **Vermelho** é desligado, mantendo os LEDs **Verde** e **Azul** acesos.
3. Após mais 3 segundos, o LED **Verde** é desligado, restando apenas o LED **Azul** aceso.
4. Finalmente, após a sequência, o LED **Azul** também se desliga.

> **Observação:** Não é possível acender os LEDs se algum dos três já estiver aceso. O processo só pode ser reiniciado após os três LEDs estarem completamente desligados.

---

### Especificações de Conexão

- **LED Vermelho:** Conectado ao pino **13**
- **LED Verde:** Conectado ao pino **11**
- **LED Azul:** Conectado ao pino **12**

---

### Exemplo de Uso

- **Passo 1:** O usuário pressiona o **Botão A**.
- **Passo 2:** Todos os LEDs RGB acendem.
- **Passo 3:** Após 3 segundos, o LED **Vermelho** apaga, mantendo apenas o **Verde** e o **Azul** acesos.
- **Passo 4:** Após mais 3 segundos, o LED **Verde** é desligado, ficando somente o **Azul** aceso.
- **Passo 5:** Ao final da sequência, o LED **Azul** se desliga e o sistema fica pronto para ser reiniciado.

---

### Como Executar

1. Faça o upload do código para a sua placa.
2. Pressione o **Botão A** para iniciar a sequência de acendimento e desligamento dos LEDs.
3. Aguarde a conclusão da sequência para que os LEDs possam ser acionados novamente.

---


