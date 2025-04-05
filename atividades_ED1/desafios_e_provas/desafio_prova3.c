#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char username[50];
	char nome[50];
	char senha[50];
}Usuario;

typedef struct{
	char username[50];
	char conteudo[200];
	int id;
}Posts;

void espera_enter(char *msg); //imprime uma mensagem de erro e espera enter do usuário
FILE *abrir_arquivo(char *nome); //abre ou cria arquivos
int interface_inicio(); //mostra a interface inicial e retorna a escolha do usuário
int procura_usr(FILE *usr, char *alvo); /*procura um usuário de acordo com o username(se encontrar retorna 1 e 
mantém o ponteiro no usuário, senão 0)*/
int novo_usuario(FILE *usr); //cadastra um novo usuário(se cadastrar com sucesso retorna 1, senão 0)
int login(FILE *usr, Usuario *usuario); //interface de login de usuário(se logar retorna 1 e o usuário logado, senao 0)
void interface_principal(FILE *usr, FILE *posts, Usuario usuario); //interface de usuário cadastrado
void novo_post(FILE *posts, Usuario usuario); //cadastra um novo post
int procura_post(FILE *posts, int id); /*procura um posta com base no id
(se encontrar retorna 1 e mantém o ponteiro no alvo, senao retorna 0)*/
void listar_posts(FILE *posts, char *username); //lista todos os posts feitos pelo usuário logado
void print_post(Posts post); //realiza a impressão das informações de um post
void alterar_senha(FILE *usr, char *username); //altera a senha de um usuário

void espera_enter(char *msg){
	printf("%s\nAperte ENTER para continuar\n", msg);
	while(getchar()!='\n');
	while(getchar()!='\n');
}

FILE *abrir_arquivo(char *nome){
	FILE *arq = NULL;
	arq = fopen(nome, "rb+");
	if(!arq)
		arq = fopen(nome, "wb+");
	return arq;
}

int procura_post(FILE *posts, int id){
	Posts temp;
	fseek(posts,0,SEEK_SET);
	do{
		if(fread(&temp,sizeof(Posts),1,posts)){
			if(temp.id==id){
				fseek(posts,-sizeof(Posts),SEEK_CUR);
				return 1;
			}
		}
		else
			return 0;
	}while(1);
}

void novo_post(FILE *posts, Usuario usuario){
	Posts post;
	printf("Digite o conteúdo do post(SAIR para voltar):\n");
	scanf(" %[^\n]s", post.conteudo);
	if(!strcmp("SAIR", post.conteudo))
		return;
	strcpy(post.username,usuario.username);
	
	do{
		int num = rand() % 1000;
		
		if(!procura_post(posts,num)){
			post.id=num;
			fseek(posts,0,SEEK_END);
			if(fwrite(&post,sizeof(Posts),1,posts)){
				fflush(posts);
				espera_enter("Post salvo com sucesso");
			}
			return;
		}
	}while(1);
}

void print_post(Posts post){
	printf("Username: %s\n", post.username);
	printf("ID: %04d\n", post.id);
	printf("Conteúdo: \n%s\n\n", post.conteudo);
}

void listar_posts(FILE *posts, char *username){
	Posts temp;
	fseek(posts,0,SEEK_SET);
	do{
		if(!fread(&temp,sizeof(Posts),1,posts))
			break;
		if(!strcmp(temp.username,username) && temp.id>=0)
			print_post(temp);
	}while(1);
	espera_enter("");
}

void excluir_post(FILE *posts, char *username){
	int id_alvo;
	do{
		printf("Digite o id do post(-1 para sair): ");
		scanf(" %d", &id_alvo);
		if(id_alvo==-1)
			return;
		
		if(procura_post(posts,id_alvo)){
			Posts substituto;
			fread(&substituto,sizeof(Posts),1,posts);
			if(!strcmp(substituto.username,username)){
				fseek(posts,-sizeof(Posts),SEEK_CUR);
				substituto.id=-1;
				fwrite(&substituto,sizeof(Posts),1,posts);
				espera_enter("Post excluído.");
			}
			else
				espera_enter("Esse post pertence a outro usuário");
		}
		else
			espera_enter("post não encontrado");
	}while(1);
}

