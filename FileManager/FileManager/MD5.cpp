#include"MD5.h"
#include<fstream>

int md5::_leftShift[64] = { 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7,
12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21 };

void md5::calMD5(uint32* chunk)
{
	int a = _a, b = _b, c = _c, d = _d;
	int f, g;
	for (int i = 0; i < 64; i++)
	{
		if (i >= 0 && i < 16)
		{
			f = F(b, c, d);
			g = i;
		}
		else if (i >= 16 && i < 32)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i >= 32 && i < 48)
		{
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else{
			f = I(b, c, d);
			g = (7 * i) % 16;
		}

		int tmp = d;
		d = c;
		c = b;
		b = b + shiftleft(a + f + chunk[g] + _k[i], _leftShift[i]);
		a = tmp;
	}
	_a += a;
	_b += b;
	_c += c;
	_d += d;
}

void md5::calfinalMD5()
{
	char* p = _chunk + _LastByte;
	*p++ = 0x80;
	int remainbyte = CHUNK_BYTE - _LastByte-1;

	if (remainbyte < 8)
	{
		memset(p, 0, remainbyte);
		calMD5((uint32*)_chunk);
		memset(_chunk, 0, CHUNK_BYTE);
	}
	else
	{
		memset(p, 0, remainbyte);
	}
	unsigned long long totalbits = _TotalByte;
	totalbits *= 8;
	((unsigned long long*)_chunk)[7] = totalbits;
	calMD5((uint32*)_chunk);
}

std::string md5::ChangeHex(uint32 n)
{
	static std::string strmap = "0123456789abcdef";
	std::string ret;
	for (int i = 0; i < 4; i++)
	{
		int curbyte = (n >> (i * 8)) & 0xff;
		std::string curstring;
		curstring += strmap[curbyte / 16];
		curstring += strmap[curbyte % 16];
		ret += curstring;
	}
	return ret;
}

std::string md5::GetstringMD5(const std::string& s)
{
	reset();
	if (s.empty())
	{
		return ChangeHex(_a).append(ChangeHex(_b)).append(ChangeHex(_c)).append(ChangeHex(_d));
	}
	_TotalByte = s.size();
	uint32 chunknum = _TotalByte / CHUNK_BYTE;
	const char* sptr = s.c_str();
	for (int i = 0; i < chunknum; i++)
	{
		memcpy(_chunk, sptr + i*CHUNK_BYTE, CHUNK_BYTE);
		calMD5((uint32*)_chunk);
	}
	_LastByte = _TotalByte % CHUNK_BYTE;
	memcpy(_chunk, sptr + chunknum*CHUNK_BYTE, _LastByte);
	calfinalMD5();
	return ChangeHex(_a).append(ChangeHex(_b)).append(ChangeHex(_c)).append(ChangeHex(_d));
}

std::string md5::GetfileMD5(const char* filepath)
{
	reset();
	std::ifstream fin(filepath,std::ifstream::binary);
	if (!fin.is_open())
	{
		std::cout << filepath;
		perror("file open failed");
		return "";
	}
	while (!fin.eof())
	{
		fin.read(_chunk, CHUNK_BYTE);
		if (fin.gcount() != CHUNK_BYTE)
			break;
		_TotalByte += CHUNK_BYTE;
		calMD5((uint32*)_chunk);
	}
	_LastByte = fin.gcount();
	_TotalByte += _LastByte;
	calfinalMD5();
	return ChangeHex(_a).append(ChangeHex(_b)).append(ChangeHex(_c)).append(ChangeHex(_d));
}