#include <bits/stdc++.h>
using namespace std;

class Server{
    Protected:
        string serverName;
    Public:
        Server(string name){
            serverName=name;
            cout<<"[Constructing Server] Server Name set to "<<serverName<<endl;
        }
        ~Server(){
            cout<<"Destruct Server"<<endl;
        }
        void ping(){
            cout<<"Pinging Server: "<<serverName<<endl;
        }
};

class WebServer: public Server{
    protected:
        int maxTraffic;
    public:
        WebServer(string name,int traffic): Server(name){
            maxTraffic=traffic;
            cout<<"[Constructing WebServer] Max Traffic set to "<<maxTraffic<<" requests/sec."<<endl;
        }
        ~WebServer(){
            cout<<"Destruct WebServer"<<endl;
        } 
        void serveHTML(){
            cout<<"Serving HTML content from "<<serverName<<endl;
        } 
};

class DatabaseServer: public Server{
    protected:
        string dbType;
    public:
        DatabaseServer(string name,string type): Server(name){
            dbType=type;
            cout<<"[Constructing DatabaseServer] Database Type set to "<<dbType<<endl;
        }     
        ~DatabaseServer(){
            cout<<"Destruct DatabaseServer"<<endl;
        }
        void queryData(){
            cout<<"Querying "<<dbType<<" database on "<<serverName<<endl;
        }
};

int main(){
    WebServer apache("Apache",1000);
    apache.ping();
    apache.serveHTML(); 
    DatabaseServer mysql("MySQL", "Relational");
    mysql.ping();
    mysql.queryData();
    return 0;
}