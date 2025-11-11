
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala* esquerda;
    struct Sala* direita;
} Sala;

Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void explorarSalas(Sala* atual) {
    char escolha;
    if (!atual) return;

    printf("Você está na sala: %s
", atual->nome);
    if (!atual->esquerda && !atual->direita) {
        printf("Esta é uma sala sem caminhos (nó-folha). Fim da exploração.
");
        return;
    }

    while (1) {
        printf("Escolha uma direção: (e) esquerda, (d) direita, (s) sair: ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda) {
            explorarSalas(atual->esquerda);
            break;
        } else if (escolha == 'd' && atual->direita) {
            explorarSalas(atual->direita);
            break;
        } else if (escolha == 's') {
            printf("Saindo da exploração.
");
            break;
        } else {
            printf("Opção inválida ou caminho não existe. Tente novamente.
");
        }
    }
}

int main() {
    // Construção estática da árvore da mansão
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaEsq = criarSala("Biblioteca");
    Sala* salaDir = criarSala("Sala de Música");
    Sala* salaEsqEsq = criarSala("Escritório");
    Sala* salaEsqDir = criarSala("Jardim de Inverno");
    Sala* salaDirEsq = criarSala("Sala de Jantar");
    Sala* salaDirDir = criarSala("Conservatório");

    // Montar a árvore
    hall->esquerda = salaEsq;
    hall->direita = salaDir;

    salaEsq->esquerda = salaEsqEsq;
    salaEsq->direita = salaEsqDir;

    salaDir->esquerda = salaDirEsq;
    salaDir->direita = salaDirDir;

    printf(" Detective Quest - Nível Novato!
");
    explorarSalas(hall);

    // Liberar memória (opcional para programa curto)
    free(salaEsqEsq);
    free(salaEsqDir);
    free(salaDirEsq);
    free(salaDirDir);
    free(salaEsq);
    free(salaDir);
    free(hall);

    return 0;
}