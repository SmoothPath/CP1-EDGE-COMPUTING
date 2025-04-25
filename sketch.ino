#include <LiquidCrystal.h>

// Inicializa o LCD nos pinos: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Definição dos pinos
const int ldrPin = A0;         // Sensor de luz (LDR)
const int ledVerde = 6;        // LED verde (OK)
const int ledAmarelo = 7;      // LED amarelo (atenção)
const int ledVermelho = 8;     // LED vermelho (alerta)
const int buzzer = 9;          // Buzzer para alerta sonoro

// Tempo de leitura e intervalo entre amostras
const int tempoLeitura = 5000; // Tempo total de leitura: 5 segundos
const int intervaloLeitura = 100; // Intervalo entre leituras (ms)
const int numLeituras = tempoLeitura / intervaloLeitura; // Total de amostras

// Caracteres personalizados para animação no LCD (forma de bandeira)
byte wave1[8] = {
  B00110,
  B01100,
  B11000,
  B10001,
  B00011,
  B00110,
  B01100,
  B00000
};

byte wave2[8] = {
  B00011,
  B00110,
  B01100,
  B10000,
  B11001,
  B10011,
  B00110,
  B00000
};

byte wave3[8] = {
  B00000,
  B00110,
  B01111,
  B11100,
  B01110,
  B00111,
  B00011,
  B00000
};

void setup() {
  // Define os pinos dos LEDs e buzzer como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Inicia o LCD (16 colunas x 2 linhas)
  lcd.begin(16, 2);

  // Criação dos caracteres personalizados no LCD
  lcd.createChar(0, wave1);
  lcd.createChar(1, wave2);
  lcd.createChar(2, wave3);

  // Executa animação de abertura com bandeira
  animacaoInicial();
}

void loop() {
  long soma = 0;

  // Lê várias amostras da LDR e soma os valores
  for (int i = 0; i < numLeituras; i++) {
    soma += analogRead(ldrPin);
    delay(intervaloLeitura);
  }

  // Calcula a média das leituras
  int mediaLDR = soma / numLeituras;

  // Mapeia o valor para uma escala de 0 (escuro) a 100 (claro)
  int intensidade = map(mediaLDR, 8, 1016, 100, 0);

  // Limpa o LCD antes de exibir novas informações
  lcd.clear();

  // Avaliação da intensidade de luz
  if (intensidade >= 75) {
    // Luz muito forte (alerta)
    lcd.setCursor(0, 0);
    lcd.print("Luz: ");
    lcd.print(intensidade);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("ALERTA! ALTA");

    // Ativa LED vermelho e buzzer
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 265, 15000);  // Tom de alerta por um tempo maior (15 segundos)
    
  } else if (intensidade > 40 && intensidade < 75) {
    // Luz média (atenção)
    lcd.setCursor(0, 0);
    lcd.print("Luz: ");
    lcd.print(intensidade);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("ATENCAO: Media");

    // Ativa LED amarelo
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    digitalWrite(buzzer, HIGH);
    tone(buzzer, 265, 3000);  // Tom de alerta por 3 segundos
    digitalWrite(buzzer, LOW);

  } else {
    // Ambiente escuro (OK)
    lcd.setCursor(0, 0);
    lcd.print("Luz: ");
    lcd.print(intensidade);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Ambiente OK");

    // Ativa LED verde
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(buzzer, LOW);
  }

  delay(2000); // Aguarda antes da próxima leitura
}
//Boas vindas ao sistema!
// Função de animação inicial com nome da equipe e bandeira
void animacaoInicial() {
  lcd.clear();
  lcd.setCursor(0, 0);

  // Desenha a bandeira com caracteres personalizados
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));

  // Efeito digitado para " SmoothPath"
  String titulo = " SmoothPath";
  for (int i = 0; i < titulo.length(); i++) {
    lcd.print(titulo[i]);
    delay(150); // tempo entre cada letra (ajuste se quiser mais rápido/lento)
  }

  lcd.setCursor(0, 1);

   // Efeito digitado para "Monitorando..."
  String status = "Iniciando...";
  for (int i = 0; i < status.length(); i++) {
    lcd.print(status[i]);
    delay(150); // mesmo efeito digitado
  }

  delay(3000); // pausa para o usuário ler
  lcd.clear();

   // Efeito digitado para "Analise..."
  String logando = "Analisando...";
  for (int i = 0; i < logando.length(); i++) {
    lcd.print(logando[i]);
    delay(150); // mesmo efeito digitado
  }
  
}