#ifndef RING_H
#define RING_H

typedef int Data;

class Ring
{
public:
    Ring();
    ~Ring();

    void add (Data datum);
    Data del();
    bool isEmpty();
    void Clear();
    bool Ukazatel(int n);
    void Random();

protected:
	bool nextDatum(bool firstTime, Data &datum) const;

private:
    class RingImplementation;
    RingImplementation *pimpl;
};

#endif // RING_H
