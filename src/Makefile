# == VARIAVEIS ===
# ================
#
# Podemos declarar algumas variaveis dentro do Makefile (sintaxe similar a bash)
# Isso facilita o seu trabalho caso voce opte trocar alguma versao do
# compilador ou flag para seu processo de compilacao
# Uma variavel com nome VAR eh declarada da seguinte maneira:
# 	VAR=conteudo
# e eh chamada atraves do comando $(VAR)

CC=g++ # compilador, troque para gcc se preferir utilizar C
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./tp3.exe # nome do executavel que sera gerado, nao troque
TMPOUT=./tp3.testresult
HEADERS_DIR = ./headers

# === REGRAS =====
# ================
# 
# Aqui declaramos as nossas regras de compilacao.
# Para chamar uma regra, podemos simplesmente digitar
# 	make nome_regra
# Exs.:
# 	make ./tp1
# 	make foo.o
# 	make clean
# Cada regra de compilacao tem a seguinte sintaxe:
#
# NOME_OUTPUT: DEPENDENCIAS
# 	CMD
#
# NOME_OUTPUT eh o nome do arquivo que vai ser gerado (ou qualquer nome caso
# nenhum arquivo seja gerado, ex. clean)
# DEPENDENCIAS sao os nomes dos arquivos necessarios para executar essa regra
# de compilacao
# CMD sao os comandos necessarios para executar a regra (por exemplo, hcamar o
# gcc)


$(EXEC): main.cpp tipoitem.o tipono.o arvorebinaria.o
	$(CC) $(CFLAGS) main.cpp tipoitem.o tipono.o arvorebinaria.o -o $(EXEC)

tipoitem.o: ${HEADERS_DIR}/TipoItem.hpp ${HEADERS_DIR}/TipoItem.cpp 
	$(CC) $(CFLAGS) -c ${HEADERS_DIR}/TipoItem.cpp -o tipoitem.o

tipono.o: ${HEADERS_DIR}/TipoNo.hpp ${HEADERS_DIR}/TipoNo.cpp 
	$(CC) $(CFLAGS) -c ${HEADERS_DIR}/TipoNo.cpp -o tipono.o

arvorebinaria.o: ${HEADERS_DIR}/ArvoreBinaria.hpp  ${HEADERS_DIR}/ArvoreBinaria.cpp 
	$(CC) $(CFLAGS) -c ${HEADERS_DIR}/ArvoreBinaria.cpp -o arvorebinaria.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean: 
	rm -rf tipoitem.o tipono.o arvorebinaria.o

clean_windows:
	del tipoitem.o tipono.o arvorebinaria.o
# === OUTROS =====
# ================
# 
# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
