#include<iostream>
#include<string>
using namespace std;

// --------------------- the start of cars class -------------------------//
class cars{
int ids;
int seats;
double seatprice;
int passenger;
string drivername;
public : 
cars()
{
ids=0;
drivername='no';
 seats=7;
 seatprice=0;
 passenger=0;
 
}
cars(int ids, int seats, double seatprice,int passenger, string drivername)
{
this->ids=ids;
this->seats=seats;
this->seatprice=seatprice;
this->passenger=passenger;
this->drivername=drivername;
}
//------------------ setters -----------------------
void setid(int ids)
{
this->ids=ids;	
}
void setseats(int seats)
{
this->seats=seats;
}
void setprice(double seatprice)
{
this->seatprice=seatprice;
}
void setpassenger(int passenger)
{
this->passenger=passenger;
}
void setname(string name)
{
this->drivername=name;
}
 //------------------ getters -----------------------
 int getid()
 {
 	return ids;
 }
 int getseats()
 {
 	return seats;
 }
 double getprice()
 {
 	return seatprice;
 }
 int getpassenger()
 {
 	return passenger;
 }
 string getname()
 {
 	return drivername;
 }
 
 // ------------------ operator overload ----------------//
 void operator=(cars d)
 {
 	setid(d.getid());
 	setname(d.getname());
 	setprice(d.getprice());
 	setpassenger(d.getpassenger());
 	setseats(d.getseats());
 }
};


// --------------------- the end of cars class -------------------------//


const int maxsize=100;
// --------------------- the start of queue class -------------------------//
class queue
{
    cars s[maxsize];
	int front,rear,count;
	public:
	queue()
	{
		front=0;rear=maxsize-1;count=0;
	}
	bool empty()
	{
		return(count==0);
	}
	bool append(int ids, int seats, double seatprice,int passenger, string drivername)
	{
		if(count==maxsize)return 0;
		rear=(rear+1)%maxsize;
		s[rear].setid(ids);
		s[rear].setname(drivername);
		s[rear].setseats(seats);
		s[rear].setpassenger(passenger);
		s[rear].setprice(seatprice);
		count++;
		return 1;
	}
	bool serve()
	{
		if(empty())
		return 0;
		front=(front+1)%maxsize;
		count--;
		return 1;
		
	}
	cars retrieve(cars &c)
	{
	switch (empty()) {
  case 0: break;}
  
		c=s[front];
		return c;
	}
	
};

// --------------------- the end of queue class -------------------------//
//------------------ to check if there is repeated id or not // 
bool checkerid(queue d,int ids)
{
 cars v;
	while(!d.empty())
	{
		d.retrieve(v);
		if(v.getid()==ids )
		return 1;
		d.serve();
		
	}
	return 0;// there is no repeated id 
}
int counters(queue s)
{
int counter=0;
	while(!s.empty())
	{
	counter++;
	s.serve();	
	}
	return counter;
}


cars checkerid2(queue d,int ids,string name, double price,int seats)
{
 cars v;
 	cars n;

	while(!d.empty())
	{
		d.retrieve(v);
		if(v.getid()==ids && v.getname()==name &&v.getseats()==seats)
		return n;
		d.serve();
		
	}
	if(v.getid()!=ids) return n;
	
	return v;// 
}

//----------- add a car at specified position function------------//

