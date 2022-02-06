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
