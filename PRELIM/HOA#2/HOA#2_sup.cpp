#include<iostream>
#include <string>

class GroceryItem {
	private:
		std::string name;
		int price;
		int quantity;
	public:
		virtual ~GroceryItem() {}
		virtual void display() = 0;
		virtual int calculateCost() = 0;
 };

class Fruit : public GroceryItem{
	private:
    	std::string fruitName;
    	int fruit_price;
    	int Fquantity;
    
	 public:
//constructor
    	Fruit( std::string n, int p, int q ){
    	fruitName = n;
    	fruit_price = p;
    	Fquantity = q;
        std::cout << "Constructor Called. Fruit: " << fruitName <<  std::endl;
        
    }

//deconstructor
~Fruit (){
    std::cout << "Desconstructor Called. What was Deleted:" << fruitName << std::endl;
}

//Copyconstructor
Fruit (const Fruit &copyFruit) {
    fruitName = copyFruit.fruitName;
    fruit_price = copyFruit.fruit_price;
    Fquantity = copyFruit.Fquantity;
    std::cout << "Copy Constructor Called. Copied: " << fruitName << std::endl;
}

//overwrites an existing object - copy assignment
Fruit& operator=(const Fruit &copyFruit ) {
    std::cout << "Copy Assignment Called. Assigning: " << copyFruit.fruitName << "\n\n\n";
    if (this != &copyFruit) {
        fruitName = copyFruit.fruitName;
        fruit_price = copyFruit.fruit_price;
        Fquantity = copyFruit.Fquantity;
    }
    return *this;
}

int calculateCost() override{
    return fruit_price*Fquantity;
}

void display() override{
    std::cout << "\nWhat Fruit: " << fruitName << "  Price: PHP " << fruit_price << std::endl;
    std::cout << "How many?: " << Fquantity << "\n";
    std::cout << "Total: PHP" << calculateCost() << std::endl << std::endl;
}

};

//class vegetables
class Vegetables : public GroceryItem{
	private:
    	std::string vegName;
    	int veg_price;
    	int Vquantity;
    	
	 public:
//constructor
    	Vegetables( std::string n, int p, int q ){
    		vegName = n;
    		veg_price = p;
    		Vquantity = q;
        	std::cout << "Constructor Called. Vegetables: " << vegName <<  std::endl;
    }

//deconstructor
~Vegetables (){
    std::cout << "Desconstructor Called. What was Deleted: " << vegName << std::endl;
}

//Copyconstructor
Vegetables (const Vegetables &copyVegetables) {
    std::cout << "Copy Constructor Called. Copied: " << vegName << std::endl;
    vegName = copyVegetables.vegName;
    veg_price = copyVegetables.veg_price;
    Vquantity = copyVegetables.Vquantity;
}

//overwrites an existing object - copy assignment
Vegetables& operator=(const Vegetables &copyVegetables ) {
    std::cout << "Copy Assignment Called. Assigning: " << copyVegetables.vegName << "\n\n\n";
    if (this != &copyVegetables) {
        vegName = copyVegetables.vegName;
        veg_price = copyVegetables.veg_price;
        Vquantity = copyVegetables.Vquantity;
    }
    return *this;
}

int calculateCost() override{
    return veg_price*Vquantity;
}

void display() override{
    std::cout << "\nWhat Vegetables: " << vegName << "  Price: PHP" << veg_price << std::endl;
    std::cout << "How many?: " << Vquantity << std::endl;
    std::cout << "Total: PHP" << calculateCost() << "\n\n";
}

};


int main () {
    GroceryItem* list[10];

    list[0] = new Fruit("Orange", 10, 1);
    list[1] = new Fruit("Apple", 150, 7);
    list[2] = new Fruit("Peach", 500, 20);
    list[3] = new Fruit("Lychee", 100, 30);
    list[4] = new Fruit("Banana", 250, 20);
	list[5] = new Vegetables ("Potato", 10, 1);
	list[6] = new Vegetables ("Kangkong", 10, 1);
	list[7] = new Vegetables ("Sitaw", 25, 1);
	list[8] = new Vegetables ("Gabi", 90, 3);
	list[9] = new Vegetables ("Carrots", 100, 9);
	
    for (int i = 0; i < 10; i++) {
        if(list[i] != nullptr) {
            list[i] ->display();
        }
    }

    int totalSum = 0;
    for (int i = 0; i < 10; i++){
        if (list[i] != nullptr) {
            totalSum += list[i] ->calculateCost();
        }
    }

    std::cout << "\n\nThe Whole Total: PHP " << totalSum << "\n\n\n";
    
    Fruit originalFruit("Orange", 10, 1);
    Fruit emptyFruit("PlaceHolder", 45, 5);
    emptyFruit = originalFruit;

    Vegetables originalVegetables("Gabi", 90, 3);
    Vegetables emptyVegetables("PlaceHolder",85, 5);
    emptyVegetables = originalVegetables;

    delete list[5];

    list[5] = nullptr;
    delete list[9];
    delete list[8];
    delete list[7];
    delete list[6];
    delete list[5];
    delete list[4];
    delete list[3];
    delete list[2];
    delete list[1];
    delete list[0];
    
    return 0;


}