void add(queue &garage, int position,queue &servedqueue)
{
queue temp; 
int ids; int seats; double seatprice;int passenger; string drivername;
			cout<<"enter the car id , seat , seatprice , passenger , drivername \n"; 
			cin>>ids>>seats>>seatprice>>passenger>>drivername;
			if(garage.empty()&& servedqueue.empty())
			{
				garage.append(ids,seats,seatprice,passenger,drivername);
			}
			else {
				
			
			while(passenger>seats)
			{
				cout<<"the passengers is more than seats number please enter the passengers number again\n";
				cin>>passenger;
			}

			while(checkerid(garage , ids)!=0 )
			{
				cout<<"renter the id , because the entered id is repeated \n";
				cin>>ids;
			}
			if(!servedqueue.empty())// start of servved queue checking
			{
				
			
			cars test=checkerid2(servedqueue,ids,drivername,seatprice,seats);
			while(test.getprice()!=0)
			{
			cout<<"enter the inmation below to add this id or change the id \n";
				cout<<"the owner of this id is "<<test.getname()<<" and his id = "<<test.getid()<<" the seats price is "<<test.getprice()<<" and the number of seats is "<<test.getseats()<<endl;
				cout<<"firsst u have to insert id , then seats number , seatprice , driver name \n";
			cin>>ids>>seats>>seatprice>>drivername;
			test=checkerid2(servedqueue,ids,drivername,seatprice,seats);
			}	
			}// end of servved queue checking
			for(int i=1;i<position;i++)
			{
			cars te;
			if(garage.empty()) 
			{
				i=position+1;
			}
			if(!garage.empty())
			{
			garage.retrieve(te);
			temp.append(te.getid(),te.getseats(), te.getprice(),te.getpassenger(),te.getname());
			garage.serve();				
			}

			}
			temp.append(ids,seats,seatprice,passenger,drivername);
			while(!garage.empty())
			{
			cars te;
			garage.retrieve(te);
			temp.append(te.getid(),te.getseats(), te.getprice(),te.getpassenger(),te.getname());
			garage.serve();
				
			}
			while(!temp.empty())
			{
			cars te;
			temp.retrieve(te);
			garage.append(te.getid(),te.getseats(), te.getprice(),te.getpassenger(),te.getname());
			temp.serve();
			}
			}


}
//----------- end add a car at specified position function------------//
//----------- to print the cars information in garage------------//
void print (queue pr)
{
int  i =1; 
	cars temp ;
	if(pr.empty()) {
		cout<<"the garage is empty there is no information to print \n";
		return;
	} 
	while (!pr.empty())
	{
	cout<<"<-----------------------the "<<i << " information :----------------------->\n ";
	pr.retrieve(temp);
	cout<<"the car id : "<<temp.getid()<<endl;
	cout<<"the number of seats  "<<temp.getseats()<<endl;
	cout<<"the seatprice is "<<temp.getprice()<<endl;
	cout<<"the number of passengers is "<<temp.getpassenger()<<endl;
	cout<<"the driver name is "<<temp.getname()<<endl;
	cout<<"<---------------------------------------------->\n ";
	pr.serve();
	i++;
		
	}
}
//----------- end------------//
//----------- to get the garage income------------//
double garageincome(queue a , queue b )
{
	double income=0;
	while(!a.empty())
	{
		cars temp; 
		a.retrieve(temp);
		income+=(temp.getpassenger() *temp.getprice());
		a.serve();
	}
	
		while(!b.empty())
	{
		cars temp; 
		b.retrieve(temp);
		income+=(temp.getpassenger() *temp.getprice());
		b.serve();
	}
	return income;
}

// to make a copy from the queue
void fill (queue te, queue &f)
{
cars temp;
	while(!te.empty())
	{
	te.retrieve(temp);
	f.append(temp.getid(),temp.getseats(), temp.getprice(),temp.getpassenger(),temp.getname());
	te.serve();	
	}
}

//----------- to add the income from the served queue and garage queue and return it  ------------//
void addprice(queue &last ,cars c)
{
queue temp ;
cars te; 
while(!last.empty())
{
	last.retrieve(te);
	if(te.getid()==c.getid())
	{
		te.setpassenger(te.getpassenger()+c.getpassenger());
		temp.append(te.getid(),te.getseats(), te.getprice(),te.getpassenger(),te.getname());
		last.serve();
	}
	temp.append(te.getid(),te.getseats(), te.getprice(),te.getpassenger(),te.getname());
	last.serve();
} 
temp.append(c.getid(),c.getseats(), c.getprice(),c.getpassenger(),c.getname());
fill(temp,last);

}
//----------- to get the super driver details ------------//
cars maxincome(queue c, queue c1 )
{
queue temp ;
queue last;
fill(c,temp);
fill(c1,temp);

cars tem;
while(!temp.empty())
{
	tem=temp.retrieve(tem);
	addprice(last,tem);// i sent the last queue and an object in from temp which it includes all cars in garage and served
	temp.serve();
}


// to calculate the maxincome from last queue 
cars maxin;
last.retrieve(maxin);
while(!last.empty())
{
cars comp;
last.retrieve(comp);
if((comp.getprice()*comp.getpassenger())>(maxin.getprice()*maxin.getpassenger()))
maxin=comp;
last.serve();	
}
return maxin;
}

