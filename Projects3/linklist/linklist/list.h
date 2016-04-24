#include "Node.h"
class unsotredType {


	public:
		unsotredType();
		void MakeEmpty();
		bool IsFull()const;
		int Getlength() const;
		void InsertItem(int item);
		void DeleteItem(int item);
		void show();
		~unsotredType();
private:
	int length;
	NodeType* start;

};
