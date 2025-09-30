void pega_emprestado(Livro *x, Livro acervo[]){
    int i;
    for(i = 0; i < 999; i++){
        if(x->nome == acervo[i].nome){
            acervo[i].qnt--;
        }
    }
}
