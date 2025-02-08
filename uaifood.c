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

typedef struct cadastro_cliente{
  int cod_cliente; //codigo do cliente
  char nome_cliente[50]; //nome do cliente com o maximo de 49 caracteres
} cliente;

typedef struct itens_pedido{
  cliente c; //cliente que fez o pedido
  p_r re; //codigo do restaurante e codigo do prato
  int quant_prato; //quantidade do prato
} pedido;

typedef struct rest{ 
  int cod_rest;  //codigo do restaurante
  char nome[50];  //nome do restaurante com o maximo e 49 caracteres
  p_r pratos[4];  //vetor de pratos do restaurante com o maximo de 4 pratos
}   r;

void printar_Uai_restaurant(){
  printf("**************************************************\n");
  printf("uaiFood - Restaurante\n");
  printf("**************************************************\n");
}

void cadastrar_rest(r *restaurante){
  for(int i = 0; i < 3; i++){ //recebe os dados dos restaurantes
    printf("Cadastre o codigo e nome do restaurante %d\n", i + 1); //mostra qual deve ser o restaurante que estar entrando os dados
    scanf("%d", &restaurante[i].cod_rest); //recber o codigo do restaurante
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
  printf("\n"); //formatação corretamente
}

void cadastrar_cliente(cliente *cliente){
  for(int i = 0; i < 2; i++){
    printf("Cadastre o codigo e nome do cliente %d\n", i + 1);
    scanf("%d", &cliente[i].cod_cliente);  //receber codigo do cliente
    getchar();  //tira o \n
    scanf("%[^\n]", cliente[i].nome_cliente);  //receber nome do cliente
  }
}

int colocar_matriz_em_0(int restaurante_ja_pedidos[][3]){
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 3; j++){
      restaurante_ja_pedidos[i][j] = 0;
    }
  }
  return **restaurante_ja_pedidos;
}

int printar_login(int d){
  printf("\n");
  printf("LOGIN UAIFOOD PEDIDOS\n"); //iniciar login
  printf("Digite o código do cliente (ou um número negativo para sair):\n"); //dar instruções para o usuario
  scanf("%d", &d); //receber decisão do usuario
  return d;
}

int achar_posi_cliente(cliente *cliente, int codigo){
  int aux;
  for(int i = 0; i < 2; i++){
    if(codigo == cliente[i].cod_cliente){ //ver se o cliente esta cadastrado
      aux = i;
      break;
    }
  }
  return aux;
}

int achar_posi_restaurante(r *restaurante, int codigo){
  int aux = codigo;
  aux--;
  return aux;
}

int cliente_vivo(cliente *cliente, int codigo){
  int vivo = 0;
  for(int i = 0; i < 2; i++){
    if(codigo == cliente[i].cod_cliente){ //ver se o cliente esta cadastrado
      vivo = 1;
      break;
    }
  }
  if(vivo == 0){
    printf("\nCliente não encontrado. Tente novamente.\n\n");
  }
  return vivo;
}

int tela_login_user(cliente *cliente, r *restaurante, int posi, int total_rest){
  int opicoes;
  printf("Bem vindo %s - Selecione o restaurante\n\n", cliente[posi].nome_cliente); //printar o nome do cliente
  for(int i = 0; i < total_rest; i++){
    printf("%d - %s\n", i+1, restaurante[i].nome); //printar o nome dos restaurantes
  }
  printf("0 - Fechar o pedido\n"); //printar a opção de sair
  printf("-1 - Logout\n");  //logout do pedido
  scanf("%d", &opicoes);
  printf("\n");
  return opicoes;
}

int switch_ver_rest(r *restaurante, int menu_opicoes){
  int voltar_menu_opcoes;
  int aux = menu_opicoes;
  menu_opicoes++;
  switch(menu_opicoes){
    case -1:
      voltar_menu_opcoes = 0;
    break;
    case 0:
      voltar_menu_opcoes = 0;
    break;
    case 1:
      for(int i = 0; i < 4; i++){
        if(i == 0){
          printf("%s - Pratos - Menu de Opções\n", restaurante[aux].nome);
        }
        printf("%d - %s - Preco: R$ %.02f\n", restaurante[aux].pratos[i].cod_prato, restaurante[aux].pratos[i].descri_prato, restaurante[aux].pratos[i].preco); 
      }
      printf("0 – Fechar pedido\n");
      printf("-1 - Voltar ao menu anterior\n");
      voltar_menu_opcoes = 1; //Fazer voltar para o menu de opções
    break;
    case 2:
      for(int i = 0; i < 4; i++){
        if(i == 0){
          printf("%s - Pratos - Menu de Opções\n", restaurante[aux].nome);
        }
        printf("%d - %s - Preco: R$ %.02f\n", restaurante[aux].pratos[i].cod_prato, restaurante[aux].pratos[i].descri_prato, restaurante[aux].pratos[i].preco); 
      }
      printf("0 – Fechar pedido\n");
      printf("-1 - Voltar ao menu anterior\n");
      voltar_menu_opcoes = 1; //Fazer voltar para o menu de opções
    break;
    case 3:
        for(int i = 0; i < 4; i++){
          if(i == 0){
            printf("%s - Pratos - Menu de Opções\n", restaurante[aux].nome);
          }
          printf("%d - %s - Preco: R$ %.02f\n", restaurante[aux].pratos[i].cod_prato, restaurante[aux].pratos[i].descri_prato, restaurante[aux].pratos[i].preco); 
        }
        printf("0 – Fechar pedido\n");
        printf("-1 - Voltar ao menu anterior\n");
      voltar_menu_opcoes= 1;
        break;
  }
  return voltar_menu_opcoes;
}

