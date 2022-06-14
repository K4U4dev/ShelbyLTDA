#ifndef _BICHOS_H
#define _BICHOS_H

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "saldo.h"
#include "desenhos.h"
#include "marca.h"
#include <time.h>

int cut_cent();
int cut_dez();
int def_grupo();
void ehobixo();
void sorteio(int resultado[]);
void printar_res(int resultado[]);
void bilhete(int x, int y, int resultado[]);
char bichos[25][15];
void tela_cotacao();
void data_hora(int x, int y, int opcao);


/*Olá! Bem vindo ao código desenvolvido pela Shelby.ltda
Coisas q podem parecer confusas podem ficar mais simples
compilando e indo na área de ajuda.
*/


int jogo_do_bicho()
//funçao principal do jogo do bicho.
{
    clrscr();
    textcolor(BROWN);

    ehobixo();
    int a, numero, resultado[5], premio[4], bicho[24];
    double valor;
    double valor_premio;
    int qual_premio;
    int menux;
    int menuy;

    while (1)
    {
        desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
        logo_bicho(2, 4);
        saldo_atual(3, 11);
        int bloco02x = 11, bloco02y = 14;
        gotoxy(bloco02x, bloco02y);
        printf("Apostar");
        gotoxy(bloco02x, bloco02y + 1);
        printf("Ajuda");
        gotoxy(bloco02x, bloco02y + 2);
        printf("Origem");
        gotoxy(bloco02x, bloco02y + 3);
        printf("Retroceder");
        int opcao01 = selecionar_opcao(bloco02x - 3, bloco02y, 4);
        switch (opcao01)
        {
        case 1:
            //area de apostas do jogo
            menux = 6, menuy = 14;

            // Desenha todo o background
            clrscr();
            textcolor(BROWN);
            desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
            logo_bicho(2, 4);
            saldo_atual(3, 11);

            int bloco01x = 9;
            int bloco01y = 14;
            gotoxy(bloco01x, bloco01y++);
            printf("Selecione a opcao: ");
            gotoxy(bloco01x + 4, bloco01y++);
            printf("Milhar");
            gotoxy(bloco01x + 4, bloco01y++);
            printf("Centena");
            gotoxy(bloco01x + 4, bloco01y++);
            printf("Bolinho");
            gotoxy(bloco01x + 4, bloco01y++);
            printf("Retroceder");
            int opcao = selecionar_opcao(bloco01x, bloco01y - 4, 4);

            switch (opcao)
            {
            case 1:
                // aposta tipo milhar
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                saldo_atual(3, 11);
                gotoxy(menux, menuy);
                printf("Digite a milhar: ");
                gotoxy(menux, menuy + 2);
                scanf("%d", &numero);

                do
                {
                    clrscr();
                    textcolor(BROWN);
                    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                    logo_bicho(2, 4);
                    saldo_atual(3, 11);
                    gotoxy(menux, menuy);
                    printf("Digite o valor da aposta: ");
                    gotoxy(menux, menuy + 2);
                    scanf("%lf", &valor);
                } while (!validar_aposta_bicho(valor));
                #ifdef __MINGW32__
                fflush(stdin);
                #else
                __fpurge(stdin);
                #endif
                remover_dinheiro(valor);

                sorteio(resultado);

                do
                {
                    clrscr();
                    textcolor(BROWN);
                    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                    logo_bicho(2, 4);
                    saldo_atual(3, 11);
                    gotoxy(menux, menuy);
                    printf("Selecione qual premio jogar");
                    gotoxy(menux + 2, menuy + 2);
                    printf("1- Primeiro premio");
                    gotoxy(menux + 2, menuy + 3);
                    printf("2- Primeiro ao quinto");
                    qual_premio = selecionar_opcao(menux, menuy + 2, 2);

                } while ((qual_premio > 2 && qual_premio < 1));

                clrscr();
                desenhar_quadrado(39, 23, 1, 1);
                bilhete(2, 2, resultado);
                gotoxy(43, 7);
                printf("RESULTADOS");
                desenhar_quadrado(39, 10, 41, 8);

                int posy = 10;
                int ganhou = 0;
                //aposta comparada no 1 premio
                if (qual_premio == 1)
                {
                    if (numero == resultado[0])
                    {
                        adicionar_dinheiro(valor * 100);
                        gotoxy(43, 12);
                        printf("Voce acertou o 1° premio");
                        gotoxy(43, 13);
                        printf("Premio: R$ %.2lf\n", valor * 100);
                    }
                    else
                    {
                        gotoxy(43, 13);
                        printf("Lamentável! Voce perdeu.\n");
                    }
                }
                //aposta para 1ao5
                else
                {
                    int ganhou = 0;
                    int posy = 10;

                        for (int i = 0; i < 5 ; i++)
                        {
                            if (numero == resultado[i])
                            {
                                gotoxy(43, posy);
                                printf("Voce acertou o %d° premio.", i + 1);
                                valor_premio += valor * 20;
                                adicionar_dinheiro(valor_premio);
                                ganhou = 1;
                                posy++;
                            }
                        }

                        if (!ganhou)
                        {
                            gotoxy(43, 13);
                            printf("Lamentável! Voce perdeu.\n");
                        }
                        else
                        {
                            gotoxy(43, 16);
                            printf("PREMIO >> %.2lf\n", valor_premio);
                        }
                }
                preencher_com_espacos(80, 1, 1, 24);
                gotoxy(15, 24);
                pausa();
                return 0;;

            case 2:
                //aposta tipo centena
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                saldo_atual(3, 11);
                gotoxy(menux, menuy);
                printf("Digite a centena: ");
                gotoxy(menux, menuy + 2);
                scanf("%i", &numero);

                do
                {
                    clrscr();
                    textcolor(BROWN);
                    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                    logo_bicho(2, 4);
                    saldo_atual(3, 11);
                    gotoxy(menux, menuy);
                    printf("Digite o valor da aposta: ");
                    gotoxy(menux, menuy + 2);
                    scanf("%lf", &valor);
                } while (!validar_aposta_bicho(valor));
                #ifdef __MINGW32__
                fflush(stdin);
                #else
                __fpurge(stdin);
                #endif
                remover_dinheiro(valor);

                sorteio(resultado);

                do
                {
                    clrscr();
                    textcolor(BROWN);
                    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                    logo_bicho(2, 4);
                    saldo_atual(3, 11);
                    gotoxy(menux, menuy);
                    printf("Selecione qual premio jogar");
                    gotoxy(menux + 2, menuy + 2);
                    printf("1- Primeiro premio");
                    gotoxy(menux + 2, menuy + 3);
                    printf("2- Primeiro ao quinto");
                    qual_premio = selecionar_opcao(menux, menuy + 2, 2);

                } while ((qual_premio > 2 && qual_premio < 1));

                clrscr();
                desenhar_quadrado(39, 23, 1, 1);
                bilhete(2, 2, resultado);
                gotoxy(43, 7);
                printf("RESULTADOS");
                desenhar_quadrado(39, 10, 41, 8);

                valor_premio = 0;
                //compara o 1º premio a centena apostada
                if (qual_premio == 1)
                {
                    if (numero == cut_cent(resultado[0]))
                    {
                        adicionar_dinheiro(valor * 100);
                        gotoxy(43, 12);
                        printf("Voce acertou o 1°  premio");
                        gotoxy(43, 13);
                        printf("Premio: R$ %.2lf\n", valor * 100);
                    }
                    else
                    {
                        gotoxy(43, 13);
                        printf("Lamentável! Voce perdeu.\n");
                    }
                }

                else
                //compara os 5 prêmios a centena apostada
                {
                    int ganhou = 0;
                    int posy = 10;
                    for (int i = 0; i < 5; i++)
                    {
                        if (numero == cut_cent(resultado[i]))
                        {
                            gotoxy(43, posy);
                            printf("Voce acertou o %d° premio.", i + 1);
                            valor_premio += valor * 20;
                            adicionar_dinheiro(valor_premio);
                            ganhou = 1;
                            posy++;
                        }
                    }

                    if (!ganhou)
                    {
                        gotoxy(43, 13);
                        printf("Lamentável! Voce perdeu.\n");
                    }
                    else
                    {
                        gotoxy(43, 16);
                        printf("PREMIO >> %.2lf\n", valor_premio);
                    }
                }
                preencher_com_espacos(80, 1, 1, 24);
                gotoxy(15, 24);
                pausa();
                return 0;

            case 3:
                // aposta tipo Bolinho
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                saldo_atual(3, 11);
                gotoxy(menux, menuy);
                printf("Digite o número do bicho: ");
                gotoxy(menux, menuy + 2);
                scanf("%i", &numero);

                do
                {
                    clrscr();
                    textcolor(BROWN);
                    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                    logo_bicho(2, 4);
                    saldo_atual(3, 11);
                    gotoxy(menux, menuy);
                    printf("Digite o valor da aposta: ");
                    gotoxy(menux, menuy + 2);
                    scanf("%lf", &valor);
                } while (!validar_aposta_bicho(valor));
                remover_dinheiro(valor);
                #ifdef __MINGW32__
                fflush(stdin);
                #else
                __fpurge(stdin);
                #endif

                sorteio(resultado);

                do
                {
                    clrscr();
                    textcolor(BROWN);
                    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                    logo_bicho(2, 4);
                    saldo_atual(3, 11);
                    gotoxy(menux, menuy);
                    printf("Selecione qual premio jogar\n");
                    gotoxy(menux + 2, menuy + 2);
                    printf("1- Primeiro premio");
                    gotoxy(menux + 2, menuy + 3);
                    printf("2- Primeiro ao quinto");
                    qual_premio = selecionar_opcao(menux, menuy + 2, 2);

                } while ((qual_premio > 2 && qual_premio < 1));

                clrscr();
                desenhar_quadrado(39, 23, 1, 1);
                bilhete(2, 2, resultado);
                gotoxy(43, 7);
                printf("RESULTADOS");
                desenhar_quadrado(39, 10, 41, 8);

                valor_premio = 0;
                //Compara o grupo(bolinho) do 1º Prêmio com sua aposta
                if (qual_premio == 1)
                {
                    if (numero == def_grupo(resultado[0]))
                    {
                        adicionar_dinheiro(valor * 20);
                        gotoxy(45, 15);
                        printf("Voce acertou o 1°  premio");
                        gotoxy(45, 16);
                        printf("Premio: R$%.2lf\n", valor * 20);
                    }
                    else
                    {
                        gotoxy(43, 13);
                        printf("Lamentável! Voce perdeu.\n");
                    }
                }
                // campara os 5 grupo(bolinho) com sua aposta
                else
                {
                    int ganhou = 0;
                    int posy = 10;
                    for (int i = 0; i < 5; i++)
                    {
                        if (numero == def_grupo(resultado[i]))
                        {
                            gotoxy(45, posy);
                            printf("Voce acertou o %d° premio", i + 1);
                            adicionar_dinheiro(valor * 4);
                            ganhou = 1;
                            valor_premio += valor * 4;
                            posy++;
                        }
                    }

                    if (!ganhou)
                    {
                        gotoxy(43, 13);
                        printf("Lamentável! Voce perdeu.\n");
                    }
                    else
                    {
                        gotoxy(45, 15);
                        printf("Premio: R$ %.2lf\n", valor_premio);
                    }
                }

                preencher_com_espacos(80, 1, 1, 24);
                gotoxy(15, 24);
                pausa();
                //Após a aposta, voltaremos para a tela inicial
                return 0;

            case 4:
                break;
            }

            break;

        case 2:
            //area de ajuda para uma maior compeensão do usuário sobre o jogo.
            clrscr();
            textcolor(BROWN);
            desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
            logo_bicho(2, 4);
            int menu01x = 10, menu01y = 11;
            gotoxy(menu01x - 3, menu01y);
            printf("Aprendendo a jogar");
            gotoxy(menu01x, menu01y + 1);
            printf("O que é MILHAR?");
            gotoxy(menu01x, menu01y + 2);
            printf("O que é CENTENA?");
            gotoxy(menu01x, menu01y + 3);
            printf("O que é BOLINHO?");
            gotoxy(menu01x, menu01y + 4);
            printf("O que é 1° Premio e 1° ao 5°?");
            gotoxy(menu01x, menu01y + 5);
            printf("Qual a cotação do prêmio por jogo?");
            gotoxy(menu01x, menu01y + 6);
            printf("Como ter um bom palpite?");
            gotoxy(menu01x, menu01y + 7);
            printf("Retroceder");
            int op = selecionar_opcao(menu01x - 3, menu01y + 1, 7);
            switch (op)
            {
            case 1:
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                gotoxy(5, 11);
                printf("O que é uma aposta na milhar?");
                gotoxy(3, 13);
                printf("Uma aposta no milhar significa apostar com 4 dígitos sendo comparados no\n");
                gotoxy(3, 14);
                printf("resultado. Você deve escolher um número de 0 até 9999. Para números menores\n");
                gotoxy(3, 15);
                printf("que 1000 digite sem o zero na frente. ex. aposta-se em 321 no milhar e\n");
                gotoxy(3, 16);
                printf("\n");
                gotoxy(3, 17);
                printf("Exemplo: Aposta-se em 321 no milhar e no resultado será 0321.");
                gotoxy(3, 23);
                printf("Próximo");
                pausa();
                break;
            case 2:
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                gotoxy(5, 11);
                printf("O que é uma aposta na centena?");
                gotoxy(3, 13);
                printf("Uma aposta na centena significa apostar com 3 dígitos sendo comparado no\n");
                gotoxy(3, 14);
                printf("resultado. Você deve escolher um número de 0 até 999. Para números menores \n");
                gotoxy(3, 15);
                printf("que 100 digite sem o zero na frente.\n");
                gotoxy(3, 16);
                printf("\n");
                gotoxy(3, 17);
                printf("Exemplo: Aposta-se em 321 na centena e no resultado tem 8321 você ganhou já\n");
                gotoxy(3, 18);
                printf("que a centena bate.\n");
                gotoxy(3, 23);
                pausa();
                break;
            case 3:
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                gotoxy(5, 11);
                printf("O que uma aposta no bolinho?");
                gotoxy(3, 13);
                printf("Uma aposta no bolinho significa apostar no grupo resultante da dezena de\n");
                gotoxy(3, 14);
                printf("cada milhar.\n");
                gotoxy(3, 15);
                printf("\n");
                gotoxy(3, 16);
                printf("Exemplo: 2304 é do grupo 01. Já que de 01 a 04 pertence a esse grupo e vai\n");
                gotoxy(3, 17);
                printf("pulando de 4 em 4 totalizando em 25 grupos e cada grupo tem um animal como \n");
                gotoxy(3, 18);
                printf("significado.");
                gotoxy(3, 19);
                printf("Para grupos menores que 10 digite sem o zero na frente. \n");
                gotoxy(3, 20);
                printf("\n");
                gotoxy(3, 21);
                printf("Exemplo: Aposta-se no grupo 2 e no resultado tem 1206 você ganhou já que 06 e\n");
                gotoxy(3, 22);
                printf("do grupo 02.");
                gotoxy(3, 23);
                pausa();
                break;
            case 4:
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                gotoxy(5, 11);
                printf("O que é apostar no Primeiro prêmio e no primeiro ao quinto?");
                gotoxy(3, 13);
                printf("Quando se aposta no primeiro quinto seu número será comparado a todos os 5 \n");
                gotoxy(3, 14);
                printf("prêmios do sorteio. Já no primeiro prêmio apenas no 1 número a ser sorteado.\n");
                gotoxy(3, 15);
                printf("Já no primeiro prêmio apenas no 1 número a ser sorteado. Jogar no 1° ao 5°\n");
                gotoxy(3, 16);
                printf("aumenta sua chance de ganhar, mas tem premiação menor.\n");
                gotoxy(3, 23);
                pausa();
                break;
            case 5:
                tela_cotacao();
                gotoxy(3, 23);
                pausa();
                break;
            case 6:
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                logo_bicho(2, 4);
                gotoxy(5, 11);
                printf("Como ter um bom palpite?");
                gotoxy(3, 13);
                printf("A melhor chance de vencer é apostando no seu sonho. Sonhou que era um famoso \n");
                gotoxy(3, 14);
                printf("toureiro na Espanha? Então aposte no Touro! Alguns sonhos são mais difíceis\n");
                gotoxy(3, 15);
                printf("de decifrar, para isso recomendo buscar um adivinhador de sonho, procure um \n");
                gotoxy(3, 16);
                printf("no boteco mais próximo e não espalhe teu sonho para não agourarem ele!\n");
                gotoxy(3, 17);
                printf("\n");
                gotoxy(3, 18);
                printf("Não está satisfeito e quer ter uma experiência profissional? Então aprenda ");
                gotoxy(3, 19);
                printf("com os melhores! Segue abaixo o link do vídeo que cotém os grandes segredos:\n");
                gotoxy(3, 20);
                printf("<Ex cambista jogue com inteligência dica como jogar no jogo do bicho>\n");
                gotoxy(3, 21);
                printf("https://youtu.be/MyK3cBonvu0\n");
                gotoxy(3, 23);
                pausa();
                break;
            case 7:
                break;
            }
            break;

        case 3:
            //area que conta a origem do jogo
            clrscr();
            textcolor(BROWN);
            desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
            logo_origem(2, 3);
            int posicy = 10;
            gotoxy(3, posicy);
            printf("Após meses de lucro intenso no ramo de apostas de cavalo, Thomas Shelby e os");
            gotoxy(3, posicy++);
            printf("Peaky Blinders começaram a notar uma queda vertiginosa no lucro obtido pelo ");
            gotoxy(3, posicy++);
            printf("evento que era o principal meio de lucro para manter a Shelby LTDA de pé. ");
            gotoxy(3, posicy++);
            printf("Preocupados e sem saber o que fazer, os Peaky Blinders se reúnem e no meio ");
            gotoxy(3, posicy++);
            printf("da reunião John fala sobre sua viagem ao Brasil e um novo jogo de azar que ");
            gotoxy(3, posicy++);
            printf("estava virando febre em terras tupiniquins. Após isso, Thomas Shelby fica ");
            gotoxy(3, posicy++);
            printf("interessado por esse potencial investimento, então John acrescenta que o jogo");
            gotoxy(3, posicy++);
            printf("do bicho teve origem na capital do Império brasileiro, o Rio de Janeiro, onde");
            gotoxy(3, posicy++);
            printf("havia um zoológico que pertencia ao barão João Viana que estava com problemas");
            gotoxy(3, posicy++);
            printf("financeiros, mas teve a brilhante ideia de usar os 25 animais do zoológico");
            gotoxy(3, posicy++);
            printf("como bilhete para dar aos frequentadores do Zoo. E ao fim do dia um dos [...]");

            gotoxy(5, 22);
            printf("RETROCEDER                                                        PRÓXIMO");
            desenhar_linha_horizontal(3, 21, 76);
            int opcao001 = selecionar_opcao_horizontal(3, 22, 2, 66);
            switch (opcao001)
            {
            case 1:
                break;
            case 2:
                clrscr();
                textcolor(BROWN);
                desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
                int posiy = 3;
                gotoxy(3, posiy);
                printf("bichos era sorteado e quem tivesse o bilhete com esse bicho ganhava um");
                gotoxy(3, posiy++);
                printf("prêmio. Com isso, alem do zoológico sair da falência o jogo do bicho se");
                gotoxy(3, posiy++);
                printf("tornou o cargo chefe da renda do Barão. E para onde ia no Rio via");
                gotoxy(3, posiy++);
                printf("pessoas de baixa classe social comprando bilhetes de animais, todas");
                gotoxy(3, posiy++);
                printf("desesperadas pelo prêmio. Thomas Shelby fica encantado com a ideia e");
                gotoxy(3, posiy++);
                printf("resolve aplicar a mesma em todo território de Birmingham.");
                gotoxy(3, posiy++);
                printf(" ");
                gotoxy(3, posiy++);
                printf(" ");
                gotoxy(3, posiy++);
                printf("Para isso, John aconselhou de criar 3 maneiras de se jogar o bicho:");
                gotoxy(3, posiy++);
                printf("Milhar, que é consideravelmente mais difícil,  mas tem o maior prêmio;");
                gotoxy(3, posiy++);
                printf("Centena, que tem níveis intermediários de dificuldade e valor monetário;");
                gotoxy(3, posiy++);
                printf("Bolinho, que é fácil, tem jogabilidade simples, mas um prêmio baixo.");
                gotoxy(3, 23);
                pausa();
                break;

            default:
                break;
            }
            break;

        case 4:
            return 0;
        }
    }
    return 0;
}

