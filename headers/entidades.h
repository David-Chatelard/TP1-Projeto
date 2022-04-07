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
            /**
             * @brief Armazena nome do usuário
             * 
             * @param nome Nome a ser armazenado
             */
            void setNome(const Nome&);

            /**
             * @brief Retorna o nome do usuário
             * 
             * @return Nome Nome a ser retornado
             */
            Nome getNome() const;

            /**
             * @brief Armazena email do usuário
             * 
             * @param email Email a ser armazenado
             */
            void setEmail(const Email&);

            /**
             * @brief Retorna o email do usuário
             * 
             * @return Email Email a ser retornado
             */
            Email getEmail() const;

            /**
             * @brief Armazena a senha do usuário
             * 
             * @param senha Senha a ser armazenada
             */
            void setSenha(const Senha&);

            /**
             * @brief Retorna a senha
             * 
             * @return Senha Senha a ser retornada
             */
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


/**
 * @brief Padrão para a representação da avaliação de uma excursão
 * 
 */
class Avaliacao {
    private:
            Codigo codigo;
            Nota nota;
            Descricao descricao;
            Email emailAutor;
            Codigo codigoExcursao;
    public:
            /**
             * @brief Armazena o código da avaliação
             * 
             * @param codigo Código da avaliação
             */
            void setCodigo(const Codigo&);

            /**
             * @brief Retorna o código da avaliação
             * 
             * @return Codigo Código da avaliação
             */
            Codigo getCodigo() const;

            /**
             * @brief Armazena a nota da avaliação
             * 
             * @param nota Nota da avaliação
             */
            void setNota(const Nota&);

            /**
             * @brief Retorna a nota da avaliação
             * 
             * @return Nota Nota da avaliação
             */
            Nota getNota() const;

            /**
             * @brief Armazena a descrição da avaliação
             * 
             * @param descricao Descrição da avaliação
             */
            void setDescricao(const Descricao&);

            /**
             * @brief Retorna a descrição da avaliação
             * 
             * @return Descricao Descrição da avaliação
             */
            Descricao getDescricao() const;

            void setEmailAutor(const Email&);

            Email getEmailAutor() const;

            void setCodigoExcursao(const Codigo&);

