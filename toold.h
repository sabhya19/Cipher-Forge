#ifndef TOOLD_H
#define TOOLD_H
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;
string decode(string msg){
    string str="";
            if(msg[0] == '$') {
                str+= " ";
                return str;
            }
            if(msg[0]== '%'){
                str+= ".";
                return str;
            }
            if(msg[0]== '@'){
                str+= ",";
                return str;
            }
            if(msg[0]== '&'){
                str+= "?";
                return str;
            }
            if(msg[0]== '#'){
                str+= "!";
                return str;
            }
            int size = msg[0] - '0';
            int adjMatrix[size][size], j = 0, k = 0, count = 0, adjList[size], binary[7], pos = 0, xorval = 0, ascii, flag;
            for(int i = 1; i < msg.length(); i++) {
                if(i == msg.length() - 1) {
                    flag = msg[i] - '0';
                    continue;
                }
                if(msg[i] == ' ') {
                    continue;
                }
                if(count%size == 0 && count) {
                    count = 0;
                    j++;
                    k = 0;
                }
                adjMatrix[j][k] = msg[i] - '0';
                count++;
                k++;
            }
            for(int i = 0; i < size; i++) {
                adjList[i] = adjMatrix[i][(i + 1)%size];
                binary[pos] = 1;
                pos++;
                for(int j = 0; j < adjList[i] - 1; j++) {
                    binary[pos] = 0;
                    pos++;
                }
            }
            for(int i = 6; i >= 0; i--) {
                xorval += pow(2, (6 - i)) * binary[i];
            }
            ascii = xorval^32;
            char c = ascii;
            if(flag == 0) {
                c = c - 'A' + 'a';
            }
            str+= c;
        return str;
}
#endif // TOOLD_H
