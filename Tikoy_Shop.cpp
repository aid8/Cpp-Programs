#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
	const int max_order = 3;
	int money, sizePick, orderCount, totalAmount = 0, totalOrders = max_order;
	char flavorPick = ' ', ansPick = ' ';
	map<char, string> flavors = {
		{'C',"Classic"},
		{'U',"UBE"},
		{'P',"Pandan"},
		{'B',"Butterscotch"}
	};
	map<int, pair<int,string>> prices = {
		{1,make_pair(100,"Petite")},
		{2,make_pair(200,"Large")},
		{3,make_pair(300,"Party")}
	};
	vector<pair<int,pair<char,int>>> tikoys; //<ordercount, <flavor, price>>
	
	cout << "----Same Flavor - Same Size TIKOY 2020. Buy 1 Take 1----\n";
	cout << "--------------------------MENU--------------------------\n";
	cout << "Flavors:\n";
	for(auto itf = flavors.begin(); itf != flavors.end(); itf++) 
		cout << "\t[" << itf->first << "]: " << itf->second << "\n";
	cout << "Prices:\n";
	for(auto itp = prices.begin(); itp != prices.end(); itp++) 
		cout << "\t[" << itp->first << "]: " << itp->second.second << "\n";
	
	cout << "------------------------ORDERING------------------------\n";
	while(totalOrders > 0){
		while(true){
			cout << "Please Enter the flavor letter: "; cin >> flavorPick;
			if(flavors.find(toupper(flavorPick)) == flavors.end()) 
				cout << "Please Enter a valid letter!\n";
			else break;
		}
		while(true){
			cout << "Please Enter the size number: "; cin >> sizePick;
			if(prices.find(toupper(sizePick)) == prices.end()) 
				cout << "Please Enter a valid number!\n";
			else break;
		}
		
		cout << "How many type of order of this do you want? "; cin >> orderCount;
		while(totalOrders - orderCount < 0 || orderCount < 0){
			if(totalOrders - orderCount < 0) cout << "The maximum size that you can order is " << max_order << "!\n";
			cout << "Please Enter a valid amount!\n";
			cout << "How many type of order of this do you want? (Input 0 to cancel) "; cin >> orderCount;
		}
		totalAmount += prices[sizePick].first * orderCount;
		if(orderCount > 0) tikoys.push_back(make_pair(orderCount,make_pair(flavorPick,sizePick)));
		totalOrders -= orderCount;
		
		if(totalOrders > 0){
			cout << "Do you want to order again? [Y/N]: "; cin >> ansPick;
			while(toupper(ansPick) != 'Y' && toupper(ansPick) != 'N'){
				cout << "Please enter a valid answer! [Y/N]: "; cin >> ansPick;
			}
			if(toupper(ansPick) == 'N') break;
		}
		cout << "\n";
	}
	cout << "------------------------SUMMARY-------------------------\n";
	for(auto i : tikoys){
		cout << i.first*2 << " Tikoys of flavor " << flavors[toupper(i.second.first)] << " and size of " 
		<< prices[i.second.second].second << " = " << prices[i.second.second].first * i.first << "\n";
	}
	cout << "Total Transaction: " << totalAmount << "\n";
	cout << "--------------------------------------------------------\n";
	cout << "Please Enter the amount of money: "; cin >> money;
	money -= totalAmount;
	if(money > 0){
		cout << "Change: " << money << "\n";
		cout << "Thank you for buying tikoys in our store. Please Come Again!\n";
	}
	else cout << "Sorry! You do not have enough money to buy the Tikoys! Please Come Again!\n";
	tikoys.clear();
	return 0;
}
