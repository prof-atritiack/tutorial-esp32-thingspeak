/****************************************************************************
 * Projeto: Teste de conexão WiFi para ESP32                                *
 * Autor: André Tritiack                                                    *
 * Repositório: https://github.com/prof-atritiack/tutorial-esp32-thingspeak *
 *                                                                          *
 * Este projeto exemplifica como conectar o ESP32 a uma rede Wi-Fi          *
 *                                                                          *
 * Baseado em exemplos oficiais da biblioteca WiFi do Arduino,              *
 * tutoriais da Random Nerd Tutorials, e documentação da Espressif.         *
 ***************************************************************************/

// Biblioteca WiFi para ESP32
#include <WiFi.h>

// Insira as credenciais da rede WiFi:
// Nome da rede (SSID: Service Set Identifier)
#define SSID "INSIRA AQUI O NOME DA SUA REDE WIFI"
// Senha da rede
#define SENHA "INSIRA AQUI SUA SENHA DA REDE WIFI"

// Rotina de configuração (roda apenas uma vez...)
void setup() {
  // Velocidade padrão para monitor serial do ESP32
  Serial.begin(115200);

  Serial.print("Conectando ao Wi-Fi");  

  WiFi.begin(SSID, SENHA);
  while(WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }
  Serial.println("");

  // Imprime o nome da rede, o endereço IP e o MAC Address do módulo:
  Serial.println("Conectado a: " + String(SSID));
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("MAC Address: " + WiFi.macAddress());
}

// Rotina principal (roda ciclicamente...)
void loop() {
  // Nada por aqui...
}