#include <iostream>
#include <fstream>
#include <string.h>
#include <vector> 
#include <string> 
#include <algorithm> 
#include <map>
#include <unordered_set> 

using namespace std;

void displayFile(const string & filename){
    ifstream file(filename);
    string line; 

    if(file.is_open()){
        std::cout << "File Contains: " << endl; 
        while(getline(file,line)) {
            std::cout << line << endl; 
        }
        file.close();
    } else {
        std::cout << "File failed to open." << endl; 
    }
}


//take a string and 2 char; 1st one is replaced 
string shift(string str, char a, char b){
    int length = str.length(); 

    for (int i = 0; i < length; ++i){
        if(str[i] == a){
            str[i] = b; 
        } 

        else if (str[i] == b){
            str[i] = a;
        }
    }
    return str; 
}

int charFrequency(vector <char> vec, char character){
    ///frequences of the character in a vector 
    int frequency = count(vec.begin(), vec.end(), character);
    return frequency; 

}

int cipherLength(const string & filename){
    ifstream file(filename);
    int length = 0; 

    char ch; 
    if (!file){
        cout << "File Open Error" << endl; 
    } else {
        while(file.get(ch)){
            if(std::isalpha(ch)){
                length++;
                }    
        }
    }
    return length; 
}

void generateKey(string str){
    map<char, int> key;

    int count = 0; 
    for (char c : str){
        if(std::isalpha(c)){
            key[c]++;
        }
    }

    for (auto& it : key){
        std::cout << it.first << ' ' << it.second << endl; }
}

int heuristic(const std::string& str, const std::unordered_set<std::string>& dict) {
    int heuristic = 0;
    const int minWordLength = 3; 
    const int maxWordLength = 10; 

    for (int i = 0; i < str.length(); ++i) {
        for (int j = i + minWordLength; j <= str.length() && (j - i) <= maxWordLength; ++j) {
            std::string substring = str.substr(i, j - i);

            if (dict.find(substring) != dict.end()) {
                heuristic++;
                std::cout << "Found valid word: '" << substring << "'" << std::endl;
            }
        }
    }

    return heuristic; // Return the final heuristic value if the target wasn't reached
}

int main()
{
    ifstream dictionary("dictionary.txt");
    unordered_set<string>dictVector; 

    if(!dictionary){
        std::cout << "Unable to open file" << endl; 
        return 1; 
    } else {
        string word;
        while(getline(dictionary, word)){
            dictVector.insert(word);
            }
        }
        dictionary.close();
    
       
    ifstream cipher("ciphertext.txt");  
    vector <char> charVector; 

    if(!cipher){
        std::cout << "Unable to open file." << endl; 
        return 1; 
    } else {
        char ch;
        while(cipher.get(ch)){
            charVector.push_back(ch); 
        }
    cipher.close();
    }

    string cipherText("VSRQJHEREVTXDUHSDQWU"); //turn the vector of characters in a string 
   
    int validWord = 0; 
    char c1, c2; 
    while (validWord < 300){ 
        std::cout << "Current Ciphertext: " << endl; 
        std::cout << cipherText << endl; 

        std::cout << "Current Key: " << endl;
        generateKey(cipherText);

        std::cout << "Please Enter 1. Character to be replaced, and 2. Character Replacing: " << endl; 
        cin >> c1 >> c2; 
        cipherText = shift(cipherText, c1, c2); 

        validWord = heuristic(cipherText, dictVector);
        cout << "Heuristic Value: " << validWord << endl; 

        string decryptedText = "The United States was at peace with that nation and, at the solicitation of Japan, was still in conversation with its government and its emperor, looking toward the maintenance of peace in the Pacific. Indeed, one hour after Japanese air squadrons had commenced bombing in Oahu, the Japanese ambassador to the United States and his colleague delivered to the Secretary of State a formal reply to a recent American message. While this reply stated that it seemed useless to continue the existing diplomatic negotiations, it contained no threat or hint of war or armed attack.";

    }  

    return 0; 
} 