/*
 NodeMCU Parpadeo/Blink por Dani No www.esploradores.com
 Hace parpadear un LED conectado a la salida D1 (GPIO05) del módulo NodeMCU.
 Este código de ejemplo es de público dominio.
 */

int LED_aparpadear = 5;                 // Definimos la variable y el número del GPIO a conectar el LED a parpadear. 
                                        // Lo hacemos en el encabezado del programa para que 
                                        // sea una variable global, accesible a todo el programa.

void setup() {                          // La función “setup” incializa las configuraciones de 
                                        // los diferentes elementos del programa.
                                        // Únicamente se ejecuta una vez.
  pinMode(LED_aparpadear, OUTPUT);      // Inicializa el LED_aparpadear como una salida.
}

void loop() {                           // La función “loop” se ejecuta una y otra vez, indefinidamente.
  digitalWrite(LED_aparpadear, HIGH);   // Enciende el LED.
  delay(1000);                          // Espera un segundo.
  digitalWrite(LED_aparpadear, LOW);    // Apaga el LED.
  delay(2000);                          // Espera dos segundos.
}
