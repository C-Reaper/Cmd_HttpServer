#include "/home/codeleaded/System/Static/Library/HttpServer.h"

static void RootHandler(void* user_ctx, HttpRequest* req, HttpResponse* res) {
    (void)user_ctx;
    
    printf("[HTTP] %s %s\n", req->method, req->path);

    if (strcmp(req->method, "GET") == 0) {
        if (strcmp(req->path, "/") == 0 || strcmp(req->path, "/index.html") == 0) {
            res->status_code = 200;
            HttpResponse_AddHeader(res, "Content-Type", "text/html; charset=utf-8");
            HttpResponse_SetBody(res,
                "<!DOCTYPE html>"
                "<html><head><meta charset='utf-8'>"
                "<title>Mein C HTTP Server</title></head>"
                "<body>"
                "<h1> Server läuft!</h1>"
                "<p>Hallo aus deinem eigenen C HTTP Server.</p>"
                "<p><a href='/about'>Über</a> | <a href='/api/status'>API Status</a></p>"
                "</body></html>"
            );
        } 
        else if (strcmp(req->path, "/about") == 0) {
            res->status_code = 200;
            HttpResponse_AddHeader(res, "Content-Type", "text/html");
            HttpResponse_SetBody(res, "<h1>Über diesen Server</h1><p>Entwickelt mit deiner eigenen Networking-Bibliothek.</p>");
        }
        else {
            res->status_code = 404;
            HttpResponse_SetBody(res, "<h1>404 - Seite nicht gefunden</h1>");
        }
    } 
    else if (strcmp(req->method, "POST") == 0) {
        res->status_code = 200;
        HttpResponse_AddHeader(res, "Content-Type", "application/json");
        char body[256];
        snprintf(body, sizeof(body), "{\"status\":\"ok\", \"received\":\"%s\"}", req->body ? req->body : "null");
        HttpResponse_SetBody(res, body);
    } 
    else {
        res->status_code = 405;
        HttpResponse_AddHeader(res, "Allow", "GET, POST");
        HttpResponse_SetBody(res, "Method Not Allowed");
    }
}

int main(void) {
    printf("=== Mein C HTTP Server ===\n");

    HttpServer server = HttpServer_New(8080, "./code", NULL);

    HttpServer_AddRoute(&server, "GET", "/about", RootHandler);
    HttpServer_AddRoute(&server, "POST", "/api/status", RootHandler);
    HttpServer_Start(&server);

    printf("Server läuft auf http://localhost:8080\n");
    printf("Drücke STRG+C zum Beenden...\n");

    char msg[1024];
    int out = scanf("%s",msg);

    HttpServer_Free(&server);
    return 0;
}