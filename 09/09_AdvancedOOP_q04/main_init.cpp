#include "answer.h"
#include "utils.h"

// const string CHECKED_FILENAME = "answer.h";
// const int NO_IGNORED_LINES = 5;

int main() {
	Animal** bagOfAnimals = new Animal*[5]{new Cat(Tom), 
                                        	new Dog(Husky), 
                                        	new Cat(Leo),
                                        	new Dog(Thomas), 
                                        	new Cat(Neko)};
	for(int i = 0; i < 5; i++) {
		bagOfAnimals[i]->sound();
   	}

	return 0;
}