int cut_cent(int number)
{
    //função utilizada para pegar os últimos três dígitos do milhar do resultado para fazer a "centena"
    int out;
    out = number - ((number / 1000) * 1000);
    return out;
}

int cut_dez(int number)
{
    //função utilizada para pegar os últimos dois dígitos do milhar do resultado para fazer o "bolinho"
    int out;
    out = number - ((number / 100) * 100);
    return out;
}

int def_grupo(int number)
{
    /*função utilizada para pegar esses dois ultimos digitos do bolinho pondo eles em casas de 1 a 25 de 4 em 4
     para posteriormente ser usado na função ehobicho */
    int grupo;
    int fator;
    fator = cut_dez(number);
    grupo = (fator / 4) + 1;

    return fator == 0 ? 25 : grupo;
}

void ehobixo()
{
    //Os nomes são guardados num vetor bidimensional e sera linkado com o grupo(bolinho) resultante da função sorteio
    strcpy(bichos[0], "Avestruz");
    strcpy(bichos[1], "Aguia");
    strcpy(bichos[2], "Burro");
    strcpy(bichos[3], "Borboleta");
    strcpy(bichos[4], "Cachorro");
    strcpy(bichos[5], "Cabra");
    strcpy(bichos[6], "Carneiro");
    strcpy(bichos[7], "Camelo");
    strcpy(bichos[8], "Cobra");
    strcpy(bichos[9], "Coelho");
    strcpy(bichos[10], "Cavalo");
    strcpy(bichos[11], "Elefante");
    strcpy(bichos[12], "Galo");
    strcpy(bichos[13], "Gato");
    strcpy(bichos[14], "Jacare");
    strcpy(bichos[15], "Leao");
    strcpy(bichos[16], "Macaco");
    strcpy(bichos[17], "Porco");
    strcpy(bichos[18], "Pavão");
    strcpy(bichos[19], "Peru");
    strcpy(bichos[20], "Touro");
    strcpy(bichos[21], "Tigre");
    strcpy(bichos[22], "Urso");
    strcpy(bichos[23], "Veado");
    strcpy(bichos[24], "Vaca");
}