void alterar_senha(FILE *usr, char *username){
	char nova_senha[50];
	printf("Digite a nova senha: ");
	scanf(" %s", nova_senha);

	Usuario temp;
	procura_usr(usr,username);	
	fread(&temp,sizeof(Usuario),1,usr);
	strcpy(temp.senha,nova_senha);
	fseek(usr,-sizeof(Usuario),SEEK_CUR);
	if(fwrite(&temp,sizeof(Usuario),1,usr)){
		fflush(usr);
		espera_enter("Senha alterada com sucesso");
	}
}

void interface_principal(FILE *usr, FILE *posts, Usuario usuario){
	do{
		system("clear");
		printf("Seja Bem Vindo(a) %s\n\n", usuario.nome);
		printf("4) Novo post\n");
		printf("5) Listar todos os posts\n");
		printf("6) Excluir post\n");
		printf("7) Alterar senha\n");
		printf("8) Logout\n");
		printf("digite: ");
		int escolha;
		scanf(" %d", &escolha);
		
		switch(escolha){
			case 4:
				novo_post(posts, usuario);
				break;
			case 5:
				listar_posts(posts, usuario.username);
				break;
			case 6:
				excluir_post(posts,usuario.username);
				break;
			case 7:
				alterar_senha(usr, usuario.username);
				break;
			case 8:
				return;
			default:
		}
	}while(1);
}

int procura_usr(FILE *usr, char *alvo){
	fseek(usr,0,SEEK_SET);
	Usuario temp;
	
	do{
		if(fread(&temp,sizeof(Usuario),1,usr)){
			if(!strcmp(alvo,temp.username)){
				fseek(usr,-sizeof(Usuario),SEEK_CUR);
				return 1;
			}
		}
		else
			return 0;
	}while(1);
}

int novo_usuario(FILE *usr){
	Usuario new_usr;
	do{
		system("clear");
		printf("=CADASTRO DE USUÁRIO=\n\n");
		printf("Digite o nome de usuário: ");
		scanf(" %s", new_usr.username);
		if(!strcmp(new_usr.username,"SAIR")){
			espera_enter("SAIR não é um username permitido");
			continue;
		}
		
		if(!procura_usr(usr, new_usr.username))
			break;
		else
			espera_enter("nome de usuário em uso. Tente outro.");
	}while(1);
	
	printf("Nome completo: ");
	scanf(" %[^\n]s", new_usr.nome);
	
	printf("Senha: ");
	scanf(" %s", new_usr.senha);
	
	fseek(usr, 0, SEEK_END);
	if(fwrite(&new_usr,sizeof(Usuario),1,usr)){
		fflush(usr);
		return 0;
	}
	return 1;
}

int login(FILE *usr, Usuario *usuario){
	char user[50], senha[50];
	Usuario validador;
	do{
		system("clear");
		printf("Username(SAIR para cancelar): ");
		scanf(" %s", user);
		
		if(!strcmp(user, "SAIR"))
			return 0;
		
		printf("Senha: ");
		scanf(" %s", senha);
		
		if(procura_usr(usr,user)){
			fread(&validador,sizeof(Usuario),1,usr);
			if(!strcmp(validador.senha,senha)){
				*usuario=validador;
				return 1;
			}
		}
		espera_enter("Usuário ou senha inválidos. Tente novamente");
	}while(1);
}

int interface_inicio(){
	system("clear");
	printf("=REDE SOCIAL=\n\n");
	printf("1) Novo usuário\n");
	printf("2) Fazer login\n");
	printf("3) Sair da aplicação\n");
	int escolha;
	printf("Digite: ");
	scanf(" %d", &escolha);
	return escolha;
}

int main(){
	FILE *usr = abrir_arquivo("usuarios.dat");
	FILE *posts = abrir_arquivo("posts.dat");
	if(!usr || !posts)
		return 1;
	
	do{
		Usuario usuario_logado;
		system("clear");
		switch(interface_inicio()){
			case 1: 
				if(novo_usuario(usr))
					return 2;
				break;
			case 2:
				if(login(usr,&usuario_logado))
					interface_principal(usr,posts,usuario_logado);
				break;
			case 3:
				fclose(usr);
				fclose(posts);
				return 0;
			default:
				espera_enter("Opção inválida");
		}
	}while(1);
}

