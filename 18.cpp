#include <iostream>
#include <string.h>
#include <list>
#include <iterator>
class persoana{
  unsigned id;
  char nume[40];
public:
  persoana(){}
  persoana(unsigned id1,const char nume1[40]){strcpy(nume,nume1); id=id1;}
  const char* get_nume()const{return nume;}
  void set_nume(char x[40]){strcpy(nume,x);}
  unsigned get_id()const{return id;}
  void set_id(unsigned x){id=x;}
  friend std::istream& operator>>(std::istream&,persoana&);
  friend std::ostream& operator<<(std::ostream&,persoana&);
  ~persoana(){}
};
class Abonat: public  persoana{
    unsigned long long numar_de_telefon;
public:
  Abonat(){}
  Abonat(unsigned id,const char nume[40],unsigned long long numar_de_telefon1):persoana(id, nume){numar_de_telefon=numar_de_telefon1;}
  void set_numar(unsigned long long x){numar_de_telefon=x;}
  unsigned long long get_numar()const{return numar_de_telefon;}
  virtual void display() const {std::cout<<"Id:"<<get_id()<<"	nume:"<<get_nume()<<"	numar de telefon:"<<get_numar()<<'\n';}
  friend std::istream& operator>>(std::istream&,Abonat&);
  friend std::ostream& operator<<(std::ostream& out,Abonat &A) {A.display();return out;}
  friend std::ostream& operator<<(std::ostream& out,Abonat *A){A->display();return out;}
  ~Abonat(){}
};
class Abonat_Skype: public Abonat{
    unsigned id_skype;
public:
  Abonat_Skype(){}
  Abonat_Skype(unsigned id, const char nume[40],unsigned long long numar_de_telefon,unsigned id_skype1):Abonat(id,nume,numar_de_telefon){id_skype=id_skype1;}
  void set_id_Skype(unsigned x){id_skype=x;}
  unsigned get_id_Skype()const{return id_skype;}
  virtual void display()const{std::cout<<"Id:"<<get_id()<<"	nume:"<<get_nume()<<"	numar de telefon:"<<get_numar()<<"	idSkype:"<<id_skype<<'\n';}
  friend std::istream& operator>>(std::istream&,Abonat_Skype&);
  friend std::ostream& operator<<(std::ostream& out,Abonat_Skype &A){A.display();return out;}
  friend std::ostream& operator<<(std::ostream& out,Abonat_Skype *A){A->display();return out;}
  ~Abonat_Skype(){};
};
class Abonat_Skype_Romania: public Abonat_Skype{
    char adresa_mail[40];
public:
  Abonat_Skype_Romania(){}
  Abonat_Skype_Romania(unsigned id, const char nume[40],unsigned long long numar_de_telefon,unsigned id_skype,const char adresaDEmail[40]):Abonat_Skype(id,nume,numar_de_telefon,id_skype){strcpy(adresa_mail,adresaDEmail);}
  void set_adresa(char x[40]){strcpy(adresa_mail,x);}
  char* get_adresa(){return adresa_mail;}
  void display()const{std::cout<<"Id:"<<get_id()<<"	nume:"<<get_nume()<<"	numar de telefon:"<<get_numar()<<"	idSkype:"<<get_id_Skype()<<"	adresa:"<<adresa_mail<<'\n';}
  friend std::istream& operator>>(std::istream&,Abonat_Skype_Romania&);
  friend std::ostream& operator<<(std::ostream& out,Abonat_Skype_Romania *A){A->display();return out;}
  friend std::ostream& operator<<(std::ostream& out,Abonat_Skype_Romania &A){A.display();return out;}
  ~Abonat_Skype_Romania(){}
};
class Abonat_Skype_Extern: public Abonat_Skype{
    char tara[40];
public:
  Abonat_Skype_Extern(){}
  Abonat_Skype_Extern(unsigned id, const char nume[40],unsigned long long numar_de_telefon,unsigned id_skype,const char country[40]):Abonat_Skype(id,nume,numar_de_telefon,id_skype){strcpy(tara,country);}
  void set_tara(char x[40]){strcpy(tara,x);}
  char* get_tara(){return tara;}
  void display()const{std::cout<<"Id:"<<get_id()<<"	nume:"<<get_nume()<<"	numar de telefon:"<<get_numar()<<"	idSkype:"<<get_id_Skype()<<"	tara:"<<tara<<'\n';}
  friend std::istream& operator>>(std::istream&,Abonat_Skype_Extern&);
  friend std::ostream& operator<<(std::ostream& out,Abonat_Skype_Extern &A){A.display();return out;}
  friend std::ostream& operator<<(std::ostream& out,Abonat_Skype_Extern *A){A->display();return out;}
  ~Abonat_Skype_Extern(){}
};
class Agenda{
    std::list <Abonat*> lista_abonati;
public:
    Abonat* operator[](const char  numele_abonatului[40]);
    void adaugare_final(Abonat *X){lista_abonati.push_back(X);}
    void adaugare_inceput(Abonat *X){lista_abonati.push_front(X);}
    void afisare_final(){std::cout<<lista_abonati.back();}
    void afisare_inceput(){std::cout<<lista_abonati.front();}

};
int main()
{ 


//---------------De aici bagam variabile random stupide--------

  Agenda agenda;
  Abonat *p;
  Abonat x(23,"asd",213);
  p=&x;
  agenda.adaugare_final(p);
  Abonat_Skype y(3211,"cas",3421,123);
  p=&y;
  agenda.adaugare_final(p);
  Abonat_Skype_Romania z(2134,"awea",234,2789,"@bla.bla");
  p=&z;
  agenda.adaugare_final(p);
  Abonat_Skype_Extern t(874,"MUUU",314,2131,"Man.United 0-1 Barcelona");
  p=&t;
  agenda.adaugare_final(p);


//----------Ne-am oprit din a baga variante random stupide------

//---------De aici e cautarea in agenda--------------------------

  	char optiune;
	std::cout<<"\nCauti pe cineva?(Y/n)";
	std::cin>>optiune;
	if(optiune=='y'||optiune=='Y'){
	char nume_cautat[40];
	std::cout<<"pe cine cauti?\n";
	std::cin>>nume_cautat;
	Abonat *X=agenda[nume_cautat];
	if(strcmp(X->get_nume(),nume_cautat)==0)
	std::cout<<X<<'\n';
	else
	std::cout<<"NU exista abonatul "<<nume_cautat<<'\n';
}
  return 0;
}
std::istream& operator >>(std::istream& in,persoana& X)
{
    unsigned id;
    char nume[40];
    std::cout<<"Id:";
    std::cin>>id;
    std::cout<<"Nume:";
    std::cin>>nume;
    X.set_nume(nume);
    X.set_id(id);
    return in;
}

