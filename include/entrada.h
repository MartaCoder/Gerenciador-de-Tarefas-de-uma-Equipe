#ifndef ENTRADA_H
#define ENTRADA_H

#include <stddef.h>

#define TAM_ENTRADA 256

void lerLinha(const char *mensagem, char *destino, size_t tamanho);
void lerTextoObrigatorio(const char *mensagem, char *destino, size_t tamanho);
int lerInteiroIntervalo(const char *mensagem, int minimo, int maximo);
int lerCodigoPositivo(const char *mensagem);
int dataValida(const char *data);
void lerPrazo(char *prazo);

#endif
