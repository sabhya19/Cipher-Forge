#ifndef TOOLE_H
#define TOOLE_H
#include<iostream>
#include<string>
#include<cmath>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
class Node {
    public:
        int data;
        Node* next;
};

class Buffer{
    public:
        char key[26] = {NULL};
        Node* head[26] = {NULL};
        int index(char c) {
            for(int i = 0; i < 26; i++) {
                if(c == key[i]) {
                    return i;
                }
            }
            return -1;
        }
};

Buffer buf;
Node* encodeMatrix(char c) {
    int ascii = c, binary_32 = 32;
    int xorval = ascii^binary_32, k = 0;
    int temp = xorval;
    while(temp) {
        k += temp & 1;
        temp >>= 1;
    }
    int n = log2(xorval);
    int binary[n], pos = n - 1;
    while(xorval){
        binary[pos] = xorval%2;
        xorval/= 2;
        pos--;
    }
    pos = 0;
    int adjList[k], adjMatrix[k][k];
    for(int i = 0; i < k; i++) {
        int count = 1;
        while(pos < n && binary[pos] != 1) {
            pos++;
            count++;
        }
        adjList[i] = count;
        pos++;
    }

    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    for(int i = 0; i < k; i++) {
        adjMatrix[i][(i + 1)%k] = adjList[i];
        adjMatrix[(i + 1)%k][i] = adjList[i];
    }

    Node* head = new Node();
    Node* curr = new Node();
    curr->data = k;
    curr->next = NULL;
    head = curr;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            Node* temp = new Node();
            temp->data = adjMatrix[i][j];
            curr->next = temp;
            curr = temp;
            temp->next = NULL;
        }
    }
    return head;
}

bool encodeBuffer(QString str, QString & fl) {
    std::string s = str.toLocal8Bit().constData();
    QString ext{".txt"};
    QString file = fl + ext;
    QFile qf(file);
    qf.open(QFile::Truncate | QFile::WriteOnly);
    QTextStream output(&qf);
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ') {
            output << "$\n";
            continue;
        }
        if(s[i] == '.'){
            output<< "%\n";
            continue;
        }
        if(s[i]== ','){
            output<< "@\n";
            continue;
        }
        if(s[i]== '?'){
            output<< "&\n";
            continue;
        }
        if(s[i]== '!'){
            output<< "#\n";
            continue;
        }
        int flag = 1;
        if(s[i] >= 97 && s[i] <= 122) {
            s[i] = s[i] - 'a' + 'A';
            flag = 0;
        }
        int pos = buf.index(s[i]);
        if(pos != -1) {
            //output the linked list in the file.
            Node* ptr = buf.head[pos];
            while(ptr != NULL) {
                output << ptr->data; //<< " ";
                ptr = ptr->next;
            }
            output << flag;
            output << "\n";
        }
        else {
            pos = s[i] - 'A';
            buf.key[pos] = s[i];
            buf.head[pos] = encodeMatrix(s[i]);
            Node* ptr = buf.head[pos];
            while(ptr != NULL) {
                output << ptr->data;// << " ";
                ptr = ptr->next;
            }
            output << flag;
            output << "\n";
        }
    }
    qf.flush();
    qf.close();
    return true;
}
#endif // TOOLE_H
