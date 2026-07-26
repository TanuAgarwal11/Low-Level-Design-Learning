#include <bits/stdc++.h>
using namespace std;

enum class HttpStatusType
{
    OK,
    BAD_REQUEST,
    NOT_FOUND,
    INTERNAL_SERVER_ERROR
};

struct HttpStatusCodes
{
    int code;
    string message;

    HttpStatusCodes(int c, string msg)
    {
        code = c;
        message = msg;
    }

    bool isSuccess()
    {
        return code < 400;
    }

    void display()
    {
        cout << code << " " << message << endl;
    }

    static HttpStatusCodes *fromCode(int code)
    {
        static HttpStatusCodes ok(200, "OK");
        static HttpStatusCodes badRequest(400, "BAD REQUEST");
        static HttpStatusCodes notFound(404, "NOT FOUND");
        static HttpStatusCodes internalServerError(500, "Internal Server Error");

        if (code == 200)
        {
            return &ok;
        }
        if (code == 400)
        {
            return &badRequest;
        }
        if (code == 404)
        {
            return &notFound;
        }
        if (code == 500)
        {
            return &internalServerError;
        }

        return nullptr;
    }
};

int main()
{
    HttpStatusCodes ok(200, "OK");
    ok.display();

    cout << ok.isSuccess() << endl;

    HttpStatusCodes *status = HttpStatusCodes::fromCode(404);
    if (status != nullptr)
    {
        status->display();
    }

    return 0;
}