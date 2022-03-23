#ifndef CODA_H
#define CODA_H

template <class T>
class coda;

template < class T >
class cella
{
public:
    friend class coda<T>;
    T v;
    cella *next;
};

template <class T>
class coda
{
    public:
        coda();
        bool codavuota();
        bool finecoda();
        T leggicoda();
        void fuoricoda();
        void incoda(T);
        void stampa();


        coda& operator=(const coda& other);

        int lunghezza;
        cella<T> *testa;
        cella<T> *fondo;
};

template <class T>
coda<T>::coda()
{
    lunghezza=0;
    testa=nullptr;
    fondo=nullptr;
}


template <class T>
bool coda<T>::codavuota()
{
    return (lunghezza==0);
}

template <class T>
T coda<T>::leggicoda()
{
    if(!codavuota())
        return testa->v;
}

template <class T>
void coda<T>::fuoricoda()
{
    cella<T> *temp = new cella<T>;
    temp = testa;
    testa = testa->next;
    delete temp;
    lunghezza--;
}

template <class T>
void coda<T>::incoda(T elem)
{
    cella<T> *temp = new cella<T>;
    if(codavuota()) {
        fondo=testa=temp;
    } else {
        fondo->next=temp;
    }
    temp->v=elem;
    temp->next=NULL;
    fondo=temp;
    lunghezza++;


// 1 testa = 1 fondo = 1
// 1 2 testa=1 fondo = 2
// 1 2 3 testa=1 fondo=3

}

template <class T>
bool coda<T>::finecoda()
{
    testa=testa->next;
    return true;
}

template <class T>
void coda<T>::stampa()
{
    while(!finecoda()) {
        T temp = leggicoda();
        std::cout << "ciao";
    }
}

#endif // CODA_H
