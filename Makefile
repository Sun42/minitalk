ifeq (${OSTYPE}, FreeBSD)
	CC	=	gcc 
else
	CC	=	/usr/sfw/bin/gcc 
endif
SERV    =       serveur
SRC_SRV =       server.c \
		server_utils.c \
		server_utils2.c \
		server_utils3.c
OBJ_SRV =       $(SRC_SRV:.c=.o)

CLIENT  =       client
SRC_CL  =       client.c \
		client_utils.c
OBJ_CL  =       $(SRC_CL:.c=.o)

TMP     =       $(SRC_SRV:.c=.c~) $(SRC_CL:.c=.c~)

INC     =       -I. -I$(HOME)/rendu/include
CFLAGS  +=      $(INC)

RM      =       rm -f

all     : $(SERV) $(CLIENT)

$(SERV) : $(OBJ_SRV)
	$(CC) -o $(SERV) $(OBJ_SRV) $(LIB)

$(CLIENT) : $(OBJ_CL)
	$(CC) -o $(CLIENT) $(OBJ_CL) $(LIB)

clean   :
	$(RM) $(OBJ_SRV)
	$(RM) $(OBJ_CL)

fclean  : clean
	$(RM) $(SERV)
	$(RM) $(CLIENT)

re      : fclean all

.PHONY  : all clean fclean re
