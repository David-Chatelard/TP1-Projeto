#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

/* -----------------------------------------------------------------------
// Estrutura de c�digo sugerida para declara��o de classe entidade.
// Substituir Entidade por nome da classe.
// Substituir Dominio.
// Substituir nomeAtributo.

class Entidade {
    private:
            Dominio nomeAtributo;
    public:
            void setnomeAtributo(const Dominio&);
            Dominio getnomeAtributo() const;
};

inline void Entidade::setnomeAtributo(const Dominio &nomeAtributo){
    this->nomeAtributo = nomeAtributo;
}

inline Dominio Entidade::getnomeAtributo() const{
    return nomeAtributo;
}

----------------------------------------------------------------------- */

class Usuario {
    private:
            Nome nome;
            Email email;
            Senha senha;
    public:
            void setNome(const Nome&);
            Nome getNome() const;
            void setEmail(const Email&);
            Email getEmail() const;
            void setSenha(const Senha&);
            Senha getSenha() const;
};

inline void Usuario::setNome(const Nome &nome){
    this->nome = nome;
}
inline void Usuario::setEmail(const Email &email){
    this->email = email;
}
inline void Usuario::setSenha(const Senha &senha){
    this->senha = senha;
}

inline Nome Usuario::getNome() const{
    return nome;
}
inline Email Usuario::getEmail() const{
    return email;
}
inline Senha Usuario::getSenha() const{
    return senha;
}


class Avaliacao {
    private:
            Codigo codigo;
            Nota nota;
            Descricao descricao;
    public:
            void setCodigo(const Codigo&);
            Codigo getCodigo() const;
            void setNota(const Nota&);
            Nota getNota() const;
            void setDescricao(const Descricao&);
            Descricao getDescricao() const;
};

inline void Avaliacao::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}
inline void Avaliacao::setNota(const Nota &nota){
    this->nota = nota;
}
inline void Avaliacao::setDescricao(const Descricao &descricao){
    this->descricao = descricao;
}

inline Codigo Avaliacao::getCodigo() const{
    return codigo;
}
inline Nota Avaliacao::getNota() const{
    return nota;
}
inline Descricao Avaliacao::getDescricao() const{
    return descricao;
}

#endif // ENTIDADES_H_INCLUDED