void sorteio(int resultado[])
{
    //função utilizada para sortear o resultado para milhar,centena e bolinho
    for (int i = 0; i < 5; i++)
    {
        resultado[i] = rand() % 10000;
    }
}

void printar_res(int resultado[])
{
    //função utilizada para mostrar o resultado do sorteio do jogo
    for (int i = 0; i < 5; i++)
    {
        printf("%04d %02d", resultado[i], def_grupo(resultado[i]));
        printf(" %s\n", bichos[def_grupo(resultado[i]) - 1]);
    }
}

void bilhete(int x, int y, int resultado[])
{
    //função utilizada para mostrar o bilhete do apostador

    gotoxy(x, y++);
    printf("            Loteria Shelby");
    gotoxy(x, y++);
    printf(":::::::::::::::::::::::::::::::::::::");
    gotoxy(x, y++);
    printf("*           Loteria Shelby          *");
    gotoxy(x, y++);
    printf("*       Resultado do Sorteio        *");
    gotoxy(x, y++);
    printf("*Data Impressão:                    *");
    data_hora(19, 6, 1);
    gotoxy(x, y++);
    printf(":::::::::::::::::::::::::::::::::::::");
    gotoxy(x, y++);
    printf("Ponto: %04d - KAUA SHELBY", rand() %1000000);
    gotoxy(x, y++);
    printf("Terminal: %012ld", rand() %1000000000000);
    gotoxy(x, y++);
    printf("Operador: %08d", rand() %100000000);
    gotoxy(x, y++);
    printf("-------------------------------------");
    gotoxy(x, y++);
    printf("Data: ");
    data_hora(8, 12, 2);
    gotoxy(x, y++);
    printf("-------------------------------------");
    gotoxy(x, y++);
    printf("               FEDERAL");
    gotoxy(x, y++);
    printf(" ");
    gotoxy(x, y++);
    printf("1 -%04d %02d %s", resultado[0], def_grupo(resultado[0]), bichos[def_grupo(resultado[0]) - 1]);
    gotoxy(x, y++);
    printf("2 -%04d %02d %s", resultado[1], def_grupo(resultado[1]), bichos[def_grupo(resultado[1]) - 1]);
    gotoxy(x, y++);
    printf("3 -%04d %02d %s", resultado[2], def_grupo(resultado[2]), bichos[def_grupo(resultado[2]) - 1]);
    gotoxy(x, y++);
    printf("4 -%04d %02d %s", resultado[3], def_grupo(resultado[3]), bichos[def_grupo(resultado[3]) - 1]);
    gotoxy(x, y++);
    printf("5 -%04d %02d %s", resultado[4], def_grupo(resultado[4]), bichos[def_grupo(resultado[4]) - 1]);
    gotoxy(x, y++);
    printf(" ");
    gotoxy(x, y++);
    printf(":::::::::::::::::::::::::::::::::::::");
}

