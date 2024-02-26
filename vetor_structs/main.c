#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book {
    char            title[100];
    unsigned int    pages;
    float           price;
} Book;

typedef struct _arr_books {
    Book            **books;
    unsigned int    quantity;
} Array_books;

Book *create_book(const char *title, unsigned int pages, float price) {
    // Cria uma struct de book na memória heap e retorna o ponteiro
    Book *book = (Book *) calloc(1, sizeof(Book));

    strcpy(book->title, title);
    book->pages = pages;
    book->price = price;

    return book;    // Retorna o ponteiro book
}

unsigned int delete_book(Book **book) {     
    /*  Recebe como parâmetro um ponteiro para ponteiro de book
        Ex: Está recebendo o endereço de book1 que é um ponteiro de book
    */ 

    /*  Tem que ser passado um ponteiro de ponteiro de book, pois até
        daria certo liberar na memória heap a alocação dinânimica se fosse passado apenas ponteiro de book
        no entanto, ao setar como NULL a variável na stack, não daria certo porque
        estaria setando como NULL a cópia da variável pertecente ao escopo do parâmetro, sendo assim, a original
        continuaria apontando agora para uma região da memória que foi liberado 
    */

    // O conteúdo de book é o endereço de memória na heap da instância de book
    free(*book);

    // Coloca NULL no endereço de memória da stack que estava apontando para instância de book
    *book = NULL;

    return (*book == NULL);    // 1 se verdadeiro, 0 se falso
}

void print_book(Book *book) {
    puts("");
    printf("Title: %s \n", book->title);
    printf("Pages: %d \n", book->pages);   
    printf("Price: $%.2f \n", book->price);  // .2f porque retorna float com precisão de duas casas decimais
    puts("");
}

void print_vector_books(Array_books *arr) {
    puts("");
    for (int i = 0; i < arr->quantity; i++) {
        print_book(arr->books[i]);
    }
    puts("");
}

Array_books *create_vector_books(unsigned int quantity) {
    /*
        Cria na memória heap um struct de Array_books e
        retorna um ponteiro que está apontando para ela
    */
    Array_books *arr = (Array_books *) calloc(1, sizeof(Array_books));

    arr->quantity = quantity;
    arr->books = calloc(quantity, sizeof(Book));
    
    printf("Endereco de arr na funcao = %p \n", &arr);

    /* 
        Neste caso, arr é um ponteiro criado dentro do escopo dessa função,
        quando retornamos arr significa que bookcase está apontando
        para o mesmo endereço que arr está apontando, ao finalizar a função
        a variável arr é destruida e bookcase continua existindo apontando
        para o local correto
    */ 
    return arr;
}

int main()
{   
    Array_books *bookcase = create_vector_books(3);

    bookcase->books[0] = create_book("Livro 1", 56, 5.99);
    bookcase->books[1] = create_book("Livro 2", 560, 99.78);
    bookcase->books[2] = create_book("Livro 3", 120, 56.25);

    print_vector_books(bookcase);
    
    return 0;
}