            Codigo getCodigoExcursao() const;
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

inline void Avaliacao::setEmailAutor(const Email &emailAutor){
    this->emailAutor = emailAutor;
}

inline void Avaliacao::setCodigoExcursao(const Codigo &codigoExcursao){
    this->codigoExcursao = codigoExcursao;
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

inline Email Avaliacao::getEmailAutor() const{
    return emailAutor;
}

inline Codigo Avaliacao::getCodigoExcursao() const{
    return codigoExcursao;
}


/**
 * @brief Padrão para a representação de uma sessão de uma excursão
 * 
 */
class Sessao {
    private:
            Codigo codigo;
            Data data;
            Horario horario;
            Idioma idioma;
            Codigo codigoExcursao;
    public:
            /**
             * @brief Armazena o código da sessão
             * 
             * @param codigo Código da sessão
             */
            void setCodigo(const Codigo&);

            /**
             * @brief Retorna o código da sessão
             * 
             * @return Codigo Código da sessão
             */
            Codigo getCodigo() const;

            /**
             * @brief Armazena a data da sessão
             * 
             * @param data Data da sessão
             */
            void setData(const Data&);

            /**
             * @brief Retorna a data da sessão
             * 
             * @return Data Data da sessão
             */
            Data getData() const;

            /**
             * @brief Armazena o horário da sessão
             * 
             * @param horario Horário da sessão
             */
            void setHorario(const Horario&);

            /**
             * @brief Retorna o horário da sessão
             * 
             * @return Horario Horário da sessão
             */
            Horario getHorario() const;

            /**
             * @brief Armazena o idioma da sessão
             * 
             * @param idioma Idioma da sessão
            */
            void setIdioma(const Idioma&);

            /**
             * @brief Retorna o idioma da sessão
             * 
             * @return Idioma Idioma da sessão
             */
            Idioma getIdioma() const;

            void setCodigoExcursao(const Codigo&);

            Codigo getCodigoExcursao() const;
            
};

inline void Sessao::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

inline void Sessao::setData(const Data &data){
    this->data = data;
}

inline void Sessao::setHorario(const Horario &horario){
    this->horario = horario;
}

inline void Sessao::setIdioma(const Idioma &idioma){
    this->idioma = idioma;
}

inline void Sessao::setCodigoExcursao(const Codigo &codigoExcursao){
    this->codigoExcursao = codigoExcursao;
}

inline Codigo Sessao::getCodigo() const{
    return codigo;
}

inline Data Sessao::getData() const{
    return data;
}

inline Horario Sessao::getHorario() const{
    return horario;
}

inline Idioma Sessao::getIdioma() const{
    return idioma;
}

inline Codigo Sessao::getCodigoExcursao() const{
    return codigoExcursao;
}


/**
 * @brief Padrão para a representação de uma excursão
 * 
 */
class Excursao {
    private:
            Codigo codigo;
            Titulo titulo;
            Nota nota;
            Cidade cidade;
            Duracao duracao;
            Descricao descricao;
            Endereco endereco;
            Email emailGuia;
    public:
            /**
             * @brief Armazena o código da excursão
             * 
             * @param codigo Código a ser armazenado na excursão
             */
            void setCodigo(const Codigo&);

            /**
             * @brief Retorna o código da excursão
             * 
             * @return Codigo Código da excursão
             */
            Codigo getCodigo() const;

            /**
             * @brief Armazena o título da excursão
             * 
             * @param titulo Título a ser armazenado na excursão
             */
            void setTitulo(const Titulo&);

            /**
             * @brief Retorna o título da excursão
             * 
             * @return Titulo Título da excursão
             */
            Titulo getTitulo() const;

            /**
             * @brief Armazena a nota da excursão
             * 
             * @param nota Nota a ser armazenada na excursão
             */
            void setNota(const Nota&);

            /**
             * @brief Retorna a nota da excursão
             * 
             * @return Nota Nota da excursão
             */
            Nota getNota() const;

            /**
             * @brief Armazena a cidade da excursão
             * 
             * @param cidade Cidade a ser armazenada na excursão
             */
            void setCidade(const Cidade&);

            /**
             * @brief Retorna a cidade da excursão
             * 
             * @return Cidade Cidade da excursão
             */
            Cidade getCidade() const;

            /**
             * @brief Armazena a duração da excursão
             * 
             * @param duracao Duração a ser armazenada na excursão
             */
            void setDuracao(const Duracao&);

            /**
             * @brief Retorna a duração da excursão
             * 
             * @return Duracao Duração da excursão
             */
            Duracao getDuracao() const;

            /**
             * @brief Armazena a descrição da excursão
             * 
             * @param descricao Descrição a ser armazenada na excursão
             */
            void setDescricao(const Descricao&);

            /**
             * @brief Retorna a descrição da excursão
             * 
             * @return Descricao Descrição da excursão
             */
            Descricao getDescricao() const;

            /**
             * @brief Armazena o endereço da excursão
             * 
             * @param endereco Endereço a ser armazenado na excursão
             */
            void setEndereco(const Endereco&);

            /**
             * @brief Retorna o endereço da excursão
             * 
             * @return Endereco Endereço da excursão
             */
            Endereco getEndereco() const;

            /**
             * @brief Armazena o Email do guia da excursão
             * 
             * @param email Email do guia da excursão a ser armazenado na excursão
             */
            void setEmailGuia(const Email&);

            /**
             * @brief Retorna o Email do guia da excursão
             * 
             * @return Email Email do guia da excursão
             */
            Email getEmailGuia() const;
};

inline void Excursao::setCodigo(const Codigo &codigo){
    this->codigo = codigo;
}

inline void Excursao::setTitulo(const Titulo &titulo){
    this->titulo = titulo;
}

inline void Excursao::setNota(const Nota &nota){
    this->nota = nota;
}

inline void Excursao::setCidade(const Cidade &cidade){
    this->cidade = cidade;
}

inline void Excursao::setDuracao(const Duracao &duracao){
    this->duracao = duracao;
}

inline void Excursao::setDescricao(const Descricao &descricao){
    this->descricao = descricao;
}

inline void Excursao::setEndereco(const Endereco &endereco){
    this->endereco = endereco;
}

inline void Excursao::setEmailGuia(const Email &emailGuia){
    this->emailGuia = emailGuia;
}

inline Codigo Excursao::getCodigo() const{
    return codigo;
}

inline Titulo Excursao::getTitulo() const{
    return titulo;
}

inline Nota Excursao::getNota() const{
    return nota;
}

inline Cidade Excursao::getCidade() const{
    return cidade;
}

inline Duracao Excursao::getDuracao() const{
    return duracao;
}

inline Descricao Excursao::getDescricao() const{
    return descricao;
}

inline Endereco Excursao::getEndereco() const{
    return endereco;
}

inline Email Excursao::getEmailGuia() const{
    return emailGuia;
}

#endif // ENTIDADES_H_INCLUDED
