/*
    Nama      : Rifqi Akmal Fauzi
    NPM       : 140810200021
    Kelas     : A
    Deskripsi : Code Shift cipher
*/
#include<bits/stdc++.h>
using namespace std;

string encrypt(string text, int k){
    string hasil = "";
    for(int i = 0; i < text.length(); i++){
        if(text[i] != ' '){
            if(isupper(text[i])){
                hasil += char(int(text[i] - 'A' + k )%26 + 'A');
            }else{
                hasil += char(int(text[i] - 'a' + k )%26 + 'a');
            } 
        }else{
            hasil += text[i];
        } 
    }
    return hasil;
}

string decrypt(string text, int k){
    string hasil = " ";
    for(int i = 0; i < text.length(); i++){
        if(text[i] != ' '){
            if(isupper(text[i])){
                hasil += char(int(text[i] - 'A' - k + 26)%26 + 'A');
            }else{
                hasil += char(int(text[i] - 'a' - k + 26)%26 + 'a');
            } 
        }else{
            hasil += text[i];
        } 
    }
    return hasil;
}

int main(){
    int k, a;
    string text;
    cout<<"\nMasukkan kalimat yang ingin dienkripsi : ";
    getline(cin, text);
    cout<<"\nMasukkan key : ";
    cin>>k;
    string text_enkripsi = encrypt(text, k);
    cout<<"\nKalimat enkripsi : " << text_enkripsi;
    cout<<"\nKalimat dekripsi :" << decrypt(text_enkripsi, k);
}