#include "stdafx.h"
#define WINVER 0x501
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <ws2tcpip.h>
#include <winsock2.h>
#include <windows.h>
#include <string>
#include <sys/types.h>
#include <conio.h>

#pragma comment(lib, "Ws2_32.lib")

char bb[1024] = {};
char qq[1] = {};

int html()
{
	WSADATA wsad;
	if (!WSAStartup(0x0202, &wsad))
	{
		if (2 == LOBYTE(wsad.wVersion) && 2 == HIBYTE(wsad.wVersion))
		{
			SOCKET sock = INVALID_SOCKET;
			addrinfo aiHint, *paiRes = nullptr, *pai = nullptr;
			ZeroMemory(&aiHint, sizeof(aiHint));
			aiHint.ai_socktype = SOCK_STREAM;
			aiHint.ai_family = AF_UNSPEC;
			int res;
			const char* remName = "www.ntp-servers.net";
			if (!(res = getaddrinfo(remName, "80", &aiHint, &paiRes)))
			{
				pai = paiRes;
				do
				{
					sock = socket(pai->ai_family, pai->ai_socktype, pai->ai_protocol);
					if (INVALID_SOCKET == sock)
						continue;
					if (connect(sock, pai->ai_addr, pai->ai_addrlen) != SOCKET_ERROR)
						break;
					else;
				} while (pai = pai->ai_next);
				if (pai)
				{
					std::string sReq =
						"GET / HTTP/1.0\r\n"
						"Host: " + std::string(remName) + "\r\n"
						"Connection: close\r\n\r\n";
					if (sReq.size() == send(sock, sReq.c_str(), sReq.size(), 0))
					{
						std::ofstream ofs("out.txt");
						if (ofs.is_open())
						{
							char buf[1024];
							do
							{
								res = recv(sock, buf, sizeof(buf), 0);
								switch (res)
								{
								case 0: break;
								case SOCKET_ERROR: break;
								default:
								{
									ofs.write(buf, res);
									break;
								}
								}
							} while (res > 0);
						}
						else;
						ofs.close();
					}
					else;
				}
				else;
				freeaddrinfo(paiRes);
			}
			else;
		}
		else;
	}
	else;
	return 0;
}

void stroka()
{
	std::ifstream ifs("out.txt");
	ifs.getline(bb, 1024);
	ifs.getline(bb, 1024);
	ifs.getline(bb, 1024);
}

int time()
{
	qq[0] = bb[23];
	qq[1] = bb[24];

	int z = int(qq[0]) - 48;
	int zz = int(qq[1]) - 48;
	int zzz = z * 10 + zz;

	switch (zzz)
	{
	case 0: zzz = 23; break;
	case 1: zzz = 24; break;
	case 2: zzz = 1; break;
	case 3: zzz = 2; break;
	case 4: zzz = 3; break;
	case 5: zzz = 4; break;
	case 6: zzz = 5; break;
	case 7: zzz = 6; break;
	case 8: zzz = 7; break;
	case 9: zzz = 8; break;
	case 10: zzz = 9; break;
	case 11: zzz = 10; break;
	case 12: zzz = 11; break;
	case 13: zzz = 12; break;
	case 14: zzz = 13; break;
	case 15: zzz = 14; break;
	case 16: zzz = 15; break;
	case 17: zzz = 16; break;
	case 18: zzz = 17; break;
	case 19: zzz = 18; break;
	case 20: zzz = 19; break;
	case 21: zzz = 20; break;
	case 22: zzz = 21; break;
	case 23: zzz = 22; break;
	}

	switch (zzz)
	{
	case 0: zzz = 3; break;
	case 1: zzz = 4; break;
	case 2: zzz = 5; break;
	case 3: zzz = 6; break;
	case 4: zzz = 7; break;
	case 5: zzz = 8; break;
	case 6: zzz = 9; break;
	case 7: zzz = 10; break;
	case 8: zzz = 11; break;
	case 9: zzz = 12; break;
	case 10: zzz = 13; break;
	case 11: zzz = 14; break;
	case 12: zzz = 15; break;
	case 13: zzz = 16; break;
	case 14: zzz = 17; break;
	case 15: zzz = 18; break;
	case 16: zzz = 19; break;
	case 17: zzz = 20; break;
	case 18: zzz = 21; break;
	case 19: zzz = 22; break;
	case 20: zzz = 23; break;
	case 21: zzz = 0; break;
	case 22: zzz = 1; break;
	case 23: zzz = 2; break;
	}
	return zzz;
}

void main()
{
	html();
	stroka();

	std::cout << time() << bb[25] << bb[26] << bb[27] << std::endl;
}