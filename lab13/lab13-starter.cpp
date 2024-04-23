/**********************
 * Student Author Name: Khi Kidman
 * Lab Section: 3pm
 * ******************/


#include<string> 
#include<vector>
#include<iostream>

using namespace std;


class Stock {
	private:
		string symbol;
		int sharesOwned;
		double totalCost;  // Total cost of the shares owned
		double totalProceed; //Total proceed of the shares that sold
		

	public:
		Stock(const string& symbol);

		// Getter functions
		string getSymbol() const { return symbol; }
		int getSharesOwned() const { return sharesOwned; }
		double getTotalCost() const { return totalCost; }
		double getTotalProceed() const { return totalProceed; }

		//Selling and Buying shares
		void buyShares(int shares, double price);
		void sellShares(int shares, double price);
};

//Constructor for the stock. The default sharesOwned, totalCost, and totalProceed are zero
Stock::Stock(const string& symbol) {
	this->symbol = symbol;
	this->sharesOwned = 0;
	this->totalCost = 0.0;
	this->totalProceed = 0.0;
}



// Buy shares, when we buy shared we increase the sharedOwned and add to totalCost
void Stock::buyShares(int shares, double price) {
	if (shares > 0) {
		sharesOwned += shares;
		totalCost += shares * price;
	}
}

// Sell shares, when we sell shares we decrease the sharesOwned and add to totalProceed 
void Stock:: sellShares(int shares, double price) {
	this->sharesOwned -= shares;
	this->totalProceed += shares * price;
}


class Portfolio {
	private:
		vector<Stock*> stocks;

	public:
		// Buy stock
		void buyStock(const string& symbol, int shares, double price);

		// Sell stock
		void sellStock(const string& symbol, int shares, double price);
	   

		// View portfolio
		void viewPortfolio() const;
};


void Portfolio::buyStock(const string& symbol, int shares, double price) {
	// It the stock is already there buy more shares
	for (Stock* stock : stocks) {
		if (stock->getSymbol() == symbol) {
			stock->buyShares(shares, price);
			return;
		}
	}
	// If the stock is not already in the portfolio, create new stock, add it, and buy more share
	Stock* new_stock = new Stock(symbol);
	new_stock->buyShares(shares, price);
	stocks.push_back(new_stock);
	return;
}

// Sell stock
void Portfolio::sellStock(const string& symbol, int shares, double price) {
	//complete me
	for (Stock* stock : stocks) {
		if (stock->getSymbol() == symbol) {
			stock->sellShares(shares, price);
			return;
		}
	}
}

// View portfolio
void Portfolio::viewPortfolio() const {
	//complete me
	cout << "Portfolio" << endl;
	for (Stock* stock : stocks) {
		cout << "Symbol: " << stock->getSymbol() << ", Shares Owned: " << stock->getSharesOwned() << ", Total Cost: $" << stock->getTotalCost() << ", Total Proceeds: $" << stock->getTotalProceed() << endl; 
	}
}


int main() {
	Portfolio portfolio;

	// Simulate buying and selling stocks
	portfolio.buyStock("AAPL", 10, 150.0);
	portfolio.buyStock("GOOG", 5, 160.0);


	// View portfolio and total profit
	portfolio.viewPortfolio();

	
	portfolio.sellStock("AAPL", 5, 175.0);
	portfolio.sellStock("GOOG", 1, 145.0);
	portfolio.buyStock("MSFT", 2, 425.0);
	portfolio.viewPortfolio();

	
	portfolio.sellStock("GOOG", 4, 120.0);
	portfolio.viewPortfolio();

    return 0;
}

