# Windows Performance Options

Have you ever found it cumbersone that, natively, Windows doesn't really let you apply Performance Options settings without a reboot? If you are an end user, you can hit "Apply". However, from a Systems Administrator standpoint, trying to apply via GPO or Registry is a pain as it requires a reboot or logoff from the user. This means that for the first login, the user will have bad performance if they are on a VM. 


Well, look no further. I have created a C++ script that will apply performance options using the Windows API and registry calls, which apply keys that cannot be set by SPI (SystemParametersInfo) calls. After this script runs, it will end explorer.exe and restart it. This effortlessly applies the script. 

The options are that everything is unchecked except for Font Smoothing, which is normally the ideal performance for Virtual Machines. 
