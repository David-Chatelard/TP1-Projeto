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

/**
 * @brief Padrão para representação de um usuário
 * 
 */

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

/**
 * @brief Armazena nome
 * 
 * @param nome Nome a ser armazenado
 */
inline void Usuario::setNome(const Nome &nome){
    this->nome = nome;
}

/**
 * @brief Armazena email
 * 
 * @param email Email a ser armazenado
 */
inline void Usuario::setEmail(const Email &email){
    this->email = email;
}

/**
 * @brief Armazena a senha
 * 
 * @param senha Senha a ser armazenada
 */
inline void Usuario::setSenha(const Senha &senha){
    this->senha = senha;
}

/**
 * @brief Retorna o nome
 * 
 * @return Nome Nome a ser retornado
 */
inline Nome Usuario::getNome() const{
    return nome;
}

/**
 * @brief Retorna o email
 * 
 * @return Email Email a ser retornado
 */
inline Email Usuario::getEmail() const{
    return email;
}

/**
 * @brief Retorna a senha
 * 
 * @return Senha Senha a ser retornada
 */
inline Senha Usuario::getSenha() const{
    return senha;
}


/**
 * @brief Padrão para a representação da avaliação de uma excursão
 * 
 */
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

/**
 * @brief Armazena o código da avaliação
 * 
 * @param codigo Código da avaliação
 */
inline void Avaliacao::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

/**
 * @brief Armazena a nota da avaliação
 * 
 * @param nota Nota da avaliação
 */
inline void Avaliacao::setNota(const Nota &nota){
    this->nota = nota;
}

/**
 * @brief Armazena a descrição da avaliação
 * 
 * @param descricao Descrição da avaliação
 */
inline void Avaliacao::setDescricao(const Descricao &descricao){
    this->descricao = descricao;
}

/**
 * @brief Retorna o código da avaliação
 * 
 * @return Codigo Código da avaliação
 */
inline Codigo Avaliacao::getCodigo() const{
    return codigo;
}

/**
 * @brief Retorna a nota da avaliação
 * 
 * @return Nota Nota da avaliação
 */
inline Nota Avaliacao::getNota() const{
    return nota;
}

/**
 * @brief Retorna a descrição da avaliação
 * 
 * @return Descricao Descrição da avaliação
 */
inline Descricao Avaliacao::getDescricao() const{
    return descricao;
}

#endif // ENTIDADES_H_INCLUDED
