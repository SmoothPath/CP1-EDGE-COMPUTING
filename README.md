# CP1-EDGE-COMPUTING

O protótipo é um sistema de monitoramento de luminosidade desenvolvido em Arduino.
Ele utiliza um sensor LDR para medir a intensidade da luz ambiente, exibindo os resultados em um display LCD 16x2. Dependendo da quantidade de luz detectada, o sistema aciona LEDs coloridos (verde, amarelo ou vermelho) e um buzzer para alertar o usuário:

Ambiente OK (Luz baixa): LED verde aceso.

Atenção (Luz média): LED amarelo aceso e breve alerta sonoro.

Alerta (Luz alta): LED vermelho aceso e alerta sonoro prolongado.

O projeto também conta com uma animação inicial personalizada no LCD, mostrando uma bandeira animada da equipe SmoothPath e mensagens de boas-vindas.

⚙️ Dependências
Para compilar e executar o projeto, você precisa:

Arduino IDE (versão 1.8+ ou 2.0+)

Biblioteca padrão LiquidCrystal (já inclusa na instalação da Arduino IDE)

Placa Arduino Uno ou compatível

🛠️ Componentes Utilizados
1 × Arduino Uno

1 × Sensor LDR (módulo)

1 × Display LCD 16x2 (com comunicação paralela)

3 × LEDs (verde, amarelo, vermelho)

4 × Resistores para os LEDs e para a conexão do pino A do display LCD (1kΩ)

1 × Buzzer piezoelétrico

1 × Protoboard

Cabos de conexão (jumpers)

Como Reproduzir o Projeto:
1. Clonar o repositório =>
git clone https://github.com/organizacao/CP1-EDGE-COMPUTING.git

2. Abrir o código no Arduino IDE =>
Abra o arquivo .ino incluído no repositório.

3. Montar o circuito =>
Conecte os componentes conforme o esquema do projeto (imagem incluída no repositório).

Se preferir, pode simular antes usando o Wokwi.

4. Fazer o upload para o Arduino =>
Conecte o Arduino via USB.

Selecione a porta correta (Ferramentas > Porta) e o modelo de placa (Arduino Uno).

Clique em Upload.

Demonstração:
Quando o Arduino for ligado =>

A tela LCD mostrará uma animação de bandeira da equipe e mensagens de boas-vindas.

Após alguns segundos, o sistema começará a medir a luminosidade ambiente e mostrará o status correspondente no LCD, LEDs e buzzer.
