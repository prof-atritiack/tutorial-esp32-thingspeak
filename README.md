
## **Enviando Dados do DOIT ESP32 DEVKIT V1 ao ThingSpeak, utilizando a Arduino IDE**

Este guia apresenta o passo a passo para configurar seu DOIT ESP32 DEVKIT V1 e enviar dados para o ThingSpeak utilizando a biblioteca ThingSpeak. Ideal para iniciantes em projetos de IoT com foco em monitoramento remoto de dados.

---

## Requisitos

- Placa DOIT ESP32 DEVKIT V1
- Cabo micro USB
- Arduino IDE instalada e atualizada
- Conta no [ThingSpeak](https://thingspeak.com/)
- Acesso à internet via Wi-Fi

> ⚠️ É altamente recomendável utilizar uma **rede Wi-Fi própria ou compartilhada via smartphone** (roteador portátil), especialmente durante testes e demonstrações. Isso evita conflitos de rede ou restrições do firewall institucional.
>
> **Importante:** O módulo ESP32 não se conecta a redes de 5G. Se estiver usando um celular como roteador:
> - No **iPhone**, ative a opção **Maximizar Compatibilidade** nas configurações de Acesso Pessoal.
> - No **Android**, certifique-se de que a rede está configurada para **2.4 GHz**, não 5 GHz.

---

## Etapa 1: Configuração da IDE Arduino

> **Observação importante:** Nos computadores do laboratório, as placas ESP32 já estão instaladas na IDE.
> A seção a seguir é útil apenas para instalação em computadores pessoais.
> Se está em um computador já configurado, pule para a seção 1.2.

### 1.1 Instalação da Placa ESP32 (apenas para uso em computadores próprios)

1. Abra a Arduino IDE
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

### 1.2 Configurações Básicas da Arduino IDE

- Ajuste as opções da IDE, no menu File ---> Preferences:
- **Tamanho da Fonte**: escolha um tamanho que facilite a leitura em sala (ex: 14 ou 16)
- Escolha o tema de sua preferência.
- Habilite a opção "Editor Quicks Suggestions".

### 1.3  Seleção da Placa e Porta

- Na Arduino IDE, clique em **"Select Other Board and Port"** na parte superior da tela
- Digite na busca "DEV ou DOIT" e selecione a placa **DOIT ESP32 DEVKIT V1**
- Conecte a placa ao computador via cabo USB (não utilize a extensão, conecte direto na USB)
- Selecione a porta COM correta (geralmente **COM5** nos laboratórios)
- Ajuste a velocidade de comunicação do Serial Monitor (ícone do Serial Monitor, no canto superior direito da tela):
**Velocidade do Monitor Serial**: 115200 bauds
  
---

## Etapa 2: Criar um Canal no ThingSpeak

1. Acesse sua conta em [ThingSpeak](https://thingspeak.com)
2. Vá até **Channels > New Channel**
3. Preencha:
   - **Name**: Envio de Dados ESP32
   - Ative pelo menos os **Field 1** até o **Field 4**
4. Clique em **Save Channel**
5. No menu **API Keys**, copie a **Write API Key**
6. Guarde também o **Channel ID**

---

## Etapa 3: Instalar Bibliotecas

Na Arduino IDE:

1. Clique no ícone do Library Manager (terceiro ícone no menu lateral esquerdo)
2. Instale:
   - **ThingSpeak** (MathWorks)
   - A biblioteca **WiFi** já vem com o pacote do ESP32

---
## Etapa 4: Obter o Código de Exemplo e Carregar na Placa

1. Para facilitar o uso, o código completo já está disponível neste repositório. Para obter uma cópia local, clone o repositório usando a opção disponível nesta página.

2. Localize o arquivo .ino dentro da pasta codigo e abra-o na Arduino IDE.

3. Atualize os dados da rede Wi-Fi e a API Key do seu canal.

4. Atualize também os valores das variáveis a serem enviadas, caso deseje enviar dados reais de sensores.
**Nota:** Os valores utilizados neste exemplo são gerados aleatoriamente. Você pode substituí-los por leituras reais de sensores (ex: temperatura, umidade, luminosidade, etc.).

5. Após atualizar o código, clique em Upload (ícone de seta para a direita) para gravar o firmware na placa DOIT ESP32 DEVKIT V1

6. Aguarde o código ser carregado e a mensagem "Leaving...  Hard Resetting via RTS pin..." aparecer no Output, indicando que o upload foi concluído com sucesso.

7. Abra o Serial Monitor e observe as mensagens.

8. Verifique as postagens sendo atualizadas no menu Private View, no ThingSpeak.

---

## Conclusão

Você aprendeu a conectar o DOIT ESP32 DEVKIT V1 ao Wi-Fi, configurar um canal no ThingSpeak e enviar múltiplos dados utilizando a biblioteca oficial. Essa base permite criar sistemas de monitoramento em tempo real e dashboards para aplicações de IoT.

---

## 🔗 Fontes de Pesquisa e Referências

- [ThingSpeak Documentation - MathWorks](https://www.mathworks.com/help/thingspeak/)
- [Espressif Arduino-ESP32 GitHub](https://github.com/espressif/arduino-esp32)
- [Random Nerd Tutorials – ESP32](https://randomnerdtutorials.com/esp32/)
- [Drivers CP210x - Silicon Labs](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)

---

> 🛠️ **Este tutorial foi gerado com o apoio do ChatGPT, com base em fontes oficiais e experiências práticas em laboratório.**