void tela_cotacao()
{
    //função utilizada para fazer os cálculos da premiação do apostador q vai ser proporcional ao tipo de aposta
    clrscr();
    desenhar_quadrado(TAMANHO_COLUNAS, TAMANHO_LINHAS, 1, 1);
    logo_cotacao(17, 2);
    gotoxy(25, 9);
    printf("Apostas feitas com 1 real rende:");
    desenhar_quadrado(26, 13, 2, 10);
    gotoxy(3, 11);
    printf("Milhar:");
    gotoxy(3, 13);
    printf("1° - £ 6.000,00");
    gotoxy(3, 14);
    printf("Probabilidade de acerto");
    gotoxy(3, 15);
    printf("1:10000");
    gotoxy(3, 17);
    printf("1° ao 5° £ - 1.200,00");
    gotoxy(3, 18);
    printf("Probabilidade de acerto");
    gotoxy(3, 19);

    desenhar_quadrado(26, 13, 28, 10);
    gotoxy(29, 11);
    printf("Centena:");
    gotoxy(29, 13);
    printf("1° £ - 4.000,00");
    gotoxy(29, 14);
    printf("Probabilidade de acerto");
    gotoxy(29, 15);
    printf("1:1000");
    gotoxy(29, 17);
    printf("1° ao 5° - £ 600,00");
    gotoxy(29, 18);
    printf("Probabilidade de acerto");
    gotoxy(29, 19);

    desenhar_quadrado(26, 13, 54, 10);
    gotoxy(55, 11);
    printf("Bolinho:");
    gotoxy(55, 13);
    printf("1° - £ 20,00");
    gotoxy(55, 14);
    printf("Probabilidade de acerto");
    gotoxy(55, 15);
    printf("1:25");
    gotoxy(55, 17);
    printf("1° ao 5° - £ 4,00");
    gotoxy(55, 18);
    printf("Probabilidade de acerto");
    gotoxy(55, 19);
}

void data_hora(int x, int y, int opcao)
{
    // ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual;

    // variável do tipo time_t para armazenar o tempo em segundos
    time_t segundos;

    // obtendo o tempo em segundos
    time(&segundos);

    // para converter de segundos para o tempo local
    // utilizamos a função localtime
    data_hora_atual = localtime(&segundos);

    gotoxy(x, y);
    switch (opcao)
    {
    case 1:
        // printar data e hora
        printf("%02d/%02d/%04d ", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900);
        printf("%02d:%02d:%02d", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
        break;
    case 2:
        //printar somente a data
        printf("%02d/%02d/%04d ", data_hora_atual->tm_mday, data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900);
        break;
    case 3:
        //printar somente a hora
        printf("%02d:%02d:%02d", data_hora_atual->tm_hour, data_hora_atual->tm_min, data_hora_atual->tm_sec);
        break;
    default:
        break;
    }
}


#endif
