#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>

using namespace std;


/* -----------------------------------------------------------------------
// Estrutura de c�digo para declara��o de classe dom�nio.
// Substituir Dominio por nome da classe.
// Substituir Tipo.

class Dominio {
    private:
        Tipo valor;                      // Atributo para armazenar valor.
        void validar(Tipo);              // M�todo para validar valor.
    public:
        void setValor(Tipo);             // M�todo para atribuir valor.
        Tipo getValor() const;           // M�todo para recuperar valor.
};

inline Tipo Dominio::getValor() const{
    return valor;
}

----------------------------------------------------------------------- */

/**
 * @brief Padrão para a representação de uma cidade
 * 
 * Regras de formato:
 * 
 * - Os valores válidos de cidade são: Hong Kong, Bangkok, Macau, Singapura, Londres, Paris, Dubai, Delhi, Istambul, Kuala Lumpur, Nova Iorque, Antalya, Mumbai, Shenzhen e Phuket.
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Cidade {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Cidade::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de um código
 * 
 * Regras de formato:
 * 
 * - O código é representado por DDDDDDX, onde D é dígito (0-9) e X é dígito verificador
 * - Não existe código 000000
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Codigo {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Codigo::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma data
 * 
 * Regras de formato:
 * 
 * - A data é representada por DD-MES-ANO
 * - DD é o dia com faixa de valores entre 01 e 31
 * - MES é o mês com valores válidos iguais a: Jan, Fev, Mar, Abr, Mai, Jun, Jul, Ago, Set, Out, Nov, Dez
 * - ANO é o ano com faixa de valores entre 2000 e 9999
 * - A data considera a ocorrência de anos bissextos 
 */

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
class Data {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Data::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma descrição
 * 
 * Regras de formato:
 * 
 * - Possui de 0 a 30 caracteres
 * - Não há espaços brancos em sequência
 * - Não há pontos em sequência
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Descricao {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Descricao::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma duração
 * 
 * Regras de formato:
 * 
 * - Os valores válidos de duração são: 30, 60, 90, 120 ou 180
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Duracao {
    private:
        int valor;                      // Atributo para armazenar valor.
        void validar(int);              // M�todo para validar valor.
    public:
        void setValor(int);             // M�todo para atribuir valor.
        int getValor() const;           // M�todo para recuperar valor.
};

inline int Duracao::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de um email
 * 
 * Regras de formato:
 * 
 * - O email é representado por parte_local@domínio
 * - parte-local é composta por até 64 caracteres
 * - Caractere de parte-local pode ser:
 *      ~Letra maiúscula ou minúscula
 *      ~Dígito
 *      ~Caracteres especiais: !#$%&'+-/=?^_`{|}~
 *      ~Ponto desde que não seja o primeiro ou o último caractere e que não ocorra em sequência
 * - domínio é composto por até 253 caracteres
 * - Caractere de domínio pode ser:
 *      ~Letra maiúscula ou minúscula
 *      ~Dígito
 *      ~Hífen
 *      ~Ponto desde que não seja o primeiro e que não ocorra em sequência
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Email {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Email::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma duração
 * 
 * Regras de formato:
 * 
 * - Possui de 0 a 20 caracteres
 * - Não há espaços em branco em sequência
 * - Não há pontos em sequência
 */

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
class Endereco {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Endereco::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de um horário
 * 
 * Regras de formato:
 * 
 * - O horário é representado por HH:MM
 * - HH é o horário com faixa de valores entre 00 e 23
 * - MM é o minuto com faixa de valores entre 00 e 59
 */

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
class Horario {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Horario::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de um idioma
 * 
 * Regras de formato:
 * 
 * - Os valores válidos de idioma são: Ingles, Chines, Mandarim, Hindi, Espanhol, Frances, Arabe, Bengali, Russo, Portugues, Indonesio
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Idioma {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Idioma::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de um nome
 * 
 * Regras de formato:
 * 
 * - Possui de 5 a 20 caracteres
 * - Cada caractere é letra, ponto ou espaço em branco
 * - Ponto é precedido por letra, é último caractere ou é seguido por um espaço em branco
 * - Não há espaços em branco em sequência
 * - A primeira letra de cada termo é maiúscula 
 */

// Método implementado pelo aluno Alexandre Abrahami Pinto da Cunha, matrícula 1800
class Nome {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Nome::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma nota
 * 
 * Regras de formato:
 * 
 * - Os valores válidos de nota são: 0, 1, 2, 3, 4 ou 5
 */

// Classe implementada pelo aluno David Fanchic Chatelard, matrícula 180138863
class Nota {
    private:
        int valor;                      // Atributo para armazenar valor.
        void validar(int);              // M�todo para validar valor.
    public:
        void setValor(int);             // M�todo para atribuir valor.
        int getValor() const;           // M�todo para recuperar valor.
};

inline int Nota::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma senha
 * 
 * Regras de formato:
 * 
 * - A senha é representada por XXXXXX
 * - Cada caractere X é letra ou dígito
 * - Não existe caracter repetido
 * - Existe pelo menos uma letra maiúscula, uma letra minúscula e um dígito
 */

// Método implementado pelo aluno Emanuel Couto Brenag, matrícula 190057131, o aluno trancou a disciplina
class Senha {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Senha::getValor() const{
    return valor;
}

/**
 * @brief Padrão para a representação de uma duração
 * 
 * Regras de formato:
 * 
 * - Possui de 5 a 20 letras (não caracteres)
 * - Não há espaços em branco em sequência
 * - Não há pontos em sequência
 */

// Método implementado pelo aluno Alexandre Abrahami Pinto da Cunha, matrícula 1800
class Titulo {
    private:
        string valor;                      // Atributo para armazenar valor.
        void validar(string);              // M�todo para validar valor.
    public:
        void setValor(string);             // M�todo para atribuir valor.
        string getValor() const;           // M�todo para recuperar valor.
};

inline string Titulo::getValor() const{
    return valor;
}


#endif // DOMINIOS_H_INCLUDED
