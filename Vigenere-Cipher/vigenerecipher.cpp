#include<bits/stdc++.h>
using namespace std;

string generateKey(string str, string key){
	int x = str.size();
	for (int i = 0; ; i++){
		if (x == i){
            i = 0;
        }	
		if (key.size() == str.size()){
            break;
        }
		key.push_back(key[i]);
	}
	return key;
}

string Enkripsi(string str, string key){
	string ciphertext;
	for (int i = 0; i < str.size(); i++){
        ciphertext += char(int(str[i] + key[i] + 26)%26 + 'A');
    }
	return ciphertext;
}

string Dekripsi(string ciphertext, string key){
	string plaintext;
	for (int i = 0; i < ciphertext.size(); i++){
        plaintext += char(int(ciphertext[i] - key[i] + 26)%26 + 'A'); 
	}
	return plaintext;
}

int main(){
	string str;
	string key;

    cout<<"Masukkan Plaintext: "; 
    getline(cin,str);
	cout<<"Masukkan Key: ";
    cin>>key;

    string extend_key = generateKey(str, key);
	string ciphertext = Enkripsi(str,extend_key);

	cout << "Enkripsi : "<< ciphertext << "\n";
	cout << "Plaintext : "<< Dekripsi(ciphertext, extend_key);
	return 0;
}
