<h3 align="center">Fundação Centro de Análise, Pesquisa e Inovação Tecnológica - FUCAPI</h3>
<p align="CENTER">
  <a href="https://github.com/dihgab/ElevadorporVoz">
    <img src="https://github.com/dihgab/ElevadorporVoz/blob/main/Default/LogoFU.png" alt="Logo" width="80" height="80">
  </a>
<br />
<p align="center">
  <a href="https://github.com/dihgab/ElevadorporVoz">
    <img src="https://github.com/dihgab/ElevadorporVoz/blob/main/Default/ElevadorImage.jpg" alt="Logo" width="500" height="500">
  </a>

  <h3 align="center">Elevador por Voz</h3>

  <p align="center">
    Projeto Elevador com Arduino com Ênfase no Reconhecimento de Voz
    <br/>
    <a href="#instalação">Instalação</a>
    ·
    <a href="#roadmap">Roadmap</a>
  </p>
</p>


## Sobre o projeto
Neste projeto, desenvolve-se o esquema de ligação e código de um elevador que tem como intuito reconhecer um dado andar solicitado e deslocar-se até este, um projeto que necessita de funções simultâneas entre motor, sensor de posição e botões de localização.

Como sensor base para o reconhecimento de posição do Projeto Elevador Arduino, utilizou-se um Módulo Reed Switch que em conjunto com um imã de neodímio fixado no case de deslocamento tinha a função de identificar o andar em que se encontrava e interagir com os demais componentes do projeto, incluindo o ***Módulo de Reconhecimento de Voz*** que facilita na integração dos PushButtons.

## Instalação
Para fazer a instalação das bibliotecas e ter certeza de que o projeto funcione corretamente, utilize [Arduino IDE](https://www.arduino.cc/en/software).
O projeto utiliza Sketch como gerenciador de dependências padrão. Utilizando Git no Terminal:
```sh
$ git https://github.com/dihgab/ElevadorporVoz
$ cd ElevadorporVoz
$ npm install
```

## Roadmap
Acompanhe o roadmap das próximas features do projeto.

🚀 &nbsp;**Features**: Abaixo estao listadas as features previstas para as próximas releases

| Status | Objetivo | Progresso | Release | 
| :---: | :--- | --- | --- |
| ✔ | Integração com ```<Servo.h>``` para rotação contínua do Servo Motor. | `Concluido`| <a href=https://github.com/dihgab/ElevadorporVoz>alpha_1.0</a> |
| ✔ | Integração com ```<PushButton.h>``` para direcionar-se ao andar desejado.  | `Concluído`| <a href=https://github.com/dihgab/ElevadorporVoz>alpha_1.0</a> |
| 🕒 | Integração com ```<VoiceRecognitionV3.h>``` e ```<SoftwareSerial.h>``` para reconhecimento de voz. | | |
| 🕒 | Integração com ```<DFRobotDFPlayerMini.h>``` para reprodução de áudio correspondente ao andar. | | |

