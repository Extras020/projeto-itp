void cadastra_usuario(Usuario *x, Usuario cadastrados[]){
    int i, pos;
    for(i = 0; i < 1000; i++){
        if(cadastrados[i].nome == '\0'){
            pos = i;
            break;
        }
    }
    printf("digite o nome do usuario:\n");
    fgets(x->nome, MAX, stdin);
    printf("digite o CPF:\n");
    fgets(x->cpf, MAX, stdin);
}
