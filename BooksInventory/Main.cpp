#include <iostream>
#include <string.h>
#include <stdlib.h>

class book {
private:
	char* publisher, * author, * title;
		float* price;
		int* stock;
		int* wallet;
public:
	book() {
		publisher = new char[20];
		author = new char[20];
		title = new char[20];
		price = new float;
		stock = new int;
		wallet = new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	void buybook();
	int search(char[20], char[20]);

};



void book::feeddata() {
	std::cin.ignore();
	std::cout << "Enter author of book: ";
	std::cin.getline(author, 20);
	std::cout << "Enter a title: ";
	std::cin.getline(title, 20);
	std::cout << "Enter a publisher: ";
	std::cin.getline(publisher, 20);
	std::cout << "Enter price for a book: ";
	std::cin >> *price;
	std::cout << "Number queue on stock: ";
	std::cin >> *stock;
	std::cout << "Enter the amount: ";
	std::cin >> *wallet;
	std::cout << "In ur wallet: " << *wallet;
}

void book::editdata() {
	std::cout << "Enter author of book: ";
	std::cin.getline(author, 20);
	std::cout << "Enter a title: ";
	std::cin.getline(title, 20);
	std::cout << "Enter a publisher: ";
	std::cin.getline(publisher, 20);
	std::cout << "Enter price for a book: ";
	std::cin >> *price;
	std::cout << "Number queue on stock: ";
	std::cin >> *stock;
	
	
}

void book::showdata() {
	std::cout << "\nAuthor name: "<< *author;
	std::cout << "\nTitle: " << *title;
	std::cout << "\nPublisher: " << *publisher;
	std::cout << "\nPrice: " << *price;
	std::cout << "\nNumber queue on stock: " << *stock;
	std::cout << "\nMoney in ur wallet: " << *wallet;
	
}
int book::search(char abuy[20], char tbuy[20]) {
	if (strcmp(abuy, author) == 0 && strcmp(tbuy, title) == 0)
		return 1;
	else return 0;
}

void book::buybook() {
	int count;
	std::cout << "\nEnter Number of books to buy: ";
	std::cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;
		std::cout << "Books has buy succesfully" << std::endl;
		std::cout << "Amount Rub: " << (*price) * count;
		
	}
	else
		std::cout << "Sorry, books has not on stock :(";
	
	if (*wallet >= *price) {
		*wallet = (*wallet) - (*price);
		std::cout << "\nU have: " << *wallet;
	}
	else
		std::cout << "\nU have no money!";
  
}

int main()
{
	book* B[20];
	int i = 0, t, choice;
	float w = 0;
	char authorbuy[20], titlebuy[20];

	while (1) {
	std::cout << "\n\n\tWELCOME TO LIBRARY!!!";
	std::cout << "\n\n\tMENU";
	std::cout << "\n\n1. Entry of new book";
	std::cout << "\n\n2. Buy book";
	std::cout << "\n\n3. Search book";
	std::cout << "\n\n4. Show details of book";
	std::cout << "\n\n5. EXIT";
	std::cout << "\n\nEnter ur choice: ";
	std::cin >> choice;
	
		switch (choice) {
		case 1:
			B[i] = new book;
			B[i]->feeddata();
			i++;
			break;
		case 2:
			std::cin.ignore();
			std::cout << "\nEnter author name: ";
			std::cin.getline(authorbuy, 20);
			std::cout << "\nEnter book name: ";
			std::cin.getline(titlebuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(authorbuy, titlebuy)) {
					B[t]->buybook();
					break;
				}

			}
			if (t == 1) 
				std::cout << "Book is not a stock";
			
			break;
		case 3:
			std::cin.ignore();
			std::cout << "\nEnter author name: ";
			std::cin.getline(authorbuy, 20);
			std::cout << "\nEnter book name: ";
			std::cin.getline(titlebuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(authorbuy, titlebuy)) {
					B[t]->showdata();
					break;
				}
			}
			if (t == i) 
				std::cout << "Book has not found";
			
			break;
		case 4:

			std::cin.ignore();
			std::cout << "\nEnter author name: ";
			std::cin.getline(authorbuy, 20);
			std::cout << "\nEnter book name: ";
			std::cin.getline(titlebuy, 20);

			for (t = 0; t < i; t++) {
				if (B[t]->search(authorbuy, titlebuy)) {
					B[t]->editdata();
					break;
				}

			}
			if (t == i) 
				std::cout << "Book is not a stock";
				break;

		case 5:
			exit(0);
		default: std::cout << "\nInvalid number of choice!";
			
		}
		
	}
	return 0;

	
}