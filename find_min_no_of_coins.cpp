int findMinimumCoins(int amount) 
{
    int currency[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int i=0, min_coins=0;
    while(amount>0){
        if(amount < currency[i]) i++;
        else if(amount >= currency[i]){
            amount = amount - currency[i];
            min_coins++;
        }
    }
    return min_coins;
}
