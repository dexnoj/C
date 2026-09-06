#include <stdio.h>

int main() {
    printf("<!DOCTYPE html>\n");
    printf("<html lang='en'>\n<head>\n");
    printf("<meta charset='UTF-8'>\n");
    printf("<title>Login Page</title>\n");
    printf("<style>\n");
    printf("body{font-family:Arial;background:#1e1e2f;color:white;");
    printf("display:flex;justify-content:center;align-items:center;height:100vh;}\n");
    printf(".box{background:#2b2b3d;padding:30px;border-radius:10px;}\n");
    printf("input{display:block;margin:10px 0;padding:8px;width:220px;}\n");
    printf("button{padding:8px 20px;background:#4CAF50;color:white;border:none;}\n");
    printf("</style>\n</head>\n<body>\n");
    printf("<div class='box'>\n");
    printf("<h2>Login</h2>\n");
    printf("<form>\n");
    printf("<input type='email' placeholder='Email'>\n");
    printf("<input type='password' placeholder='Password'>\n");
    printf("<button type='submit'>Sign in</button>\n");
    printf("</form>\n</div>\n");
    printf("</body>\n</html>\n");

    return 0;
}