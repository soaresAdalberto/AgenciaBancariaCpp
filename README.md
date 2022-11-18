# Agência Bancária

## Projeto desenvolvido como requisito para a matéria Programação Orientada a Objetos na linguagem C++.

--------------------------------------------------------

### Contexto:

	Para a criação desse projeto foi realizado um levantamento de requisitos sobre o que uma conta
bancária precisa ter. E é a partir desse ponto que se cria um software orientado a objetos, abstraindo
informações do mundo real e trazendo-as ao código. 
	Levando em consideração esse fato, criei uma agência bancária simples que possui três tipos de
contas: corrente, poupança e investimentos. Utilizando os recursos de herança simples e múltipla, 
codifiquei uma classe mãe, onde estarão encapuslados todos os atributos e regras de negócios comuns 
entre as contas e outra classe mãe que terá os dados em comum para os tipos de investimentos da ContaInvestimento. 
	Minhas contas poupança tem uma novidade: quando chegar o mês de aniversário da conta (por exemplo,
uma conta criada em JAN/2021 irá fazer aniversário em JAN/2022) ela irá ganhar um incremento monetário, 
como gratificação. Utilizei um Enum para categorizar os meus meses do ano.
	Na minha nova classe mãe, citada anteriormente, (TipoInvestimento) criei um Enum para os tipos de
investimentos que a ContaInvestimento pode ter. 
	Posteriormente, irei segregar novas classes que terão como parâmetro os atributos de sua mãe e as 
suas regras de negócio específicas, denominadas como classes filhas. 
	Tendo esses conceitos em mente, o meu programa funcionará da seguinte maneira: o usuário poderá 
cadastrar três tipos de conta: poupança, corrente e investimentos. Na conta poupança, no seu mês aniversário, 
ele ganha uma gratificação. Na corrente, ele tem um limite para saques além do seu saldo (cheque especial) 
e na investimentos ele pode escolher qual a forma de investir seu dinheiro, além de poder visualizar em todas 
as contas seu extrato e fazer depósitos/ saques. 

--------------------------------------------------------

### Classes:

-Classe Conta:
	É uma classe mãe. Tem os atributos padrões que serão utilizados pelas classes filhas. São as características principais de uma conta bancária.

-Conta Corrente: É uma conta filha, no qual absorve os atributos da sua mãe (Classe Conta) e cria os seus próprios. 

-Conta Poupança: É uma conta filha, no qual absorve os atributos da sua mãe (Classe Conta) e cria os seus próprios. 

-Conta Investimento: É uma conta neta, no qual absorve os atributos da sua mãe (Classe TipoInvestimento), que recebe da sua avó (Classe ContaCorrente) e cria os seus próprios atributos. 

Conceitos utilizados:
-Abstração;
-Instanciação;
-Encapsulamento;
-Criação de Enum;
-Herança simples;
-Herança múltipla;
-Polimorfismo.

--------------------------------------------------------

### Glossário:

-Private:
	Acesso apenas dentro do escopo da classe, no arquivo .cpp. Para acessar por fora utilizamos o método get (obter o valor) e set (setar o valor).

-Protected: 
	Consigo visualizar as variáveis tanto no escopo de suas classes mães, quanto filhas. Se fosse private, por exemplo, visualizaria apenas na mãe. Public visualizaria em qualquer lugar, mas a variável ficaria desprotegida. 

-Nível de acesso de herança:
	Utilizei apenas public. Exemplo: tudo que é public em Conta vai como public para ContaCorrente. Tudo que é private em Conta vai como private para ContaCorrente.

-Polimorfismo:
	Em programação orientada a objetos, polimorfismo é o princípio pelo qual duas ou mais classes derivadas da mesma superclasse podem invocar métodos que têm a mesma assinatura, mas comportamentos distintos. Para criar um método polifórmico é só colocar virtual na frente, exemplo: virtual void imprimirExtrato(). Dessa forma, o objeto é do tipo conta, mas por ter sido instânciado como contaInvestimento, irá pegar o seu método equivalente (da sua própria classe). Para voltar o tipo do objeto que estava da classe mãe para a classe filha eu posso usar o comando dynamic_cast.

-Polimorfismo de método:
	Em um construtor sobrecarregado, um método pode ser replicado desde que tenha a assinatura diferente. A assinatura seria o tipo da variável que é passada como parâmetro, por exemplo: Conta(string numConta) e Conta(string numConta) daria erro, mesma assinatura. Conta(string numConta) e Conta(string numAgencia) também daria erro, mesma assinatura. Agora Conta(string numAgencia, string numConta, string proprietario, float saldo) e Conta(float saldo, string numAgencia, string numConta, string proprietario) daria certo, pois existem assinaturas diferentes, sendo a primeira assinatura "string, string, string, float" e a segunda "float, string, string, string". Lembrando que Conta(float saldo) e Conta(float saldo []) tem assinaturas diferentes, uma vez que o primeiro é float e o segundo um vetor do tipo float. É recomendado para extrair informações de um arquivo, banco de dados, dentre outros.

-Polimorfismo de sobreposição:
	Por exemplo, crio dois construtores iguais. Em uma filha implementa e substitui o mesmo método construtor da mãe, ou seja, mesma assinatura. Por exemplo, o mesmo método para imprimirExtrato da classe mãe, Conta, pode ser utilizado para imprimirExtrato na classe filha, ContaCorrente, da seguinte maneira: Conta::imprimirExtrato(). 

-Construtor sobrecarregado com herança:
	Posso utilizar os atributos da minha classe mãe (dentro do construtor sobrecarregado mãe) para a minha classe filha (dentro do construtor sobrecarregado filha), exemplo: ContaCorrente::ContaCorrente(string numAgencia, string numConta, string proprietario, float saldo, float limite) : Conta(numAgencia, numConta, proprietario, saldo).
