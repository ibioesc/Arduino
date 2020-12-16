/*
Quiz numro #2
Realizado por:
    Julio Alberto Cando
    Fredy Alejandro Barriento
Profesor: Ing. Hernando Vanegas Lopez
Fecha Inicio: 15/12/2020
Fecha Fin: 15/12/2020
*/

int pines[]={15,22,4,5,18,19,21};
int pulsador=35;
int pulsador_2=34;
void encender(int a, int b,int c, int d, int e, int f, int g){
  digitalWrite(pines[0],a);
  digitalWrite(pines[1],b);
  digitalWrite(pines[2],c);
  digitalWrite(pines[3],d);
  digitalWrite(pines[4],e);
  digitalWrite(pines[5],f);
  digitalWrite(pines[6],g);
  delay(2000);
}
void setup() {
for (int i = 0; i < 7; i = i + 1) {
  pinMode(pines[i],OUTPUT);
}
pinMode(pulsador,INPUT);
pinMode(pulsador_2,INPUT);
}

void loop() {
    if(digitalRead(pulsador)== HIGH)
  {
    for (int i = 0; i < 203; i = i + 1) {
        
        encender (1, 1, 1, 0, 1, 1, 1); //Muestra el numero A
        encender (1, 1, 1, 0, 0, 0, 0); //Muestra el numero 7
        encender (1, 1, 1, 1, 1, 1, 1); //Muestra el numero 8
        encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero -


        }
}
  if(digitalRead(pulsador_2)== HIGH){
     for (int i = 0; i < 226; i = i + 1) {
      encender (1, 1, 1, 1, 1, 1, 1); //Muestra el numero B
      encender (1, 1, 0, 0, 1, 1, 0); //Muestra el numero 5
      encender (1, 1, 0, 0, 1, 1, 0); //Muestra el numero 5
      


     }
}
  }
