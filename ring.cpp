#include <cstdlib>
#include "ring.h"
struct Node
{
    Data datum;
    Node *next;
    Node(Data datum): datum(datum), next(0) {}
    ~Node()
    {
        datum = 0;
        next = 0;
    }
};

class Ring::RingImplementation
{
public:
    RingImplementation();
    ~RingImplementation();

    void add (Data datum);
    Data del();
    bool isEmpty();
    void Clear();
    bool Ukazatel(int n);
    void Random();

    bool nextDatum(bool firstTime, Data &datum) const;
private:
    int n;
    Node *top;
};

////////////  Ring //////////////

Ring::Ring():
    pimpl(0)
{
    pimpl = new RingImplementation;
}

Ring::~Ring()
{
    delete pimpl;
    pimpl = 0;
}

void Ring::add(Data datum)
{
    pimpl->add(datum);
}

Data Ring::del()
{
    return pimpl->del();
}

bool Ring::isEmpty()
{
    return pimpl->isEmpty();
}

void Ring::Clear()
{
    pimpl->Clear();
}
bool Ring::Ukazatel(int n)
{
    return pimpl->Ukazatel(n);
}
void Ring::Random()
{
    pimpl->Random();
}

bool Ring::nextDatum(bool firstTime, Data &datum) const
{
    return pimpl->nextDatum(firstTime, datum);
}


///// RingImplementation ////////

Ring::RingImplementation::RingImplementation():
    n(0), top(0)
{}

Ring::RingImplementation::~RingImplementation()
{
    Clear();
}

void Ring::RingImplementation::add(Data datum)
{
    Node *p = new Node(datum);
    if (top)
    {
        p->next = top->next;
        top->next = p;
    }
    else
    {
        top = p;
        p->next = top;
    }
    p = 0;
	n++;
}

Data Ring::RingImplementation::del()
{
    Data d;
    if(top==top->next)
    {
        d = top->datum;
        delete top;
        top = 0;
    }
    else
    {
        Node *p = top->next;
        top->next = p->next;
        d = p->datum;
        delete p;
        p = 0;
    }
    --n;
    return d;
}

bool Ring::RingImplementation::isEmpty()
{
    return !top;
}

void Ring::RingImplementation::Clear()
{
    while (top)
        del();

}
bool Ring::RingImplementation::Ukazatel(int n)
{
	if(n>=0)
	{
		while(n--)
			top = top->next;
		return true;
	}
	else
		return false;
}

void Ring::RingImplementation::Random()
{
    int d, r, k=n;
    while(k--)
    {
		r = rand()%n;
		Ukazatel(r);
		d = del();
		r = rand()%n;
		Ukazatel(r);
		add(d);
    }
}

bool Ring::RingImplementation::nextDatum(bool firstTime, Data &datum) const
{
    static Node *cur = 0;

    bool result = true;

    if(firstTime)
    {
        cur = top;
	}
	else
	{
		if (cur == top) result = false;
	}

    if(result)
    {
        datum = cur->datum;
        cur = cur->next;
    }

    return result;
}


