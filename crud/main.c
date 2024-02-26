#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _book {
    char            title[100];
    unsigned int    pages;
    float           price;
} Book;

typedef struct _student {
    char            name[100];
    unsigned int    age;
    Book            *favorite_book;
} Student;

Book *create_book(const char *title, unsigned int pages, float price) {
    // Cria uma struct de book na memória heap e retorna o ponteiro
    Book *book = (Book *) calloc(1, sizeof(Book));

    strcpy(book->title, title);
    book->pages = pages;
    book->price = price;

    return book;    // Retorna o ponteiro book
}

/*  Faz a cópia da struct de um livro, criando um novo livro com as mesmas propriedades mas agora
    com endereços diferentes 
 */
Book *copy_book(const Book *book) {
    return create_book(book->title, book->pages, book->price);
}

Student *create_student(const char *name, unsigned int age, const Book *favorite_book) {
    Student *student = (Student *) calloc(1, sizeof(Student));

    strcpy(student->name, name);
    student->age = age;
    student->favorite_book = copy_book(favorite_book);

    return student;
}

unsigned int delete_book(Book **book) {     
    /*  Recebe como parâmetro um ponteiro para ponteiro de book
        Ex: Está recebendo o endereço de book1 que é um ponteiro de book
    */ 

    /*  Tem que ser passado um ponteiro de ponteiro de book, pois até
        daria certo liberar na memória heap a alocação dinânimica
        no entanto, ao setar como NULL a variável na stack, não daria certo porque
        estaria setando como NULL a cópia da variável, sendo assim, a original
        continuaria apontando agora para uma região da memória que foi liberado 
    */

    // O conteúdo de book é o endereço de memória na heap da instância de book
    free(*book);

    // Coloca NULL no endereço de memória da stack que estava apontando para instância de book
    *book = NULL;

    return (*book == NULL);    // 1 se verdadeiro, 0 se falso
}

unsigned int delete_student(Student **student) {
    delete_book((*student)->favorite_book); // Libera a struct de livro primeiro
    free(*student);
    *student = NULL;

    return (*student == NULL);    // 1 se verdadeiro, 0 se falso
}

void print_book(Book *book) {
    puts("");
    printf("Title: %s \n", book->title);
    printf("Pages: %d \n", book->pages);   
    printf("Price: $%.2f \n", book->price);  // .2f porque retorna float com precisão de duas casas decimais
    puts("");
}

void print_student(const Student *student) {
    puts("");
    printf("Student: %s \n", student->name);
    printf("Age: %d \n", student->age);
    puts("");
    print_book(student->favorite_book);
}

int main()
{
    Book *book1 = create_book("The witcher 1", 230, 49.85);
    Student *student = create_student("Thomas Mauro", 22, book1);
    
    print_student(student);

    delete_book(&book1);
    delete_student(&student);
    return 0;
}
