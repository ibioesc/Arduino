#define VELOCIDAD 2000   //velocidad de giro del motor, cuanto menos valor + velocidad



int pasos = 26;                                     //definimos como «entero» pin digital 13 para dar los pasos al servo
int direccion = 27;                               //definimos como «entero» pin digital 9 para dar el sentido de giro
int reset = 25;                                     //definimos como «entero» pin digital 10 para poner en «enable» el motor
int totalpasos = 400;                     //definimos como «entero» totalpasos para completar un avance
                                 


void setup() {
pinMode(pasos, OUTPUT);            //definimos pasos como salida digital
pinMode(direccion, OUTPUT);     //definimos direccion como salida digital
pinMode(reset, OUTPUT);            //definimos reset como salida digital
}

void loop() {

digitalWrite(reset, LOW);             //Mientras reset este en LOW, el motor permanece apagado
delay(2000);                                    //Retardo en la instruccion
digitalWrite(reset, HIGH);           //Cuando reset se encuentre en HIGH el motor arranca
digitalWrite(direccion, HIGH);   //mandamos direccion al servo

for (int i = 0; i<totalpasos; i++)   //Equivale al numero de vueltas (200 pasos son 360º grados de servo )

{
digitalWrite(pasos, HIGH);                // ponemos a high «pasos»
digitalWrite(pasos, LOW);                  // ponemos a low «pasos»
delayMicroseconds(VELOCIDAD);  // leemos la referencia de velocidad
}

//—————————Cambio de sentido de giro——————————–

digitalWrite(reset, LOW);                 //Mientras reset este en LOW, el motor permanece apagado
delay(2000);                                       //Retardo en la instruccion
digitalWrite(reset, HIGH);             //Cuando reset se encuentre en HIGH el motor arranca
digitalWrite(direccion, LOW);      //mandamos direccion al servo

for (int i = 0; i<totalpasos; i++)   //Equivale al numero de vueltas (200 pasos son 360º grados de servo )
{

digitalWrite(pasos, LOW);                     // ponemos a high «pasos»
digitalWrite(pasos, HIGH);                  // ponemos a low «pasos»
delayMicroseconds(VELOCIDAD);   // leemos la referencia de velocidad
}
}
