#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
/* Plantilla de clase cola */
template <class T>
class Cola
{
private:
	Nodo<T> * start,* end;  /* Apuntadores al inicio y al final de la cola */
	int length;             /* Longitud actual de la cola */
public:
	Cola();                 /* Constructora */
	~Cola();                /* Destructora */
	void push(int);         /* Encola un elemento */
	int pop(void);          /* Desencola un elemento */
	int Length(void);       /* Devuelve longitud de la cola */
	void display(void);     /* Muestra la cola */
	bool isEmpty(void);
};

template <class T>
Cola<T>::Cola(){
	start = end = NULL;
	length = 0;
}

template <class T>
void Cola<T>::push(int value){
	Nodo<T> * newNode = new Nodo<T>();
	newNode->set_data(value);
	if(start==NULL){
		start = newNode;
		end = newNode;
		newNode->set_nxt(NULL);
		length++;
	}else{
		end->set_nxt(newNode);
		newNode->set_nxt(NULL);
		end = newNode;
		length++;
	}
}

template <class T>
int Cola<T>::pop(){
	int value = -1;
	if(start==NULL)
		return -1;
	else{
		value = start->get_data();
		start = start->get_nxt();
		length--;
	}
	return value;
}

template <class T>
int Cola<T>::Length(){
	return length;
}

template <class T>
bool Cola<T>::isEmpty(){
	if(start == NULL)
		return true;
	else
		return false;
}

template <class T>
void Cola<T>::display(){
	if(start==NULL)
		std::cout << "NO DATA";
	else{
		for(Nodo<int> * seeker = start;seeker != NULL;seeker = seeker->get_nxt()){
			std::cout << seeker->get_data() << ", ";
		}
	}
}


#endif // COLA_H_INCLUDED
