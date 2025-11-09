#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value/ a.weight;
    double r2 = (double)b.value/b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items)
{
    sort(items.begin(),items.end(),cmp);

    double totalValue = 0.0;

    for(auto &i : items)
    {
        if(W == 0) break;
        if(i.weight <= W)
        {
            totalValue += i.value;
            W -= i.weight;
        }
        else
        {
            totalValue += i.value * ((double)W/i.weight);
            W = 0;
        }
    }
    return totalValue;
}

int main()
{
    int n,W;
    cout<<"Enter number of items:";
    cin>>n;

    vector<Item> items(n);
    cout<<"Enter weight and value of each item:\n";
    for(int i = 0; i < n ; i++)
    {
        cin>>items[i].weight>>items[i].value;
    }

    cout<<"Enter maximum weight capacity:";
    cin>>W;

    cout<<"Maximum value in knapsack = "<<fractionalKnapsack(W,items);

    return 0;
}