#include <iostream>
#include "ring.h"

using namespace std;

class ConsoleRing: public Ring
{
    public:
        void output(ostream &out) const;
};

ostream &operator<<(ostream &out, const ConsoleRing &ring);

int main()
{
    ConsoleRing ring;
    for (int i=1; i<=36; i++)
    {
		ring.add(i);
	}
    cout << ring << endl;

    ring.Random();
    cout << ring << endl;
    return 0;
}

ostream &operator<<(ostream &out, const ConsoleRing &ring)
{
    ring.output(out);
    return out;
}

void ConsoleRing::output(ostream &out) const
{
    Data datum;

    if(nextDatum(true, datum))
        out << datum << " ";

    while(nextDatum(false, datum))
        out << datum << " ";
}