int quant_pedidos(pedido *pedido, r *restaurante, int *total_pedidos, int *quant_pedidos_total, int menu_opcoes, int escolher_pratos, int aux){
  int quant_pedida;
  quant_pedidos_total[aux]++;
  printf("%s R$ %.02f. Qual quantidade?\n", restaurante[menu_opcoes].pratos[escolher_pratos].descri_prato,restaurante[menu_opcoes].pratos[escolher_pratos].preco);
  scanf("%d", &quant_pedida);
  return quant_pedida;
}

int alocar_pedido_do_cliente(pedido *pedido_cliente, int *quantidade, int a, int c){
  int total = 0;
  for(int i = 0; i < c; i++){
    total = total + quantidade[i];
  }
  if(a==0) pedido_cliente=malloc(sizeof(pedido)*total);
  else pedido_cliente = realloc(pedido_cliente, total);
  if(pedido_cliente == NULL){
    printf("Erro ao alocar memória\n");
    return 1;
  }
  else return 0;
}

void resumos_pedidos(pedido *pedido_cliente, int *quant_pedidos_total, int aux, cliente *cliente, r *restaurante, int menu_opcoes, int total_rest, int restaurante_ja_pedidos[][total_rest]){
  int taxa = 1;
  int contar_taxa = 1;
  int posi_ja_foi = 0;
  int total_printar = 0;
  printf("\n");
  printf("**************************************************\n");
  printf("Resumo do pedido - %s\n", cliente[aux].nome_cliente);
  printf("**************************************************\n");
  for(int i = quant_pedidos_total[aux]; i >= 0; i--){
    printf("%s", restaurante[pedido_cliente[quant_pedidos_total[aux]-i].re.cod_res_prato[0]].nome);
    printf("%dx %s = R$ %02.f\n", pedido_cliente[quant_pedidos_total[aux]-i].quant_prato, pedido_cliente[quant_pedidos_total[aux]-i].re.descri_prato, pedido_cliente[quant_pedidos_total[aux]-i].re.preco*pedido_cliente[quant_pedidos_total[aux]-i].quant_prato);
    total_printar = total_printar + (pedido_cliente[quant_pedidos_total[aux]-i].re.preco*pedido_cliente[quant_pedidos_total[aux]-i].quant_prato);
  }
  for(int i = 0; i < total_rest; i++){
    contar_taxa=1;
    if(pedido_cliente[quant_pedidos_total[aux]-i].re.cod_res_prato[0] != restaurante[pedido_cliente[quant_pedidos_total[aux]-i].re.cod_res_prato[0]].cod_rest){
      for(int k = 0; k < total_rest; k++){
        if(restaurante_ja_pedidos[aux][k] == pedido_cliente[quant_pedidos_total[aux]-k].re.cod_res_prato[0]){
          contar_taxa = 0;
        }
      }
      if(contar_taxa == 1){
        taxa++;
        restaurante_ja_pedidos[aux][posi_ja_foi] = pedido_cliente[quant_pedidos_total[aux]-i].re.cod_res_prato[0];
        posi_ja_foi++;
      }
    }
  }
  printf("Taxa de entrega x %d", taxa);
  float total_pedido = taxa + total_printar;
  printf("---------------------------------------------------------------------\n");
  printf("TOTAL DO PEDIDO = %.02f\n", total_pedido);
  printf("Selecione a forma de pagamento\n1 – Pix\n2 - Dinheiro\n3 – Cartao de Credito\n4 – Cartao de Debito");
  int pagamento = 0;
  scanf("%d", &pagamento);
  quant_pedidos_total[aux] = 0;
}

