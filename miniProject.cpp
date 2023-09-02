#include<bits/stdc++.h>
using namespace std;

void rearrangeMessage(string &str) {

    reverse(str.begin(),str.end());

    for(int i=0; i<str.length()-1; i+=2) {
        if(i+1 < str.length()) {
            swap(str[i],str[i+1]);
        }
    }

    int magicNumber = 10;

    for(int i=0; i<str.length(); i++) {
        if(int(str[i]) >= 117) {
            str[i] = ((str[i]+ magicNumber)%126 + 32);
        }
        else {
            str[i] = (str[i] + magicNumber);
        }
    }
}

void rearrangeKey(vector<int> &key) {

    reverse(key.begin(), key.end());

    for(int i=0; i<key.size()-1; i+=2) {
        if(i+1 < key.size()) {
            swap(key[i],key[i+1]);
        }
    }
}

vector<int> keyGeneration(int messageLength) {
    
    vector<int> key(2*messageLength);
    
    srand((unsigned) time(NULL));

    for(int i=0; i<2*messageLength; i++) {
        int x = 32 + (rand()%(126-32+1));
        key[i] = x;
    }

    return key;
}

int characterShift(int front, int back) {
    int frontDigitProduct = 1, backDigitProduct = 1;
    
    while(front) {
        int lastDigit = front%10;
        frontDigitProduct *= lastDigit;
        front /= 10;
    }

    while(back) {
        int lastDigit = back%10;
        backDigitProduct *= lastDigit;
        back /= 10;
    }

    return (frontDigitProduct + backDigitProduct);
}

void encode(string &message, vector<int> key) {

    rearrangeMessage(message);
    rearrangeKey(key);

    cout<<"msg in encode : "<<message<<"\n";
    cout<<"final key : ";
    for(auto x : key) {
        cout<<x<<" ";
    }


    int front = 0;
    int back = key.size()-1;

    while(front < back) {

        int shift = characterShift(key[front],key[back]);
        
        if(shift > 94) {
            shift = shift%94 + 32;
        }
        else {
            shift = shift%126;// Not required
        }
        
        if(message[front] + shift >= 126)
            message[front] = (message[front] + shift)%126 + 32;
            
        else
        message[front] = (message[front] + shift)%126;

        front++;
        back--;
    }

}

void decode() {

}

int main() {

    string message = "al u";
    // vector<int> v = {86,101,32,108,67,84,77,125};
    // vector <int> v = {97,66,95,46,76,96,87,44};
    // vector <int> v = {72,36,42,107,118,80,88,75} // c.t = |Rs_

    encode(message,keyGeneration(message.length()));

    cout<<endl<<message;

    return 0;
}