#pragma once
#define CHUNK_BYTE 64
#include<iostream>
#include<math.h>
#include<memory.h>
#include<string>
typedef unsigned int uint32;

class md5{
public:
	/* F(x,y,z) = (x & y) | ((~x) & z)
	   G(x,y,z) = (x & z) | ( y & (~z)) 
	   H(x,y,z) = x ^ y ^ z 
	   I(x,y,z) = y ^ (x | (~z)) */
	md5()
	{
		init();
	}
	uint32 F(uint32 b, uint32 c, uint32 d)
	{
		return (b & c) | ((~b) & d);
	}
	uint32 G(uint32 b, uint32 c, uint32 d)
	{
		return (b & d) | (c & (~d));
	}
	uint32 H(uint32 b, uint32 c, uint32 d)
	{
		return b ^ c ^ d;
	}
	uint32 I(uint32 b, uint32 c, uint32 d)
	{
		return c ^ (b | (~d));
	}
	uint32 shiftleft(uint32 number, int shiftnum)
	{
		return (number << shiftnum)|(number >> (32 - shiftnum));
	}
	void init()
	{
		for (int i = 0; i < 64; i++)
		{
			_k[i] = static_cast<uint32>(abs(sin(i + 1.0)) * pow(2.0, 32));
		}
		reset();
	}
	void reset()
	{
		_a = 0x67452301;
		_b = 0xefcdab89;
		_c = 0x98badcfe;
		_d = 0x10325476;
		memset(_chunk, 0, CHUNK_BYTE);
		_LastByte = _TotalByte = 0;
	}
	void calMD5(uint32* chunk);
	void calfinalMD5();
	std::string ChangeHex(uint32 n);
	std::string GetstringMD5(const std::string& s);
	std::string GetfileMD5(const char* filepath);

private:
	//循环移位的位数
	static int _leftShift[64];
	uint32 _k[CHUNK_BYTE];
	//数据块
	char _chunk[CHUNK_BYTE];
	//最后一块数据块的字节数
	uint32 _LastByte;
	//总的字节数
	uint32 _TotalByte;
	//md5信息
	uint32 _a;
	uint32 _b;
	uint32 _c;
	uint32 _d;
};