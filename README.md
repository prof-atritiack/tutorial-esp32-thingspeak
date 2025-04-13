# 📡 Tutorial: Enviando Dados do DOIT ESP32 DEVKIT V1 ao ThingSpeak

Este guia apresenta o passo a passo para configurar seu DOIT ESP32 DEVKIT V1 e enviar dados para o ThingSpeak utilizando a biblioteca ThingSpeak. Ideal para iniciantes em projetos de IoT com foco em monitoramento remoto de dados.

---

## 🧰 Requisitos

- Placa DOIT ESP32 DEVKIT V1
- Cabo micro USB
- Arduino IDE 2 instalada e atualizada
- Conta no [ThingSpeak](https://thingspeak.com/)
- Acesso à internet via Wi-Fi

> ⚠️ É altamente recomendável utilizar uma **rede Wi-Fi própria ou compartilhada via smartphone** (roteador portátil), especialmente durante testes e demonstrações. Isso evita conflitos de rede ou restrições do firewall institucional.
>
> 📶 **Importante:** O módulo ESP32 não se conecta a redes de 5 GHz. Se estiver usando um celular como roteador:
>
> - No **iPhone**, ative a opção **Maximizar Compatibilidade** nas configurações de Acesso Pessoal.
> - No **Android**, certifique-se de que a rede está configurada para **2.4 GHz**, não 5 GHz.

---

## 🛠️ Etapa 1: Configuração da IDE Arduino

> **Observação importante:** Nos computadores do laboratório, as placas ESP32 já estão instaladas na IDE. A seção a seguir é útil apenas para instalação em computadores pessoais.

### 1.1 Instalação da Placa ESP32 (apenas para uso em computadores próprios)

1. Abra a Arduino IDE 2
2. Vá em **File > Preferences**
3. No campo **"Additional Board URLs"**, adicione:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
4. Clique em **OK**
5. Vá até a aba **Boards Manager** (ícone de placa no menu lateral)
6. Busque por **esp32** e instale o pacote da Espressif Systems

> ⚠️ Módulos DOIT ESP32 DEVKIT V1 podem exigir drivers para comunicação USB. Caso sua placa não apareça nas portas disponíveis, instale os drivers CP210x:  
> [Baixar Drivers USB CP210x (Windows)](https://randomnerdtutorials.com/install-esp32-esp8266-usb-drivers-cp210x-windows/#more-148082)

### 1.2 Seleção da Placa, Porta e Configurações Básicas

- Na IDE 2, clique em **"Select Other Board and Port"** na parte inferior direita da tela
- Selecione a placa **DOIT ESP32 DEVKIT V1**
- Conecte a placa ao computador via cabo USB
- Selecione a porta COM correta (geralmente **COM5** nos laboratórios)

Ajuste também as seguintes opções nas configurações rápidas (ícone de engrenagem no Monitor Serial):

- **Velocidade do Monitor Serial**: 115200 bauds
- **Tamanho da Fonte**: escolha um tamanho que facilite a leitura em sala (ex: 14 ou 16)

---

## 🌐 Etapa 2: Criar um Canal no ThingSpeak

1. Acesse sua conta em [ThingSpeak](https://thingspeak.com)
2. Vá até **Channels > New Channel**
3. Preencha:
   - **Name**: Envio de Dados ESP32
   - Ative pelo menos os **Field 1** até o **Field 4**
4. Clique em **Save Channel**
5. No menu **API Keys**, copie a **Write API Key**
6. Guarde também o **Channel ID**

---

## 📥 Etapa 3: Instalar Bibliotecas

Na Arduino IDE:

1. Vá em **Sketch > Incluir Biblioteca > Gerenciar Bibliotecas**
2. Instale:
   - **ThingSpeak** (MathWorks)
   - A biblioteca **WiFi** já vem com o pacote do ESP32

---

## 🧑‍💻 Etapa 4: Código para Envio ao ThingSpeak

```cpp
#include <WiFi.h>
#include <ThingSpeak.h>

// === Configurações de WiFi ===
const char* ssid = "SUA_REDE_WIFI";
const char* password = "SUA_SENHA_WIFI";

// === Configurações do ThingSpeak ===
WiFiClient client;
unsigned long channelID = 1234567; // Substitua pelo seu Channel ID
const char* writeAPIKey = "SUA_API_KEY"; // Substitua pela sua Write API Key

// === Variáveis Globais ===
float valor1;
float valor2;
float valor3;
float valor4;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConectado!");

  // Informações da conexão
  Serial.print("Rede conectada: ");
  Serial.println(WiFi.SSID());
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  Serial.println("Aguardando 2 segundos...");
  delay(2000);

  ThingSpeak.begin(client);
}

void loop() {
  // Geração de dados aleatórios (simulados)
  valor1 = random(100, 500) / 10.0;
  valor2 = random(100, 500) / 10.0;
  valor3 = random(100, 500) / 10.0;
  valor4 = random(100, 500) / 10.0;

  // Envio para os campos do ThingSpeak
  ThingSpeak.setField(1, valor1);
  ThingSpeak.setField(2, valor2);
  ThingSpeak.setField(3, valor3);
  ThingSpeak.setField(4, valor4);

  int status = ThingSpeak.writeFields(channelID, writeAPIKey);

  if (status == 200) {
    Serial.println("Dados enviados com sucesso!");
  } else {
    Serial.print("Erro ao enviar: ");
    Serial.println(status);
  }

  delay(15000); // Delay de 15s para respeitar o limite gratuito do ThingSpeak
}
```

**Nota:** Os valores utilizados neste exemplo são gerados aleatoriamente. Você pode substituí-los por leituras reais de sensores (ex: temperatura, umidade, luminosidade, etc.).

---

## ✅ Conclusão

Você aprendeu a conectar o DOIT ESP32 DEVKIT V1 ao Wi-Fi, configurar um canal no ThingSpeak e enviar múltiplos dados utilizando a biblioteca oficial. Essa base permite criar sistemas de monitoramento em tempo real e dashboards para aplicações de IoT.

---

## 🔗 Fontes de Pesquisa e Referências

- [ThingSpeak Documentation - MathWorks](https://www.mathworks.com/help/thingspeak/)
- [Espressif Arduino-ESP32 GitHub](https://github.com/espressif/arduino-esp32)
- [Random Nerd Tutorials – ESP32](https://randomnerdtutorials.com/esp32/)
- [Drivers CP210x - Silicon Labs](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)

---

> 🛠️ **Este tutorial foi gerado com o apoio do ChatGPT, com base em fontes oficiais e experiências práticas em laboratório.**

