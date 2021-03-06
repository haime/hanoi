#include "Hanoi.h"
/**
Constructor calcula el numero 
de movimientos
@params Discos ________
@result void
*/
Hanoi::Hanoi(int Discos)
{
	this->Discos= Discos;
	this->NumMovimientos=pow(2,this->Discos);
}

/**
Resuelve el juego de las Torres 
de Hanoi con N discos
@params void
@result void
*/
void Hanoi::Resolver()
{

	if (this->Discos%2 == 0)
	{
		for (int i = 1; i < this->NumMovimientos; ++i)
		{
			
			int O=(this->origen.empty())?0:this->origen.top();
			int A=(this->auxiliar.empty())?0:this->auxiliar.top();
			int D=(this->destino.empty())?0:this->destino.top();



			if (i%3==1)
			{//movimento entre origen y auxiliar
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
				}
			}
			if (i%3==2)
			{//movimento entre origen y destino
				if ( O>D)
				{
					this->origen.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
				}
			}
			//this->MostrarTorres();
		}
	}else
	{
		for (int i = 1; i < this->NumMovimientos; ++i)
		{

			int O=(this->origen.empty())?INFINITY:this->origen.top();
			int A=(this->auxiliar.empty())?INFINITY:this->auxiliar.top();
			int D=(this->destino.empty())?INFINITY:this->destino.top();

			std::cout<<O<<" "<<A<<" "<<D<<std::endl;
			if (i%3==1)
			{//movimento entre origen y destino
				
				if ( O>D)
				{

					this->origen.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->origen.top());
					this->origen.pop();
				}	


			}
			if (i%3==2)
			{//movimento entre origen y auxiliar
				
				if (O>A)
				{
					this->origen.push(this->auxiliar.top());
					this->auxiliar.pop();
				}else
				{
					this->auxiliar.push(this->origen.top());
					this->origen.pop();
				}
			}
			if (i%3==0)
			{//movimento entre destino y auxiliar
				if ( A>D)
				{
					this->auxiliar.push(this->destino.top());
					this->destino.pop();
				}else
				{
					this->destino.push(this->auxiliar.top());
					this->auxiliar.pop();
				}
			}
		//this->MostrarTorres();
		}
	}

}

void Hanoi::LlenarTorre()
{
	for(int i= this->Discos; i>0 ; --i)
	{
		this->origen.push(i);
	}
}

void Hanoi::MostrarTorres()
{
	std::stack<int> auxO;
	std::stack<int> auxA;	
	std::stack<int> auxD;
	int mayor;
	if(this->origen.size() > this->auxiliar.size() && this->origen.size() > this->destino.size())
	{
		mayor=origen.size();
	}else if(this->auxiliar.size() > this->origen.size() && this->auxiliar.size() > this->destino.size())
	{
		mayor=auxiliar.size();
	}else
	{
		mayor=destino.size();	
	}
	for(int i=mayor; i>0 ;--i)
	{
		if(i<=origen.size())
		{
			std::cout<<origen.top()<<" ";
			auxO.push(origen.top());
			origen.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=auxiliar.size())
		{
			std::cout<<auxiliar.top()<<" ";
			auxA.push(auxiliar.top());
			auxiliar.pop();	
		}else{
			std::cout<<"*"<<" ";
		}
		if(i<=destino.size())
		{
			std::cout<<destino.top()<<std::endl;
			auxD.push(destino.top());
			destino.pop();	
		}else{
			std::cout<<"*"<<std::endl;
		}	
	}
	

}
