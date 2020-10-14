#include <iostream>
#include <functional>

#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

int main()
{
    [out = std::ref(std::cout << "Connecting ")]() { out.get() << "to a website!\n"; }(); // Do not use std::endl because it does a flush. See https://youtu.be/GMqQOEZYVJQ

    // Error code for ASIO
    asio::error_code ec;

    // Create a context - essentially the platform specific interface
    asio::io_context context;

    // Get the address of somewhere we wish to connect to
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("93.184.216.34", ec), 80); // IP address of example.com - Port 80 HTTP

    // Create a TCP socket
    asio::ip::tcp::socket socket(context);

    // Tell socket to try and connect to the IP and port specified in endpoint
    socket.connect(endpoint, ec);

    if (!ec)
    {
        std::cout << "Connected!\n";
    }
    else
    {
        std::cout << "Failed to connect to address:\n" << ec.message() << std::endl;  
    }

    if (socket.is_open())
    {
        // Create a HTTP request
        std::string sRequest =
            "GET /index.html HTTP/1.1\r\n"
            "Host: example.com\r\n"
            "Connection: close\r\n\r\n";

        // Try to send as much data as possible
        socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);

        size_t bytes = socket.available();
        std::cout << "Bytes available: " << bytes << std::endl;

        if (bytes > 0)
        {
            std::vector<char> vBuffer(bytes);
            socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

            for (auto c : vBuffer)
            {
                std::cout << c;
            }
        }
    }

    return 0;
}