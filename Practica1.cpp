#include<iostream>
#include <fstream>
#include <stdlib.h>
#include<string.h>
using namespace std;
class Nodo
{	private:
		int anio,cilindros,dato;
		char *marca,*modelo,*categoria,*trasmision,*color;
		Nodo *sig;
	public:
		Nodo()
		{	marca=new char[5];
			marca="----";
			modelo=new char[5];
			modelo="----";
			categoria=new char[5];
			categoria="----";
			trasmision=new char[5];
			trasmision="----";
			color=new char[5];
			color="----";
			anio=0;
			cilindros=0;
			sig=NULL;	
		}
		Nodo(char *Ma,char *Mo,char *Ca,char *Tr,char *Co,int An,int Ci)
		{	marca=Ma;
			modelo=Mo;
			categoria=Ca;
			trasmision=Tr;
			color=Co;
			anio=An;
			cilindros=Ci;
			sig=NULL;
		}
		void Asignasig(Nodo*);
		void Leer();
		void Imprimir();
		Nodo *Obtienesig();
		int Oban()	{ 	return(this->anio);			};
		int Obci()	{ 	return(this->cilindros);	};
		char* Obma(){	return(this->marca);		};
		char* Obmo(){	return(this->modelo);		};
		char* Obtr(){	return(this->trasmision);	};
		char* Obca(){ 	return(this->categoria);	};
		char* Obco(){ 	return(this->color);		};
};
void Nodo::Asignasig(Nodo *x)
{	this->sig=x;
}
void Nodo::Leer()
{	char M[20],Mod[20],Cat[20],Tras[20],Co[20];
	cout<<"Ingrese Marca: "; cin>>M;
	cout<<"Ingrese Modelo: "; cin>>Mod;
	cout<<"Ingrese anio: "; cin>>anio;
	cout<<"Ingrese Categoria: "; cin>>Cat;
	cout<<"Ingrese numero de Cilindros: "; cin>>cilindros;
	cout<<"Ingrese color: "; cin>>Co;
	cout<<"Ingrese tipo de Trasmision: "; cin>>Tras;
	marca=new char[strlen(M)+1];	strcpy(marca,M);
	modelo=new char[strlen(Mod)+1];	strcpy(modelo,Mod);
	categoria=new char[strlen(Cat)+1];	strcpy(categoria,Cat);
	color=new char[strlen(Co)+1];	strcpy(color,Co);
	trasmision=new char[strlen(Tras)+1];	strcpy(trasmision,Tras);
}
void Nodo::Imprimir()
{ 	cout<<"|\t"<<this->marca<<"\t"<<this->modelo<<"\t"<<this->anio<<"\t"
	<<this->categoria<<"\t"<<this->cilindros<<"\t"<<this->trasmision<<"\t"<<this->color<<endl;
}
Nodo* Nodo::Obtienesig()
{	return(this->sig);
}
class LSE
{	private:
		Nodo *Inicio;
	public:
		void InsertarI(char*,char*,char*,char*,char*,int,int);
		void InsertarF(char*,char*,char*,char*,char*,int,int);
		void Imprimir();
		void Agregar(Nodo*);
		Nodo *ObtenerNodo(int);
		LSE()
		{	Inicio=NULL;
		}
		void BorrarI();
		void BorrarF();
		void Borrar();
		int Contar();
		Nodo* Buscar(int,int);
		Nodo* BuscarG();
		Nodo *Buscar(char*,int);
		void CrearA(int,int);
		void CrearA(char*);
		void Editar();
};
Nodo* LSE::ObtenerNodo(int x)
{	Nodo *aux=Inicio;
	int i=1;
	if(x>Contar()||x<=0) aux=NULL;
	else
	{	while(i!=x)
		{	aux=aux->Obtienesig();
			i++;
		}
	}
	return aux;
}
void LSE::InsertarI(char *Ma,char *Mo,char *Ca,char *Tr,char *Co,int An,int Ci)
{  	if(!Inicio)	Inicio=new Nodo(Ma,Mo,Ca,Tr,Co,An,Ci);
	else
	{	Nodo *helpx3=new Nodo(Ma,Mo,Ca,Tr,Co,An,Ci);
   		helpx3->Asignasig(Inicio);
   		Inicio=helpx3;
   	}
}
void LSE::InsertarF(char *Ma,char *Mo,char *Ca,char *Tr,char *Co,int An,int Ci)
{	if(Inicio==NULL)
		Inicio=new Nodo(Ma,Mo,Ca,Tr,Co,An,Ci);
	else
	{	Nodo *help=Inicio;
		while(help->Obtienesig()!=NULL)		
		help=help->Obtienesig();
		Nodo *helpx2=new Nodo(Ma,Mo,Ca,Tr,Co,An,Ci);
		help->Asignasig(helpx2);
	}
}
void LSE::Imprimir()
{	if(!Inicio)
		cout<<"Lista Vacia"<<endl;
	else
	{	Nodo *Aux=Inicio;
		while(Aux!=NULL)
		{	Aux->Imprimir();
			Aux=Aux->Obtienesig();
		}
	}
}
void LSE::BorrarI()
{	if(!Inicio)
		cout<<"Lista Vacia"<<endl;
	else
	{	if(Inicio->Obtienesig()==NULL)
		{	delete Inicio;
			Inicio=NULL;
		}
		else
		{	Nodo *hay=Inicio;
			Inicio=Inicio->Obtienesig();
			hay->Asignasig(NULL);
			delete hay;
		}
	}
}
void LSE::BorrarF()
{	if(!Inicio)
		cout<<"Lista Vacia"<<endl;
	else
	{	if(Inicio->Obtienesig()==NULL)
		{	delete Inicio;
			Inicio=NULL;
		}
		else
		{	Nodo *Ad,*Sh;
			Ad=Inicio;
			while(Ad->Obtienesig()!=NULL)
			{	Sh=Ad;
				Ad=Ad->Obtienesig();
			}
			Sh->Asignasig(NULL);
			delete Ad;
		}
	}
}
int LSE::Contar()
{	int ESCA=0;
   	if(!Inicio)   	ESCA=0;
   	else
   	{	Nodo *REC=Inicio;
   		while(REC!=NULL)
   		{	ESCA++;
   			REC=REC->Obtienesig();
   		}
	} return ESCA;
}
void LSE::Editar()
{	system("cls");
	cout<<"Edicion de datos"<<endl;
	Nodo *temp=BuscarG();
	if(temp==NULL) cout<<"Dato no encontrado"<<endl;
	else
	{	system("cls");	temp->Imprimir(); cout<<"Nuevos datos: "<<endl; 
		temp->Leer();
	}
}
void LSE::Borrar()
{  	cout<<"Borrar Datos"<<endl;
	Nodo *simi=BuscarG();
   	if(simi==NULL)   	cout<<"Dato no encontrado"<<endl;
   	else
   	{	if(simi==Inicio)   		BorrarI();   		
   		else
   		{	if(simi->Obtienesig()==NULL)	BorrarF();
   			else
   			{	Nodo *XL=Inicio;
   				while(XL->Obtienesig()!=simi)
   				XL=XL->Obtienesig();
   				XL->Asignasig(simi->Obtienesig());
   				simi->Asignasig(NULL);
   				delete simi;
   			}
   		}
   	}
}
Nodo* LSE::Buscar(char *m,int op)
{  	Nodo *Aux=Inicio;
	char *x;
	x=new char[strlen(m)+1];
	strcpy(x,m);
	int i=1,j=0;
   	if(Inicio)
   	{	switch(op)
   		{	case 1:	while (Aux!=NULL)
   					{	if(strcmp(x,Aux->Obma())==0)
   						{	cout<<"#"<<i<<": "; Aux->Imprimir(); i++; j++;
		   				}
		   				else i++;
   						Aux=Aux->Obtienesig();
   					}	break;
   			case 2: while (Aux!=NULL)
   					{	if(strcmp(x,Aux->Obmo())==0)
   						{	cout<<"#"<<i<<": "; Aux->Imprimir(); i++; j++;
		   				}
		   				else i++;
						Aux=Aux->Obtienesig();
   					}	break;
   			case 4: while (Aux!=NULL)
   					{	if(strcmp(x,Aux->Obca())==0)
   						{	cout<<"#"<<i<<": "; Aux->Imprimir(); i++; j++;
		   				}
		   				else i++;
   						Aux=Aux->Obtienesig();
   					}	break;
   			case 6: while (Aux!=NULL)
   					{	if(strcmp(x,Aux->Obco())==0)
   						{	cout<<"#"<<i<<": "; Aux->Imprimir(); i++; j++;
		   				}
		   				else i++;
   						Aux=Aux->Obtienesig();
   					}	break;
   			case 7: while (Aux!=NULL)
   					{	if(strcmp(x,Aux->Obtr())==0)
   						{	cout<<"#"<<i<<": "; Aux->Imprimir(); i++; j++;
		   				}
		   				else i++;
   						Aux=Aux->Obtienesig();
   					}	break;
		}
		if(j==0) cout<<"Dato no encontrado en base de datos"<<endl;
		else
		{	cout<<"Selecciona el numero del dato buscado: "; cin>>i;
   			Aux=ObtenerNodo(i);	return Aux;
		} 
   	}
   	return Aux;
}
Nodo* LSE::Buscar(int x,int op)
{  	Nodo *covid=Inicio;
	int i=1;
   	if(Inicio)
   	{	switch(op)
   		{	case 3:	while (covid!=NULL)
   					{	if(covid->Oban()==x)
   						{	cout<<"#"<<i<<": "; covid->Imprimir(); i++; 
		   				}
		   				else i++;
   						covid=covid->Obtienesig();
   					}
   					cout<<"Selecciona el numero del dato buscado: "; cin>>i;
   					covid=ObtenerNodo(i);	return covid; break;
   			case 5: while (covid!=NULL)
   					{	if(covid->Obci()==x)
   						{	cout<<"#"<<i<<": "; covid->Imprimir(); i++; 
		   				}
		   				else i++;
   						covid=covid->Obtienesig();
   					}
   					cout<<"Selecciona el numero del dato buscado: "; cin>>i;
   					covid=ObtenerNodo(i);	return covid; break;
		}
   	}
   	return covid;
}
Nodo* LSE::BuscarG()
{	Nodo *temp;
	int i,op;
	char m[11];
	cout<<"Como vamos a buscar los datos que necesitas: "<<endl
	<<"Opcion 1=Marca"<<endl<<"Opcion 2=Modelo"<<endl<<"Opcion 3=anio"<<endl
	<<"Opcion 4=Categoria"<<endl<<"Opcion 5=Numero de Cilindros"<<endl
	<<"Opcion 6=Color"<<endl<<"Opcion 7=Tipo de Trasmision"<<endl
	<<"Seleccionaste: "; cin>>op; 
	switch(op)
	{	case 1:	cout<<"Ingrese Marca: "; cin>>m;
				temp=Buscar(m,op); return temp; break;
		case 2:	cout<<"Ingrese Modelo: "; cin>>m;
				temp=Buscar(m,op); return temp; break;
		case 3:	cout<<"Ingrese Anio: "; cin>>i;
				temp=Buscar(i,op); return temp; break;
		case 4:	cout<<"Ingrese Categoria: "; cin>>m;
				temp=Buscar(m,op); return temp; break;
		case 5: cout<<"Ingrese Numero de Cilindros: "; cin>>i;
				temp=Buscar(i,op); return temp; break;
		case 6:	cout<<"Ingrese Color: "; cin>>m;
				temp=Buscar(m,op); return temp; break;
		case 7:	cout<<"Ingrese Tipo de Trasmision: "; cin>>m;
				temp=Buscar(m,op); return temp; break;
		default: cout<<"Opcion Invalida verifica tu seleccion"<<endl; break;
	}
}
void LSE::CrearA(char *m)
{	ofstream Mar; 
	char *x;
	x=new char[strlen(m)+1];
	strcpy(x,m);
	Nodo *Aux=Inicio;
	Mar.open("E:/Carrosmarca.txt");
	while(Aux!=NULL)
  	{	if(strcmp(x,Aux->Obma())==0)
	 	Mar<<Aux->Obma()<<"\t"<<Aux->Obmo()<<"\t"<<Aux->Oban()<<"\t"<<Aux->Obca()<<"\t"<<Aux->Obci()<<"\t"<<Aux->Obtr()<<"\t"<<Aux->Obco()<<endl;
	 	Aux=Aux->Obtienesig();
	}
	Mar.close();
}
void LSE::CrearA(int x,int op)
{	ofstream An,Cilin; 
	if(op==1)
	{	Nodo *Aux=Inicio;
		An.open("E:/Carrosaño.txt");
		while(Aux!=NULL)
  		{	if(Aux->Oban()==x)
	  	An<<Aux->Obma()<<"\t"<<Aux->Obmo()<<"\t"<<Aux->Oban()<<"\t"<<Aux->Obca()<<"\t"<<Aux->Obci()<<"\t"<<Aux->Obtr()<<"\t"<<Aux->Obco()<<endl;
	  	Aux=Aux->Obtienesig();
		}
		An.close();	
	}
	else
	{	Nodo *Aux=Inicio;
		Cilin.open("E:/CarrosCilindros.txt");
		while(Aux!=NULL)
  		{	if(Aux->Obci()==x)
	  		Cilin<<Aux->Obma()<<"\t"<<Aux->Obmo()<<"\t"<<Aux->Oban()<<"\t"<<Aux->Obca()<<"\t"<<Aux->Obci()<<"\t"<<Aux->Obtr()<<"\t"<<Aux->Obco()<<endl;
	  		Aux=Aux->Obtienesig();
		}
		Cilin.close();
	}
  	
}
class Archivo
{	private:
		fstream A;
	public:
		void InicializarLec();
		void InicializarEsc();
		void LeerA(LSE&);
		void EscribirA(int);
		void Finalizar(LSE);
};
void Archivo::InicializarLec()
{	A.open("E:/carros.txt", ios::in);
	if(A.fail())
	{	cout<<"No se abrio el archivo"<<endl;
		system("pause");
		exit(0);
	}
	cout<<"Eres un master en el manejo de archivos"<<endl;
}
void Archivo::Finalizar(LSE D)
{	Nodo *Aux=D.ObtenerNodo(1);
	ofstream g;
	g.open("E:/carros.txt");
	if(g.fail())
	{	cout<<"No se abrio el archivo"<<endl;
		system("pause");
		exit(0);
	}
	else
	{	while(Aux!=NULL)
  		{  	g<<Aux->Obma()<<"\t"<<Aux->Obmo()<<"\t"<<Aux->Oban()<<"\t"<<Aux->Obca()<<"\t"<<Aux->Obci()<<"\t"<<Aux->Obtr()<<"\t"<<Aux->Obco()<<endl;
	  		Aux=Aux->Obtienesig();
		}
	}
	cout<<"Datos guardados correctamente adios"<<endl;
	g.close();	
}
void Archivo::LeerA(LSE &T)
{	int i,nL,ani=0,cili=0;
	char *Ma,*Mode,*Cate,*Trasm,*Col;
	while(!A.eof())
	{	char M[20],Mod[20],An[20],Cat[20],Cil[20],Tras[20],Co[20];
		i=0;
		A.getline(M,20,'\t'); 
		A.getline(Mod,20,'\t');
		A.getline(An,20,'\t');
		A.getline(Cat,20,'\t');
		A.getline(Cil,20,'\t');
		A.getline(Tras,20,'\t');
		A.getline(Co,20);
		while(*(M+i)!=NULL)		i++;
		nL=i;		Ma=new char[nL+1];
		for(i=0;i<nL+1;i++)		Ma[i]=M[i];
		i=0;
		while(*(Mod+i)!=NULL)		i++;
		nL=i;		Mode=new char[nL+1];
		for(i=0;i<nL+1;i++)		Mode[i]=Mod[i];
		i=0;
		while(*(Cat+i)!=NULL)		i++;
		nL=i;		Cate=new char[nL+1];
		for(i=0;i<nL+1;i++)		Cate[i]=Cat[i];
		i=0;
		while(*(Co+i)!=NULL)		i++;
		nL=i;		Col=new char[nL+1];
		for(i=0;i<nL+1;i++)		Col[i]=Co[i];
		i=0;
		while(*(Tras+i)!=NULL)		i++;
		nL=i;		Trasm=new char[nL+1];
		for(i=0;i<nL+1;i++)		Trasm[i]=Tras[i];
		ani=atoi(An); cili=atoi(Cil);
		T.InsertarF(Ma,Mode,Cate,Trasm,Col,ani,cili);
	} A.close();
}
main()
{	LSE Dan;
	Nodo aux;
	Archivo A;
	char m[11];
	int opc,con=0,x,op;
	do{	
		cout<<"\t\tListas LSE Instituto Politecnico Nacional"<<endl<<
			  "--------------------------------------------------------------------"<<endl<<
		"\tMenu\nOpcion 1=Cargar archivos\nOpcion 2=Imprimir\nOpcion 3=Insertar al Inicio"<<
		"\nOpcion 4=Insertar al final\nOpcion 5=Borrar Inicio\nOpcion 6=Borrar final"<<
		"\nOpcion 7=Contar datos\nOpcion 8=Borrar dato especifico\nOpcion 9=Editar Datos"<<
		"\nOpcion 10=Crear archivos con datos\nOpcion 11=Salir\nSeleccionaste: ";	 cin>>opc;
		switch(opc)
		{	case 1: if(con==0){	A.InicializarLec(); 
								A.LeerA(Dan);	con++;} 
					else cout<<"Esta opcion solo se puede ocupar una vez"<<endl;	break;
			case 2: Dan.Imprimir(); break;
			case 3: aux.Leer(); Dan.InsertarI(aux.Obma(),aux.Obmo(),aux.Obca(),aux.Obtr(),aux.Obco(),aux.Oban(),aux.Obci());	break;
			case 4: aux.Leer(); Dan.InsertarF(aux.Obma(),aux.Obmo(),aux.Obca(),aux.Obtr(),aux.Obco(),aux.Oban(),aux.Obci());	break; 
			case 5: Dan.BorrarI(); break;
			case 6: Dan.BorrarF(); break;
			case 7: cout<<"Datos de lista: "<<Dan.Contar()<<endl; break;
			case 8: Dan.Borrar(); break;
			case 9: Dan.Editar(); break;
			case 10:cout<<"Que desea generar\n1=Por anio\n2=Por numero de cilindros\n3=Por marca\nSeleccionaste: ";	cin>>op;
					switch(op)
					{	case 1: cout<<"Ingrese anio: "; cin>>x; 
								Dan.CrearA(x,op); break;
						case 2: cout<<"Ingrese numero de cilindros: "; cin>>x; 
								Dan.CrearA(x,op); break;
						case 3: cout<<"Ingresa la marca: "; cin>>m;
								Dan.CrearA(m);	break;
						default: cout<<"Opcion Invalida Verifica"<<endl; 
					}	break;
			case 11: cout<<"Saliste del programa"<<endl; break;
			default: cout<<"Opcion invalida verifica las opciones"<<endl; break;
		}
		system("pause"); system("cls");
	}while(opc!=11);
	A.Finalizar(Dan);
}
