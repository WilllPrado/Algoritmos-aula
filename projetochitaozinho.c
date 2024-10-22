#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERNAME_LEN 30
#define PASSWORD_LEN 30

typedef struct {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

User users[MAX_USERS];
int userCount = 0;

void cadastrarUsuario() {
    if (userCount >= MAX_USERS) {
        printf("Limite de usuários atingido!\n");
        return;
    }

    User newUser;
    printf("Digite o nome de usuário: ");
    scanf("%s", newUser.username);
    printf("Digite a senha: ");
    scanf("%s", newUser.password);

    users[userCount++] = newUser;
    printf("Usuário cadastrado com sucesso!\n");
}

void alterarSenha() {
    char username[USERNAME_LEN];
    char newPassword[PASSWORD_LEN];
    int found = 0;

    printf("Digite o nome de usuário: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            printf("Digite a nova senha: ");
            scanf("%s", newPassword);
            strcpy(users[i].password, newPassword);
            printf("Senha alterada com sucesso!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Usuário não encontrado!\n");
    }
}

void realizarLogin() {
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
    int found = 0;

    printf("Digite o nome de usuário: ");
    scanf("%s", username);
    printf("Digite a senha: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login realizado com sucesso!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Nome de usuário ou senha incorretos!\n");
    }
}

void excluirUsuario() {
    char username[USERNAME_LEN];
    int found = 0;

    printf("Digite o nome de usuário a ser excluído: ");
    scanf("%s", username);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            // Move todos os usuários para a esquerda para preencher o espaço
            for (int j = i; j < userCount - 1; j++) {
                users[j] = users[j + 1];
            }
            userCount--;
            printf("Usuário excluído com sucesso!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Usuário não encontrado!\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\nMenu de Opções:\n");
        printf("1. Cadastrar Usuário\n");
        printf("2. Alterar Senha\n");
        printf("3. Realizar Login\n");
        printf("4. Excluir Usuário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                alterarSenha();
                break;
            case 3:
                realizarLogin();
                break;
            case 4:
                excluirUsuario();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}