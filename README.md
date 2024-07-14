# Bypass-Windows-Defender
Bypass Windows Defender with a staged C code &amp; metasploit framework

#### developed by L0PA

 ### Bypass Step's:
   - Create a TCP Tunnel: Set up a TCP tunnel using Ngrok to expose the port for the payload.
   - Generate Payload: Use msfvenom to create the payload in .bin format.
   - Start Python Server: Launch a Python HTTP server in the same directory where the payload is located.
   - Expose Server Online: Use Serveo to make the server accessible online.
   - Set up Listener: Use msfconsole to listen on the specified TCP port.
   - Develop C Code: Write the C code to fetch and execute the payload.
   - Compile and Run: Compile the C code and execute.
   - 
##

### Tutorial

- Create the tcp tunnel on the port 4444 -
  ```
  sudo ngrok tcp 4444
  ```
- Copy the IP and the PORT of the server -
  ```
   <p align="center">
    <img src=".github/misc/logo.png">
   </p>
  ```
