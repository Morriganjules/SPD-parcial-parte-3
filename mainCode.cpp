// C++ code
//
#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8
#define slideSwitch 2
#define SENSOR A0
#define PHOTORESISTOR A1
#define unidades A4
#define decimas A5
#define apagados 0
#define activarMotor 12
#define input1 4
#define input2 3

int cuenta = 0;
unsigned long lastUpdateTime = 0;
int lecturaSensor;
int velocity;

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(slideSwitch, OUTPUT);
  pinMode(unidades, OUTPUT);
  pinMode(decimas, OUTPUT);
  pinMode(SENSOR, INPUT);
  pinMode(PHOTORESISTOR, INPUT);
  digitalWrite(activarMotor, HIGH);
  digitalWrite(unidades, 0);
  digitalWrite(decimas, 0);
  Serial.begin(9600);
}

void loop()
{
  lecturaSensor = analogRead(SENSOR);
  int fuerza = map(lecturaSensor,0,466,0.0,10.0);
  determineVelocity(fuerza);
  
  int photoSensor = analogRead(PHOTORESISTOR);
  int intensidad = map(photoSensor, 2, 404, 0, 10);
  
  int value = digitalRead(slideSwitch);
  
  if(intensidad < 8){
    if (lastUpdateTime >= velocity) {
      switchSelection(value);
      lastUpdateTime = 0;
    } else {
      lastUpdateTime++;
    }
  }
  printCount(cuenta);
  
}

void switchSelection(int value){
  if (value == 0) {
      turnRight();
      cuenta++;
      if (cuenta > 99) {
        cuenta = 0;
      }
    } else {
      turnLeft();
      cuenta++;
      if (cuenta > 99) {
        cuenta = 0;
      }
      while (!esPrimo(cuenta)) {
        cuenta++;
        if (cuenta > 99) {
          cuenta = 0;
        }
      }
    }
}

void turnLeft(){
	digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
}

void turnRight(){
	digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
}

void determineVelocity(int fuerza){
  if(fuerza >= 0 && fuerza <= 3){
  	velocity = 60;
  }
  else if(fuerza >= 4 && fuerza <= 7){
  	velocity = 30;
  }
  else{
  	velocity = 20;
  }
} 

bool esPrimo(int numero) {
  if (numero == 0 || numero == 1 || numero == 4) return false;
  for (int x = 2; x < numero / 2; x++) {
    if (numero % x == 0) return false;
  }
  return true;
}

void printCount(int count){
	prenderDigito(apagados);
  	printDigit(cuenta/10);
  	prenderDigito(decimas);
  	prenderDigito(apagados);
  	printDigit(cuenta - 10*((int)cuenta/10));
    prenderDigito(unidades);
}

void prenderDigito(int digito){
  if(digito == unidades){
  	digitalWrite(unidades, LOW);
    digitalWrite(decimas, HIGH);
    delay(10);
  }
   else if(digito == decimas){
  	digitalWrite(decimas, LOW);
    digitalWrite(unidades, HIGH);
    delay(10);
  }
   else
   {
  	digitalWrite(unidades, HIGH);
    digitalWrite(decimas, HIGH);
  }
}

void printDigit(int numero){
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
  switch(numero){
  	case 0:
    	show0();
    	break;
    case 1:
    	show1();
    	break;
    case 2:
    	show2();
    	break;
    case 3:
    	show3();
    	break;
    case 4:
    	show4();
    	break;
    case 5:
    	show5();
    	break;
    case 6:
    	show6();
    	break;
    case 7:
    	show7();
    	break;
    case 8:
    	show8();
    	break;
    case 9:
    	show9();
    	break;
  }
}


void show0(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void show1(){
  digitalWrite(A, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
}

void show2(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(C, LOW);
  digitalWrite(F, LOW);
}
void show3(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
}
void show4(){
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  
  digitalWrite(A, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
}
void show5(){
  digitalWrite(A, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  
  digitalWrite(B, LOW);
  digitalWrite(E, LOW);
}
void show6(){
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(B, LOW);
}
void show7(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void show8(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void show9(){
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  
  digitalWrite(E, LOW);
}
