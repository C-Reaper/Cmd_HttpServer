#include "/home/codeleaded/System/Static/Library/HttpServer.h"

int main() {
    HttpServer hs = HttpServer_New(8080,NULL);
    if(hs.running){
        HttpServer_Start(&hs);
        Thread_Join(&hs.worker);
    }
    HttpServer_Free(&hs);

    return 0;
}
