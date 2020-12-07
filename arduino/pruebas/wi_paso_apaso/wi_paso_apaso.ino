/*
  Quiz numro #2
  Realizado por:Ibio Antonio Escobar Gomez
  Profesor: Ing. Hernando Vanegas Lopez
  Fecha Inicio: 13/11/2020
  Fecha Fin: 20/11/2020
*/
#include <WiFi.h>
#define VELOCIDAD 1500    //velocidad de giro del motor, cuanto menos valor + velocidad
//Configuración de red
const char* ssid     = "Family EP";
const char* password = "jhulian0513";
WiFiServer server(80); //Servidor web
int pasos = 26;                                     //definimos como «entero» pin digital 13 para dar los pasos al servo
int direccion = 27;                               //definimos como «entero» pin digital 9 para dar el sentido de giro
int reset = 25;                                     //definimos como «entero» pin digital 10 para poner en «enable» el motor
int totalpasos = 2400;                     //definimos como «entero» totalpasos para completar un avance
//Variables Cliente
char linebuf[80];
int charcount = 0;
void motor_paso()
{
  digitalWrite(reset, LOW);                 //Mientras reset este en LOW, el motor permanece apagado
  delay(2000);                                       //Retardo en la instruccion
  digitalWrite(reset, HIGH);             //Cuando reset se encuentre en HIGH el motor arranca
  digitalWrite(direccion, LOW);      //mandamos direccion al servo
  for (int i = 0; i < totalpasos; i++) //Equivale al numero de vueltas (200 pasos son 360º grados de servo )
  {
    digitalWrite(pasos, LOW);                     // ponemos a high «pasos»
    digitalWrite(pasos, HIGH);                  // ponemos a low «pasos»
    delayMicroseconds(VELOCIDAD);   // leemos la referencia de velocidad
  }
  digitalWrite(reset, LOW);             //Mientras reset este en LOW, el motor permanece apagado
  delay(2000);                                    //Retardo en la instruccion
  digitalWrite(reset, HIGH);           //Cuando reset se encuentre en HIGH el motor arranca
  digitalWrite(direccion, HIGH);   //mandamos direccion al servo
  //—————————Cambio de sentido de giro——————————–
  for (int i = 0; i < totalpasos; i++) //Equivale al numero de vueltas (200 pasos son 360º grados de servo )
  {
    digitalWrite(pasos, HIGH);                // ponemos a high «pasos»
    digitalWrite(pasos, LOW);                  // ponemos a low «pasos»
    delayMicroseconds(VELOCIDAD);  // leemos la referencia de velocidad
  }
}
void setup() {
  //Inicializamos el puerto sere
  Serial.begin(115200);

  //Configuramos los pines como salida.
  pinMode(pasos, OUTPUT);            //definimos pasos como salida digital
  pinMode(direccion, OUTPUT);     //definimos direccion como salida digital
  pinMode(reset, OUTPUT);            //definimos reset como salida digital
  Serial.printf("Conectando a: %s\n", ssid);
  WiFi.begin(ssid, password);
  // Intentamos que se conecte a la red wifi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conectando...");
    delay(2000);
  }
  Serial.print("Conectado.  ");
  Serial.print(" Dirección IP del módulo: ");
  Serial.println(WiFi.localIP());
  server.begin(); //Iniciamos el servidor web.
}
void loop() {
  // Esperamos a que se conecte un cliente
  WiFiClient client = server.available();
  if (client) {
    Serial.println("Nuevo Cliente");
    memset(linebuf, 0, sizeof(linebuf));
    charcount = 0;
    // Una petición http termina con línea en blanco.
    boolean currentLineIsBlank = true;
    while (client.connected()) {  //Mientras que el cliente está conectado
      if (client.available()) {   //Si se recibe algun dato del cliente.
        char c = client.read();
        Serial.write(c);
        //Lee caracter por caracter la petición http
        linebuf[charcount] = c;
        if (charcount < sizeof(linebuf) - 1) charcount++;
        // si se recibe un caracter de nueva línea (/n) y la siguiente línea
        // es una líne en blanco entonces la petición http ha terminado y podemos
        // responder al cliente
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println();
          client.println("<!DOCTYPE HTML><html><head>");
          client.println("<body style=\"background-color:#0066aa;\">");
          client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"></head>");
          client.println("<h1 style=\"width:500px;height:20px;color:#ffffff;\"> Web Server ESP32 </h1>");
          client.println("<h2 style=\"width:500px;height:20px;color:#ffffff;\">Quiz numro #2</h2>");
          client.println("<h2 style=\"width:500px;height:20px;color:#ffffff;\"> Realizado por:Ibio Antonio Escobar Gomez </h2>");
          client.println("<h2 style=\"width:500px;height:20px;color:#ffffff;\">Profesor: Ing. Hernando Vanegas Lopez</h2>");
          client.println("<p style=\"color:#ffffff\">Mot #1 <a href=\"on1\"><button>ON</button></a>&nbsp;<a href=\"off1\"><button>OFF</button></a></p>");
         // client.println("<p style=\"color:#ffffff\">Mot #2 <a href=\"on2\"><button>ON</button></a>&nbsp;<a href=\"off2\"><button>OFF</button></a></p>");
          client.println("</html>");
          break;
        }

        if (c == '\n') {
          // Empieza una nueva línea
          currentLineIsBlank = true;
          if (strstr(linebuf, "GET /on1") > 0) {
            Serial.println("LED 1 ON");
            motor_paso();
          }
          else if (strstr(linebuf, "GET /off1") > 0 and LOW) {
            Serial.println("LED 1 OFF");
          }
//          else if (strstr(linebuf, "GET /on2") > 0 and HIGH) {
//            Serial.println("LED 2 ON");
//          }
//          else if (strstr(linebuf, "GET /off2") > 0 and LOW) {  
//            Serial.println("LED 2 OFF");
//          }
          // Empieza una nueva línea
          currentLineIsBlank = true;
          memset(linebuf, 0, sizeof(linebuf));
          charcount = 0;
        } else if (c != '\r') {
          // Todavía queda un caracter en la línea actual
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);  // Esperamos un poco para que el navegador reciba los datos.
    // Cerramos la conexión con el cliente
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