std::istream& operator >>(std::istream& in,Abonat& X)
{
    unsigned id,nrtel;
    char nume[40];
    std::cout<<"Id:";
    std::cin>>id;
    std::cout<<"Nume:";
    std::cin>>nume;
    std::cout<<"Numar de telefon:";
    std::cin>>nrtel;
    X.set_nume(nume);
    X.set_id(id);
    X.set_numar(nrtel);
    return in;
}

std::istream& operator >>(std::istream& in,Abonat_Skype& X)
{
    unsigned id,nrtel,id_skype;
    char nume[40];
    std::cout<<"Id:";
    std::cin>>id;
    std::cout<<"Nume:";
    std::cin>>nume;
    std::cout<<"Numar de telefon:";
    std::cin>>nrtel;
    std::cout<<"Id_skype:";
    std::cin>>id_skype;
    X.set_nume(nume);
    X.set_id(id);
    X.set_numar(nrtel);
    X.set_id_Skype(id_skype);
    return in;
}

std::istream& operator >>(std::istream& in,Abonat_Skype_Romania& X)
{
    unsigned id,nrtel,id_skype;
    char nume[40],adresa_mail[40];
    std::cout<<"Id:";
    std::cin>>id;
    std::cout<<"Nume:";
    std::cin>>nume;
    std::cout<<"Numar de telefon:";
    std::cin>>nrtel;
    std::cout<<"Id_skype:";
    std::cin>>id_skype;
    std::cout<<"Adresa_mail:";
    std::cin>>adresa_mail;
    X.set_nume(nume);
    X.set_id(id);
    X.set_numar(nrtel);
    X.set_id_Skype  (id_skype);
    X.set_adresa(adresa_mail);
    return in;
}

std::istream& operator >>(std::istream& in,Abonat_Skype_Extern& X)
{
    unsigned id,nrtel,id_skype;
    char nume[40],tara[40];
    std::cout<<"Id:";
    std::cin>>id;
    std::cout<<"Nume:";
    std::cin>>nume;
    std::cout<<"Numar de telefon:";
    std::cin>>nrtel;
    std::cout<<"Id_skype:";
    std::cin>>id_skype;
    std::cout<<"Tara:";
    std::cin>>tara;
    X.set_nume(nume);
    X.set_id(id);
    X.set_numar(nrtel);
    X.set_id(id_skype);
    X.set_tara(tara);
    return in;
}


Abonat* Agenda::operator[](const char numele_abonatului[40]){
     std::list <Abonat*>::iterator i0;
      for(i0=lista_abonati.begin();i0!=lista_abonati.end();i0++)
        if(strcmp(numele_abonatului,(*i0)->get_nume())==0)
          return *i0;
    return lista_abonati.back();
}
