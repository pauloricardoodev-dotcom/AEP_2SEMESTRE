# 🩺 Triate(c)

O **Triate(c)** é um programa desenvolvido em **linguagem C++** com o objetivo de **facilitar e auxiliar na obtenção de um prognóstico** por meio de uma **árvore de decisão**.  
Com ele, o usuário pode realizar, em poucos passos, uma **triagem rápida** que indica **qual doença gripal seus sintomas podem representar**.

---

## ⚙️ Funcionalidades

O menu principal do **Triate(c)** possui **cinco opções** principais:

1. **Informações do Paciente**  
   - Permite inserir **nome, idade e telefone para contato**.  
   - Os dados são armazenados em **variáveis temporárias**.  
   - Utiliza a função `toupper()` para padronizar os textos em **maiúsculas**, garantindo uma visualização uniforme.

2. **Iniciar Triagem**  
   - O usuário responde a **uma série de perguntas** sobre sintomas comuns, como:  
     `febre, falta de ar, tosse, dor de garganta, dor de cabeça, fraqueza` e `contato com pessoas doentes`.  
   - As respostas são registradas como **0 (não)** e **1 (sim)**.

3. **Prognóstico**  
   - O programa utiliza **estruturas condicionais (if / else if)** para determinar o **quadro clínico**.  
   - Uma **pontuação de 0 a 100** é gerada conforme os sintomas informados, indicando o **nível de gravidade**.  
   - Exibe também as **observações**, com recomendações de acordo com o diagnóstico.

4. **Resultado**  
   - Mostra o **diagnóstico final** ao usuário.  
   - Informa se deve **procurar atendimento médico imediato (como uma UTI)** ou se pode **tratar os sintomas em casa** com cuidados simples.

5. **Encerrar Programa**  
   - Finaliza o **laço principal** e exibe uma **mensagem de saída**, encerrando o atendimento de forma clara e organizada.

---

## 🧠 Lógica do Sistema

O **Triate(c)** utiliza uma **árvore de decisão** baseada nos sintomas informados pelo usuário para estimar a **gravidade do quadro gripal**.  
Cada resposta influencia a pontuação final, que define se o caso é **leve**, **moderado** ou **grave**.

---

## 💻 Tecnologias Utilizadas

- Linguagem: **C++**
- Estruturas: `if`, `else if`, `switch`
- Funções: `toupper()`, `cin`, `cout`
- Conceitos: **variáveis temporárias**, **pontuação de risco**, **condicionais**, **laços de repetição**

---