//----------- to remove a specified id car------------//
void deletecar(queue &d,queue &dq, int ids)
{
queue temp ; 
cars c;
if(d.empty())
{
cout<<"the queue is empty there is no cars to delete \n" ;
return;	
} 
while(!d.empty())
{
	d.retrieve(c);
	if(c.getid()==ids)
	{
	dq.append(c.getid(),c.getseats(), c.getprice(),c.getpassenger(),c.getname());
	cout<<"the specified car is deleted ! \n";
	d.serve();
	if(!d.empty())
	d.retrieve(c);	
	}
	if(!d.empty())
	{
	temp.append(c.getid(),c.getseats(), c.getprice(),c.getpassenger(),c.getname());
	d.serve();	
	}
}
	
	while(!temp.empty())
	{
		temp.retrieve(c);
		d.append(c.getid(),c.getseats(), c.getprice(),c.getpassenger(),c.getname());
		temp.serve();
	}
}
//----------- end of  removing a specified id car------------//
main()
{
int choice=9;
queue garage;
queue servedqueue;
while(choice!=8)
{
		cout<<"1)Add a car to the garage.\n";
		cout<<"2)Remove a car. \n";
		cout<<"3)Forward a car.\n";
		cout<<"4)Insert a car at.\n";
		cout<<"5)Print garage information.\n";
		cout<<"6)Garage income.\n";
		cout<<"7)Super driver\n";
		cout<<"8)exit\n";
		cin>>choice;
		
		if(choice==1){
			int ids; int seats; double seatprice;int passenger; string drivername;
			cout<<"enter the car id , seat , seatprice , passenger , drivername \n"; 
			cin>>ids>>seats>>seatprice>>passenger>>drivername;
			
			if(garage.empty()&& servedqueue.empty())
			{
			
			while(passenger>seats)
			{
				cout<<"the passengers is more than seats number please enter the passengers number again\n";
				cin>>passenger;
			}
				garage.append(ids,seats,seatprice,passenger,drivername);
				
			}
			else {
				
			
			while(passenger>seats)
			{
				cout<<"the passengers is more than seats number please enter the passengers number again\n";
				cin>>passenger;
			}

			while(checkerid(garage , ids)!=0 )
			{
				cout<<"renter the id , because the entered id is repeated \n";
				cin>>ids;
			}// i need to add seats , drivername , seatprice,id in served queue
			if(!servedqueue.empty())// start of servved queue checking
			{
				
			
			cars test=checkerid2(servedqueue,ids,drivername,seatprice,seats);
			while(test.getprice()!=0)
			{
			cout<<"enter the information below to add this id or change the id \n";
				cout<<"the owner of this id is "<<test.getname()<<" and his id = "<<test.getid()<<" the seats price is "<<test.getprice()<<" and the number of seats is "<<test.getseats()<<endl;
				cout<<"firsst u have to insert id , then seats number , seatprice , driver name \n";
			cin>>ids>>seats>>seatprice>>drivername;
			test=checkerid2(servedqueue,ids,drivername,seatprice,seats);
			}	
			}// end of servved queue checking
			garage.append(ids,seats,seatprice,passenger,drivername);

			
}// end of else
		}
		
		
		if(choice==2){
			if(garage.empty()) cout<<"the garage is empty there is no car to remove \n";
			if(!garage.empty())
			{
			cars se;
				garage.retrieve(se);
		servedqueue.append(se.getid(),se.getseats(), se.getprice(),se.getpassenger(),se.getname());
		garage.serve();
				
			}
		}
		if(choice==3){
			cout<<"enter the car id that u want to remove\n";
			int idc;
			cin>>idc;
			deletecar(garage,servedqueue,idc);
			
		}
		if(choice==4){
		int position;
			cout<<"enter the position u want to insert the car in \n";
			cin>>position;
			add(garage,position,servedqueue);
			
		}
		
		if(choice==5){
			print(garage);
		}
		if(choice==6){
			cout<<"the total income of the garage is equal "<<garageincome(garage,servedqueue)<<endl;
		}
		if(choice==7){
			cars super;
			super=maxincome(garage,servedqueue);
			cout<<"the super driver name is :"<<super.getname() <<endl;
			cout<<"and the number of passengers :"<<super.getpassenger() <<endl;
		} 

	
}
}