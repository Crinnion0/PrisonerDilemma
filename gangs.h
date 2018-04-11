#include "strategy.h"
#include "codeExecute.h"

class gangs
{
public:
	gangs(vector<strategy> a );
	~gangs();




	vector<strategy> getGang() { return gang; }
	void setGang(vector<strategy> a);




protected:

	vector<strategy> gang;

};

