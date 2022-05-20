
//Inicio do código 


const int hallPin = 9;     // Conecte o pino de sinal
const int ledPin =  13;     // Conecte o pino positivo do lED
// variables will change:
int hallState = 0;          // Variavel de leitura do sensor

void setup() {
  // inicia o LED como saida:
  pinMode(ledPin, OUTPUT);
  // inicia o sensor como como entrada:
  pinMode(hallPin, INPUT);
}

void loop(){
  // lê o estatus do sensor:
  hallState = digitalRead(hallPin);

  if (hallState == LOW) {
    // liga o LED:
    digitalWrite(ledPin, LOW);
  }
  else {
    // desliga o LED:
    digitalWrite(ledPin, HIGH);
  }
}


//Fim do código 