int main(){
  int decisao=0, cliente_existe=0; //variavel que recebe a decisão no login, e a outa serve para ver se o cliente existe
  int aux_quantida_pedidos;  //
  int fechar_pedido=0;  //variavel para fechar o pedido fechar_pedido = 0 não fecha o pedido
  int menu_opcoes=0, escolher_pratos=0; //variavel para decisão do usuario no menu, veriavel de escolher o prato
  int voltar_menu_opcoes=1; /*ver se vai volter para o menu de opções voltar_menu_opcoes = 0 nao volta, voltar_menu_opcoes = 1 volta*/
  int logout=0; //ver se a pessoa quer fazer o logout logout = 0 não logout = 1 logout
  int aux=0; //olhar a posição do vetor de pratos do restaurante
  r restaurante[3]; //quantidade de restaurantes
  cliente cliente[2]; //quantidade de clientes
  pedido *pedido_cliente; //vetor de pedidos do cliente
  int quant_pedidos_total[2]={0};
  int malloc_ou_realloc=0;  //ver se vai ser malloc(primeira vez) ou realloc(segunda vez ou demais vezes)
  int total_clientes=2;  //quantidade total de clientes
  int total_rest=3;  //quantidade total de restaurantes
  int taxa_entrega[total_clientes]; /*cada cliente tera uma posição no vetor para ver quantas taxas de entrga vai ter*/
  int restaurante_ja_pedidos[total_clientes][total_rest]; //matriz para ver se o cliente ja pediu no restaurante
  int printar_login_main=1;  //printar login = 1, printa o inicio do login; login = 0, não printa o inicio do login
  int decisao_prato;  //Ver qual prato escolhido pelo cliente
  
  printar_Uai_restaurant();
  cadastrar_rest(restaurante);  //cadastrar restaurantes
  cadastrar_cliente(cliente);  //cadastrar clientes
  **restaurante_ja_pedidos = colocar_matriz_em_0(restaurante_ja_pedidos);

  while(1){ //ver se vai printar no while as informações iniciais
    if(printar_login_main == 1){
      logout = 0;
      fechar_pedido = 0;
      decisao=printar_login(decisao);
    }
    if(decisao >= 0){ //ver se o cliente vai querer sair do programa
      if(printar_login_main == 1){
        cliente_existe = 0; //olhar se vai printar o cliente existe
        aux = achar_posi_cliente(cliente, decisao);
        cliente_existe = cliente_vivo(cliente, decisao);
      }  
      while(cliente_existe == 1){ //se o restaurante existir
        if((voltar_menu_opcoes == 1) && (printar_login_main == 1)){
          menu_opcoes = tela_login_user(cliente, restaurante, aux, total_rest);
          cliente_existe = 0;
        }
        if(menu_opcoes == -1){
          logout = 1;
        }
        if(menu_opcoes == 0){
          fechar_pedido = 1;
        }
        else{
          if(printar_login_main == 1){
            menu_opcoes--; //subtrair 1 para acessar o vetor
            voltar_menu_opcoes = switch_ver_rest(restaurante, menu_opcoes);
          }
        }  
        if((voltar_menu_opcoes == 1) && ((logout == 0) && (fechar_pedido == 0)) && (printar_login_main == 1)){
          scanf("%d", &escolher_pratos); //ver o que o cliente vai querer
          if(escolher_pratos >= 0){
            printar_login_main=0;
            escolher_pratos = escolher_pratos - 1;
            aux_quantida_pedidos = quant_pedidos(pedido_cliente, restaurante, quant_pedidos_total, quant_pedidos_total, menu_opcoes, escolher_pratos, aux);
            alocar_pedido_do_cliente(pedido_cliente, quant_pedidos_total, malloc_ou_realloc, total_clientes);
            malloc_ou_realloc++;
            for(int i = 0; i < quant_pedidos_total[aux]; i++){
              pedido_cliente[i].quant_prato = quant_pedidos_total[aux];
              pedido_cliente[i].re.cod_res_prato[0] = restaurante[menu_opcoes].cod_rest;
            }
          }
          else{
            printar_login_main=1;
          }
          voltar_menu_opcoes = 1;
        }
        voltar_menu_opcoes=1;
        menu_opcoes = menu_opcoes + 1;
        if(((menu_opcoes == 0) || (escolher_pratos == 0)) && ((logout == 0) && (fechar_pedido == 0)) && (quant_pedidos_total[aux] > 0) && (printar_login_main == 1)){
          voltar_menu_opcoes = 1;
          menu_opcoes--;
          resumos_pedidos(pedido_cliente, quant_pedidos_total, aux, cliente, restaurante, menu_opcoes, total_rest, restaurante_ja_pedidos);
          printar_login_main=1;
        }
      } 
    }
    else{
      break;
    }
  }
  free(pedido_cliente);
  return 0;
}