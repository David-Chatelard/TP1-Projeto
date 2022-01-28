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