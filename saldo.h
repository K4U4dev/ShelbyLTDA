#ifndef SALDO_H
#define SALDO_H

// Variavel global para armazenar o saldo. Todo o programa usará esse mesmo saldo
// O acesso a esse saldo está sendo feito por funções para evitar erros
double saldo;

// Iniciar o saldo com 0
void new_saldo()
{
    saldo = 0;
}

void saldo_atual(int x, int y)
{
    gotoxy(x, y);
    printf("Saldo atual >>> %.2lf", saldo);
}

void adicionar_dinheiro(double valor)
{
    saldo += valor;
}

void remover_dinheiro(double valor)
{
    saldo -= valor;
}

double getSaldo()
{
    return saldo;
}

int validar_aposta_cavalos(double valor)
{
    if (valor > saldo || valor < 5.0)
    {
        return 0;
    }
    return 1;
}

// Valida a aposta no jogo do bicho
int validar_aposta_bicho(double valor)
{
    if (valor > saldo || valor < 0.25)
    {
        return 0;
    }
    return 1;
}
#endif