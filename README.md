 # Comedouro Automático para Animais

### 📌 Descrição do Projeto

Este projeto tem como objetivo o desenvolvimento de um comedouro automático para animais, utilizando um sistema baseado em Arduino. O sistema detecta a presença do animal através de um sensor ultrassônico e aciona um servo motor para abrir o depejador de ração e depois abre a gaveta de ração  e deixa o animal comer e depois de um tempo a gaveta fecha e abre novamente só depois de certo tempo novamente. 

* Atualmente(16/02/2025), o motor de 12V testado não conseguiu abrir a gaveta, e novos testes serão realizados com motores diferentes. * 

### 🛠 Tecnologias Utilizadas

O projeto foi desenvolvido utilizando as seguintes tecnologias:

- Linguagem de Programação: C++ (para Arduino)

- Plataforma: Arduino (com bibliotecas Servo.h e Wire.h)

- Componentes:

  - 🛠 Servo Motor (para movimentar a gaveta de ração)

  - 📡 Sensor Ultrassônico (para detectar a presença do animal)

  - 🔊 Buzzer Piezoelétrico (para alertar a liberação de comida)

 - 🛠 Motor de 12v

  - 🛠 Realay(converter energia para o motor de 12v)


### 📝 Estrutura do Código

O código está organizado da seguinte forma:

- ⚙ Setup: Inicializa os componentes e define os pinos de conexão.

- 🔄 Loop: Monitora o sensor ultrassônico e controla o servo motor, LEDs e buzzer.

- 📌 Funções auxiliares:

* O código foi comentado detalhadamente para facilitar a compreensão. * 

### 🔌 Montagem do Circuito

- 📦 Materiais Necessários:

 - ✅ 1 x Arduino Uno

 - ✅ 1 x Servo Motor (testando diferentes modelos)

 - ✅ 1 x Sensor Ultrassônico HC-SR04

 - ✅ 1 x Buzzer Piezoelétrico

 - ✅ 2 x LEDs (Verde e Vermelho)

 - ✅ Resistores adequados

 - ✅ Fonte de alimentação 12V (para motor)

### 🖥 Esquema de Ligação:

- Servo Motor: Pino de controle no pino 10 do Arduino

- Sensor Ultrassônico: TRIG no pino 5, ECHO no pino 6

- Buzzer: Pino de controle no pino 8


### 🔄 Funcionamento do Sistema

- 📡 O sensor ultrassônico mede a distância continuamente.

- 🐶 Se um objeto (animal) for detectado Proximo, o servo motor é ativado para abrir a gaveta.

- 🔊 O buzzer emite um som e o LED verde acende.

- ⏳ Após 5 segundos, o servo retorna à posição inicial e inicia um cooldown de 1 minuto.


- ✅ Ao final do cooldown, o sistema volta a estar pronto para nova detecção.

### 🚀 Instalação e Execução

- 🔽 Instale a IDE do Arduino (download aqui).

- 📥 Instale as bibliotecas necessárias (Servo.h, Wire.h).

- 🔌 Conecte o Arduino ao computador via USB.

- 🖥 Compile e carregue o código para a placa Arduino.

- 🛠 Monte o circuito conforme o esquema acima.



