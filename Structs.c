typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int min;
    int seg;
} Date;

typedef struct {
    Date date;
    int cod; // gerar c�digo do produto automaticamente
    char *nome;
    int qtd;
} Produto;