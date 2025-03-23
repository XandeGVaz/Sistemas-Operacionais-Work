

<h1 align="center">Repositório referente ao trabalho de Sistemas Operacionais</h1>

<div  align="center">
    <img 
        src="./assets/images/QuizImage.jpg"
        width="500px"
    />
</div>

# Membros

- Vitor Alexandre Garcia Vaz
- Pedro Gasparelo Leme
- Gabriel Dezejácomo Maruschi
- Vitor Pardini Saconi
- Matheus Calvalcanti Santana

# Objetivo

Apesar da presença dos sistemas operacionais em praticamente todas as tecnologias digitais, o reconhecimento de sua importância diminuiu à medida que os usuários deixaram de precisar interagir diretamente com o sistema, tornando sua atuação menos perceptível no dia a dia.

Decorrente disso, este projeto tem como objetivo divulgar para a população, de forma didática e acolhedora, a relevância dos sistemas operacionais, destacando seus principais componentes, funcionalidades e impacto na vida cotidiana, dando ênfase nas operações de threads e semáforos.

# Método

Criação de um QUIZ que aborda perguntas sobre sistemas operacionais. Para isso, utilizaremos as seguintes tecnologias:
- C++
- Biblioteca SFML
- Makefile
- Git/GitHub

# Dependências

## Instalação do Compilador g++

O compilador **g++** é necessário para compilar e executar este projeto. Siga as instruções abaixo para instalá-lo no seu sistema:

### Para Linux (Ubuntu/Debian)
1. Atualize os pacotes do sistema:
   ```bash
   sudo apt update
   sudo apt upgrade
   ```

2. Instale o g++:
   ```bash
   sudo apt install g++
   ```

3. Verifique se a instalação foi concluída com sucesso:
   ```bash
   g++ --version
   ```

### Para Windows
1. Baixe o **MinGW** (Minimalist GNU for Windows), que inclui o g++:
   - Acesse o site oficial: [https://sourceforge.net/projects/mingw/](https://sourceforge.net/projects/mingw/).
   - Baixe e instale o MinGW.

2. Durante a instalação, selecione o pacote `g++` no gerenciador de pacotes do MinGW.

3. Adicione o diretório `bin` do MinGW ao PATH do sistema:
   - Vá até as configurações do sistema → Variáveis de Ambiente.
   - Adicione o caminho do diretório `bin` (ex.: `C:\MinGW\bin`) à variável `PATH`.

4. Verifique se o g++ foi instalado corretamente:
   - Abra o terminal (Prompt de Comando ou PowerShell) e execute:
     ```bash
     g++ --version
     ```

### Para macOS
1. Instale o **Xcode Command Line Tools**, que inclui o g++:
   ```bash
   xcode-select --install
   ```

2. Siga as instruções na tela para concluir a instalação.

3. Verifique se o g++ foi instalado corretamente:
   ```bash
   g++ --version
   ```

### Links úteis
- [Documentação oficial do GCC](https://gcc.gnu.org/)
- [MinGW no SourceForge](https://sourceforge.net/projects/mingw/)

Após instalar o g++, você estará pronto para compilar e executar o projeto!

## Instalação da SFML

A biblioteca SFML (Simple and Fast Multimedia Library) é necessária para o funcionamento deste projeto. Siga os passos abaixo para instalá-la no seu sistema:

### Para Linux (Ubuntu/Debian)
1. Atualize os pacotes do sistema:
   ```bash
   sudo apt update
   sudo apt upgrade
   ```

2. Instale a SFML usando o gerenciador de pacotes:
   ```bash
   sudo apt install libsfml-dev
   ```

3. Verifique se a instalação foi concluída com sucesso:
   ```bash
   pkg-config --modversion sfml-all
   ```

### Para Windows
1. Baixe a versão mais recente da SFML no site oficial: [https://www.sfml-dev.org/download.php](https://www.sfml-dev.org/download.php).

2. Extraia os arquivos baixados para um diretório de sua escolha.

3. Configure o compilador (como MinGW ou Visual Studio) para incluir os diretórios `include` e `lib` da SFML.

4. Certifique-se de adicionar as DLLs da SFML ao diretório do executável do seu projeto ou ao PATH do sistema.

### Para macOS
1. Instale o Homebrew, caso ainda não tenha:
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```

2. Instale a SFML usando o Homebrew:
   ```bash
   brew install sfml
   ```

3. Verifique se a instalação foi concluída com sucesso:
   ```bash
   pkg-config --modversion sfml-all
   ```

### Links úteis
- [Documentação oficial da SFML](https://www.sfml-dev.org/documentation/)
- [Tutoriais da SFML](https://www.sfml-dev.org/tutorials/)

Após instalar a SFML, você estará pronto para compilar e executar o projeto!
