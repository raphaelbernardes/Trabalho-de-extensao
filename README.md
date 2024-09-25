# Trabalho-de-extensao

##### Definido como porta padrão 567 ###### 

Importante ressaltar que é um trabalho criado para prova de conceito, varios tratamentos e implementações são necessárias para a correta e segura utilização do mesmo.
Fique a vontade para dar sugestões e ideias.

Para compilar o servidor: 

 `gcc -o server Servidor.c`

Para executar o Cliente: 

`flet run main.py --android` 

Caso não possua o Flet basta instalar: 

`pip install flet`

-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------

Resumo do Trabalho: Otimizando o Atendimento Clínico Presencial com API em C

Objetivo:

O trabalho visou otimizar a coleta de dados em exames médico-legais realizados fora da unidade principal, utilizando uma API em C para integrar os dados coletados em um sistema centralizado.

Problema:

A coleta manual de dados em papel durante exames "in loco" apresentava diversos problemas, como:
* Falta de praticidade: Dificuldade em transportar e armazenar os dados.
* Vulnerabilidade: Os dados estavam sujeitos a danos por fatores climáticos e perda.
* Retrabalho: Os dados precisavam ser digitados manualmente no sistema, gerando erros e consumindo tempo.

Solução:

Foi desenvolvida uma API em C que atua como servidor, recebendo os dados coletados por um aplicativo móvel. O aplicativo, desenvolvido em Python utilizando o framework Flet, permite ao médico legista registrar os dados do exame diretamente no local, de forma mais eficiente e segura.

Benefícios:

* Agilidade: Diminuição do tempo de coleta e registro dos dados.
* Precisão: Redução de erros na transcrição dos dados.
* Segurança: Proteção dos dados contra perda e danos.
* Integração: Facilidade na integração dos dados com o sistema centralizado.

Desenvolvimento:

* Levantamento de requisitos: Foram identificadas as informações essenciais a serem coletadas durante o exame.
* Desenvolvimento da API: A API em C foi desenvolvida para receber os dados do aplicativo móvel e armazená-los em um arquivo.
* Desenvolvimento do aplicativo: Um aplicativo móvel intuitivo foi criado para facilitar a coleta de dados pelo médico legista.
* Integração: A API e o aplicativo foram integrados, permitindo a transmissão dos dados em tempo real.

Resultados:

A solução implementada mostrou-se eficaz em otimizar o processo de coleta de dados, tornando-o mais rápido, preciso e seguro. No entanto, o autor reconhece que há espaço para melhorias, como a implementação de um protocolo de segurança mais robusto e a integração direta com o sistema centralizado.

Conclusão:

O trabalho demonstra o potencial da tecnologia para otimizar processos e melhorar a eficiência em diversos setores, incluindo a área da saúde. A utilização de uma API em C e de um aplicativo móvel permitiu a criação de uma solução simples e eficaz para um problema real.
