#ifndef __LIST_H__
#define __LIST_H__

template <typename T>
class List {
public:
    // Inner Node class
    class Node {
    public:
        friend class List<T>;
        Node(List<T> * list, Node* prevNode, const T& value);
        Node * Next() { return m_pNext; }
        const Node * Next() const { return m_pNext; }
        void Set(const T& val) { m_tValue = val; }
        T& Value() { return m_tValue; }
        const T& Value() const { return m_tValue; }
    private:
        T m_tValue;
		Node * m_pNext;
    };

    List() : m_pFirst(0), m_pLast(0) {}
    ~List();

    int Size() const;
    bool IsEmpty() const;
    Node * Add(const T& val);
    Node * InsertBefore(const Node* node, const T& val);
    Node * InsertAfter(Node* node, const T& val);
	Node * First() { return m_pFirst; }
	Node * Last() { return m_pLast; }
    const Node * First() const { return m_pFirst; }
    const Node * Last() const { return m_pLast; }
    void Remove(Node* node);
    void Remove(const T& obj);
    void Clear();
    void Sort(bool (*compareFunc)(T&, T&));

private:
	Node * m_pFirst;
	Node * m_pLast;
};


template <typename T>
List<T>::Node::Node(List<T>* list, Node* prevNode, const T& value) : m_tValue(value) {
	if (prevNode == NULL) { // Si prevNode es null, quiere decir que el elemento va a meterse el primero de la lista
		m_pNext = (*list).First();
	} else { 
		if ((*prevNode).m_pNext != NULL)   // Significa que no es el último de la lista
			m_pNext = (*prevNode).m_pNext; // Como no es el último de la lista, entonces este nuevo nodo tiene que adquirir su next
		else 
			m_pNext = NULL;                // Si el nodo anterior estaba apuntando a null, este lo "hereda"

		(*prevNode).m_pNext = this;        // El nodo previo, ha de apuntar a este nuevo nodo como next
	}
}

template <typename T>
List<T>::~List() {
	Clear();
}

template <typename T>
int List<T>::Size() const {
	Node * actual_node = m_pFirst;
	int size = 0;

	while (actual_node)
	{
		actual_node = (*actual_node).Next();
		size++;
	}

	return size;
}

template <typename T>
bool List<T>::IsEmpty() const {
	return m_pFirst == NULL;
}

template <typename T>
typename List<T>::Node* List<T>::Add(const T& val) {
	Node * n = new Node(this, Last(), val); // Creamos y metemos el nodo

	if (m_pFirst == NULL) { 
		// Si la lista está vacía
		m_pFirst = m_pLast = n;
	} else {
		// Si no está vacía, solo modificamos el final
		m_pLast = n;
	}

	return n;
}

template <typename T>
typename List<T>::Node* List<T>::InsertBefore(const Node* node, const T& val) {
	Node * previous_node = NULL;
	Node * actual_node = m_pFirst;

	// Buscamos el elemento hasta que demos con el o hasta que lleguemos al final (NULL)
	while ((actual_node != node) && (node != NULL))
	{
		if ((*actual_node).Next() == NULL) // Si estamos en el último, el siguiente es NULL
			return NULL;                   // entonces, devolvemos null y no agregamos nada porque no se ha encontrado el nodo

		previous_node = actual_node;
		actual_node = (*actual_node).Next();
	}

	// Si el nodo, es el primer elemento de la lista
	if (actual_node == m_pFirst) { 
		Node * n = new Node(this, previous_node, val);

		m_pFirst = n;

		return n;
	}

	return NULL;
}	

template <typename T>
typename List<T>::Node* List<T>::InsertAfter(Node* node, const T& val) {
	Node * actual_node = m_pFirst;

	// Buscamos el elemento hasta que demos con el o hasta que lleguemos al final (NULL)
	while ((actual_node != node) && (node != NULL))
	{
		if ((*actual_node).Next() == NULL) // Si estamos en el último, el siguiente es NULL
			return NULL;                   // entonces, devolvemos null y no agregamos nada porque no se ha encontrado el nodo

		actual_node = (*actual_node).Next();
	}

	Node * n = new Node(this, actual_node, val);

	if ((*actual_node).Next() == NULL) // Si era el último elemento de la lista
		m_pLast = n;                  // Actualizamos el último de la lista

	return n;
}

template <typename T>
void List<T>::Remove(Node* node) {
	if (node == NULL)
		return;

	Node * previous_node = NULL;
	Node * actual_node = m_pFirst;

	// Buscamos el elemento hasta que demos con el o hasta que lleguemos al final (NULL)
	while ((actual_node != node) && (node != NULL))
	{
		previous_node = actual_node;
		actual_node = (*actual_node).Next();
	}
	
	// Si no se ha encontrado
	if (actual_node == NULL)
		return;

	// Si se ha encontrado...
	if (previous_node) { // Y no es el primero de la lista

		if ((*actual_node).Next())   // Y es el ultimo de la lista
			m_pLast = previous_node; // Actualizamos el ultimo de la lista al previous, porque el actual nos lo cargamos

		(*previous_node).m_pNext = (*actual_node).Next();

	} else
		m_pFirst = (*actual_node).Next();

	delete actual_node; // Esto está muy turbio REPASAR
}

template <typename T>
void List<T>::Remove(const T& obj) {
	Node * previous_node = NULL;
	Node * actual_node = m_pFirst;

	// Buscamos el elemento hasta que el contenido sea igual que uno de los miembros
	while ( (*actual_node).m_tValue != obj)
	{
		previous_node = actual_node;
		actual_node = (*actual_node).Next();

		// Si el actual node (de la siguiente iteración) es NULL, hemos llegado al final
		if (actual_node == NULL)
			return;
	}

	// Si se ha encontrado...
	if (previous_node) { // Y no es el primero de la lista

		if ((*actual_node).Next())   // Y es el ultimo de la lista
			m_pLast = previous_node; // Actualizamos el ultimo de la lista al previous, porque el actual nos lo cargamos

		(*previous_node).m_pNext = (*actual_node).Next();

	} else
		m_pFirst = (*actual_node).Next();

	delete actual_node; // Esto está muy turbio REPASAR
}

template <typename T>
void List<T>::Clear() {
	Node * previous_node = NULL;
	Node * actual_node = m_pFirst;

	// Hasta la cocina y más alla!
	while (actual_node != NULL)
	{
		previous_node = actual_node;
		actual_node = (*actual_node).Next();

		delete previous_node;
	}

	delete actual_node;

	m_pFirst = m_pLast = NULL;
}

template <typename T>
void List<T>::Sort(bool (*compareFunc)(T&, T&)) {
	Node * first = list.First();
    Node * last = list.Last();

    for (Node * i = first; i != last; i = (*i).m_pNext) {
        for (Node * j = first; compareFunc( (*i).Value(), (*j).Value() ); (*j).m_pNext) {
            if (compareFunc( (*i).Value(), (*j).Value() )) {
                T value = (*i).Value();
				(*i).m_tValue = (*j).Value();
				(*j).m_tValue = value;
            }
        }
    }
}

#endif
