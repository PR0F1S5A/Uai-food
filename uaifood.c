#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ret é restaurante

//p_r é o apelido dos pretos dos restaurantes

typedef struct pratos_rest{

  int cod_prato;  //codigo do prato
  
  float preco;  //preco do prato
  
  char descri_prato[70]; //descrição do prato com o maximo e 69 caracteres
  
  int cod_res_prato[4]; //codigo do restaurante que o prato pertence
}   p_r;

typedef struct rest{
  
  int cod_rest;  //codigo do restaurante
  
  char nome[50];  //nome do restaurante com o maximo e 49 caracteres
  
  p_r pratos[4];  //vetor de pratos do restaurante com o maximo de 4 pratos
}   r;

int main(){

  int decisao=0, decisao_print=1, printar_rest=0; //variavel para decisão do usuario e olhar se pode printar dentro do while e ver se o restaureante existe

  int menu_opcoes = 0, escolher_pratos = 0; //variavel para decisão do usuario no menu, veriavel de escolher o prato

  int while_n_printar = 1; //para fazer cono un loop enquanto o cliente estiver escolhendo o prato

  int continuar = 1; //ver se dentro ndo switch case vai parara ou não

  int aux_escolher_prato; //auxiliar para escolher o prato
  
  int aux = 0; //olhar a posição do restaurante no vetor de restaurante
  
  r restaurante[3]; //quantidade de restaurantes
  
  printf("**************************************************\n");
  
  printf("uaiFood - Restaurante\n");
  
  printf("**************************************************\n");
  
  for(int i = 0; i < 3; i++){ //recebe os dados dos restaurantes
    
    printf("Cadastre o codigo e nome do restaurante %d\n", i + 1); //mostra qual deve ser o restaurante que estar entrando os dados
    
    scanf("%d", &restaurante[i].cod_rest);  /*receber codigo. PROBLEMA o que fazer quando o cogigo ser o primeiro e depois ver se já tem. Vamos tentar resolver o mais rapido possivel*/  
        
    getchar(); //tirar o \n
    
    scanf("%[^\n]", restaurante[i].nome);  //receber nome
    
    printf("Cadastre codigo do prato, codigo do restaurante, descricao e preco dos pratos do restaurante %s\n", restaurante[i].nome); //printar ações que devem ser feitas
    
    for(int j = 0; j < 4; j++){ //receber pratos dos restaurantes
      
      scanf("%d %d %[^\n]", &restaurante[i].pratos[j].cod_prato, &restaurante[i].pratos[j].cod_res_prato[j], restaurante[i].pratos[j].descri_prato);  //receber codigo do prato

      char *last_space = strrchr(restaurante[i].pratos[j].descri_prato, ' ');
      
      if (last_space != NULL) {
        
      // Convert the part after the last space to a float (the price)
      restaurante[i].pratos[j].preco = atof(last_space + 1);
        
      // Terminate the name string at the last space
      *last_space = '\0';
        
      }

    }

    getchar(); //tirar o \n
    
  }
  
    while(decisao_print == 1){ //ver se vai printar no while as informações iniciais
    printf("LOGIN UAIFOOD RESTAURANTE\n"); //iniciar login

    printf("Digite o código do restaurante (ou um número negativopara sair):\n"); //dar instruções para o usuario

    scanf("%d", &decisao); //receber decisão do usuario
      
    if(decisao >= 0){ //ver se o cliente vai querer sair do programa
      
      decisao_print = 1; //olhar se vai ter desições de login

      printar_rest = 0;
      
      for(int i = 0; i < 3; i++){
        
        if(decisao == restaurante[i].cod_rest){ //ver se o reutante está cadastrado

          printar_rest = 1; //o codigo do restaurante foi encontrado

          aux = i; //guardar a posição do restaurante no vetor de restaurante

          break;
          
        }
      
      }

      while(printar_rest == 1){ //se o restaurante existir

        if(while_n_printar == 1){
        
          printf("%s – Menu de Opções\n\n", restaurante[aux].nome); //printar o nome do restaurante

          printf("1 – Mostrar pratos\n\n");

          printf("0 – Logout\n\n");

          scanf("%d", &menu_opcoes);

        } 
        switch(menu_opcoes){
          
          case 0: //caso for logout a pessoa volta para o inicio do codigo
                continuar = 0;
          break;

          case 1:

          for(int i = 0; i < 4; i++){

            printf("%d - %s - Preco: R$ %.02f\n", restaurante[aux].pratos[i].cod_prato, restaurante[aux].pratos[i].descri_prato, restaurante[aux].pratos[i].preco); 
            
          }
            printf("0 – Voltar ao menu anterior\n");
            
          break;
          
        }

        if(continuar == 1){
        
          scanf("%d", &escolher_pratos); //ver o que o cliente vai querer

          aux_escolher_prato = escolher_pratos - 1; //auxiliar para escolher o prato

          if((escolher_pratos > 0) || (escolher_pratos < 0)){ //printar o prato escolhido

            printf("Codigo do prato: %d\n", restaurante[aux].pratos[aux_escolher_prato].cod_prato);

            printf("Codigo do restaurante: %d\n", restaurante[aux].pratos[aux_escolher_prato].cod_res_prato[aux_escolher_prato]);

            printf("Nome do Prato: %s\n", restaurante[aux].pratos[aux_escolher_prato].descri_prato);

            printf("Preco do prato: R$ %.02f\n", restaurante[aux].pratos[aux_escolher_prato].preco);

            while_n_printar = 0;
          
          }

          if(escolher_pratos == 0){

            while_n_printar = 1;

          }
          
        }

        if(continuar == 0){

          continuar = 1;
          
          break;
          
        }
        
      }

      }

      else{

        decisao_print = 0;

      }
      
      if((printar_rest == 0) && (decisao >= 0)){

      printf("\n\nRestaurante não encontrado. Tente novamente.\n\n");

      }
      
    }
     
  return 0;
  
}