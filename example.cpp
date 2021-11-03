#include <iostream>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/uri.h>
#include <cpprest/json.h>

int main()
{

    web::json::value obj = web::json::value::object();
    auto http_client_one = web::http::client::http_client(U("https://blog.naver.com/PostList.naver?blogId=lccandol"));
    auto request = http_client_one.request(web::http::methods::GET).get();
    
    if (request.status_code() == 200){
	std::cout << "\n\nResponse OK. \nCPPREST is working.\n\n" << std::endl;
    }
    
    return 0;
}
