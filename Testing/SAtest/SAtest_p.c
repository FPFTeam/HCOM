

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Tue Jan 05 14:50:02 2010
 */
/* Compiler settings for .\SAtest.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "SAtest.h"

#define TYPE_FORMAT_STRING_SIZE   1061                              
#define PROC_FORMAT_STRING_SIZE   259                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISATest_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISATest_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure MySAFunc1 */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter array */

/* 16 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MySAFunc2 */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter array */

/* 44 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 46 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 48 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 52 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MySAFunc3 */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
/* 64 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
/* 70 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pArray */

/* 72 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 74 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 76 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MySAFunc4 */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
/* 92 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x24 ),	/* 36 */
/* 98 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter array */

/* 100 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 104 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */

	/* Parameter pRes */

/* 106 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestBool */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xb ),	/* 11 */
/* 126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter array */

/* 134 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 136 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 138 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 142 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestBSTR */

/* 146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0xc ),	/* 12 */
/* 154 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter array */

/* 162 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 166 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestUnk */

/* 174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0xd ),	/* 13 */
/* 182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter array */

/* 190 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 192 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 194 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestVariant */

/* 202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0xe ),	/* 14 */
/* 210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 216 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter array */

/* 218 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 220 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 222 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 224 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 226 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 228 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestV */

/* 230 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 232 */	NdrFcLong( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0xf ),	/* 15 */
/* 238 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 244 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVar */

/* 246 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 248 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 250 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x12, 0x0,	/* FC_UP */
/*  8 */	NdrFcShort( 0x3d4 ),	/* Offset= 980 (988) */
/* 10 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 12 */	NdrFcShort( 0x18 ),	/* 24 */
/* 14 */	NdrFcShort( 0xa ),	/* 10 */
/* 16 */	NdrFcLong( 0x8 ),	/* 8 */
/* 20 */	NdrFcShort( 0x6c ),	/* Offset= 108 (128) */
/* 22 */	NdrFcLong( 0xd ),	/* 13 */
/* 26 */	NdrFcShort( 0x9e ),	/* Offset= 158 (184) */
/* 28 */	NdrFcLong( 0x9 ),	/* 9 */
/* 32 */	NdrFcShort( 0xcc ),	/* Offset= 204 (236) */
/* 34 */	NdrFcLong( 0xc ),	/* 12 */
/* 38 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (746) */
/* 40 */	NdrFcLong( 0x24 ),	/* 36 */
/* 44 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (792) */
/* 46 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 50 */	NdrFcShort( 0x308 ),	/* Offset= 776 (826) */
/* 52 */	NdrFcLong( 0x10 ),	/* 16 */
/* 56 */	NdrFcShort( 0x320 ),	/* Offset= 800 (856) */
/* 58 */	NdrFcLong( 0x2 ),	/* 2 */
/* 62 */	NdrFcShort( 0x338 ),	/* Offset= 824 (886) */
/* 64 */	NdrFcLong( 0x3 ),	/* 3 */
/* 68 */	NdrFcShort( 0x350 ),	/* Offset= 848 (916) */
/* 70 */	NdrFcLong( 0x14 ),	/* 20 */
/* 74 */	NdrFcShort( 0x368 ),	/* Offset= 872 (946) */
/* 76 */	NdrFcShort( 0xffff ),	/* Offset= -1 (75) */
/* 78 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 80 */	NdrFcShort( 0x2 ),	/* 2 */
/* 82 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 84 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 86 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 88 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 90 */	NdrFcShort( 0x8 ),	/* 8 */
/* 92 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (78) */
/* 94 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 96 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 98 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 100 */	NdrFcShort( 0x4 ),	/* 4 */
/* 102 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 108 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 110 */	NdrFcShort( 0x4 ),	/* 4 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x1 ),	/* 1 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 120 */	0x12, 0x0,	/* FC_UP */
/* 122 */	NdrFcShort( 0xffde ),	/* Offset= -34 (88) */
/* 124 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 126 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 128 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 134 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 136 */	NdrFcShort( 0x4 ),	/* 4 */
/* 138 */	NdrFcShort( 0x4 ),	/* 4 */
/* 140 */	0x11, 0x0,	/* FC_RP */
/* 142 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (98) */
/* 144 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 146 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 148 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 158 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 160 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 162 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 164 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 166 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 178 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 180 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (148) */
/* 182 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 184 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 186 */	NdrFcShort( 0x8 ),	/* 8 */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	NdrFcShort( 0x6 ),	/* Offset= 6 (196) */
/* 192 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 194 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 196 */	
			0x11, 0x0,	/* FC_RP */
/* 198 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (166) */
/* 200 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 202 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 212 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 214 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 216 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 218 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 230 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 232 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (200) */
/* 234 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 236 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 242 */	NdrFcShort( 0x6 ),	/* Offset= 6 (248) */
/* 244 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 246 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 248 */	
			0x11, 0x0,	/* FC_RP */
/* 250 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (218) */
/* 252 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 254 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 256 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 258 */	NdrFcShort( 0x2 ),	/* Offset= 2 (260) */
/* 260 */	NdrFcShort( 0x10 ),	/* 16 */
/* 262 */	NdrFcShort( 0x2f ),	/* 47 */
/* 264 */	NdrFcLong( 0x14 ),	/* 20 */
/* 268 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 270 */	NdrFcLong( 0x3 ),	/* 3 */
/* 274 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 276 */	NdrFcLong( 0x11 ),	/* 17 */
/* 280 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 282 */	NdrFcLong( 0x2 ),	/* 2 */
/* 286 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 288 */	NdrFcLong( 0x4 ),	/* 4 */
/* 292 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 294 */	NdrFcLong( 0x5 ),	/* 5 */
/* 298 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 300 */	NdrFcLong( 0xb ),	/* 11 */
/* 304 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 306 */	NdrFcLong( 0xa ),	/* 10 */
/* 310 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 312 */	NdrFcLong( 0x6 ),	/* 6 */
/* 316 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (548) */
/* 318 */	NdrFcLong( 0x7 ),	/* 7 */
/* 322 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 324 */	NdrFcLong( 0x8 ),	/* 8 */
/* 328 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (554) */
/* 330 */	NdrFcLong( 0xd ),	/* 13 */
/* 334 */	NdrFcShort( 0xff46 ),	/* Offset= -186 (148) */
/* 336 */	NdrFcLong( 0x9 ),	/* 9 */
/* 340 */	NdrFcShort( 0xff74 ),	/* Offset= -140 (200) */
/* 342 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 346 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (558) */
/* 348 */	NdrFcLong( 0x24 ),	/* 36 */
/* 352 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (566) */
/* 354 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 358 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (566) */
/* 360 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 364 */	NdrFcShort( 0xfe ),	/* Offset= 254 (618) */
/* 366 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 370 */	NdrFcShort( 0xfc ),	/* Offset= 252 (622) */
/* 372 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 376 */	NdrFcShort( 0xfa ),	/* Offset= 250 (626) */
/* 378 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 382 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (630) */
/* 384 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 388 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (634) */
/* 390 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 394 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (638) */
/* 396 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 400 */	NdrFcShort( 0xde ),	/* Offset= 222 (622) */
/* 402 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 406 */	NdrFcShort( 0xdc ),	/* Offset= 220 (626) */
/* 408 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 412 */	NdrFcShort( 0xe6 ),	/* Offset= 230 (642) */
/* 414 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 418 */	NdrFcShort( 0xdc ),	/* Offset= 220 (638) */
/* 420 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 424 */	NdrFcShort( 0xde ),	/* Offset= 222 (646) */
/* 426 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 430 */	NdrFcShort( 0xdc ),	/* Offset= 220 (650) */
/* 432 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 436 */	NdrFcShort( 0xda ),	/* Offset= 218 (654) */
/* 438 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 442 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (658) */
/* 444 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 448 */	NdrFcShort( 0xde ),	/* Offset= 222 (670) */
/* 450 */	NdrFcLong( 0x10 ),	/* 16 */
/* 454 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 456 */	NdrFcLong( 0x12 ),	/* 18 */
/* 460 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 462 */	NdrFcLong( 0x13 ),	/* 19 */
/* 466 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 468 */	NdrFcLong( 0x15 ),	/* 21 */
/* 472 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 474 */	NdrFcLong( 0x16 ),	/* 22 */
/* 478 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 480 */	NdrFcLong( 0x17 ),	/* 23 */
/* 484 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 486 */	NdrFcLong( 0xe ),	/* 14 */
/* 490 */	NdrFcShort( 0xbc ),	/* Offset= 188 (678) */
/* 492 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 496 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (688) */
/* 498 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 502 */	NdrFcShort( 0xbe ),	/* Offset= 190 (692) */
/* 504 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 508 */	NdrFcShort( 0x72 ),	/* Offset= 114 (622) */
/* 510 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 514 */	NdrFcShort( 0x70 ),	/* Offset= 112 (626) */
/* 516 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 520 */	NdrFcShort( 0x6e ),	/* Offset= 110 (630) */
/* 522 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 526 */	NdrFcShort( 0x64 ),	/* Offset= 100 (626) */
/* 528 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 532 */	NdrFcShort( 0x5e ),	/* Offset= 94 (626) */
/* 534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 538 */	NdrFcShort( 0x0 ),	/* Offset= 0 (538) */
/* 540 */	NdrFcLong( 0x1 ),	/* 1 */
/* 544 */	NdrFcShort( 0x0 ),	/* Offset= 0 (544) */
/* 546 */	NdrFcShort( 0xffff ),	/* Offset= -1 (545) */
/* 548 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 554 */	
			0x12, 0x0,	/* FC_UP */
/* 556 */	NdrFcShort( 0xfe2c ),	/* Offset= -468 (88) */
/* 558 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 560 */	NdrFcShort( 0x2 ),	/* Offset= 2 (562) */
/* 562 */	
			0x12, 0x0,	/* FC_UP */
/* 564 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (988) */
/* 566 */	
			0x12, 0x0,	/* FC_UP */
/* 568 */	NdrFcShort( 0x1e ),	/* Offset= 30 (598) */
/* 570 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 572 */	NdrFcLong( 0x2f ),	/* 47 */
/* 576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 582 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 584 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 586 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 588 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 590 */	NdrFcShort( 0x1 ),	/* 1 */
/* 592 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 594 */	NdrFcShort( 0x4 ),	/* 4 */
/* 596 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 598 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 600 */	NdrFcShort( 0x10 ),	/* 16 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0xa ),	/* Offset= 10 (614) */
/* 606 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 608 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 610 */	NdrFcShort( 0xffd8 ),	/* Offset= -40 (570) */
/* 612 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 614 */	
			0x12, 0x0,	/* FC_UP */
/* 616 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (588) */
/* 618 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 620 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 622 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 624 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 626 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 628 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 630 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 632 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 634 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 636 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 638 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 640 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 642 */	
			0x12, 0x0,	/* FC_UP */
/* 644 */	NdrFcShort( 0xffa0 ),	/* Offset= -96 (548) */
/* 646 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 648 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (554) */
/* 650 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 652 */	NdrFcShort( 0xfe08 ),	/* Offset= -504 (148) */
/* 654 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 656 */	NdrFcShort( 0xfe38 ),	/* Offset= -456 (200) */
/* 658 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 660 */	NdrFcShort( 0x2 ),	/* Offset= 2 (662) */
/* 662 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 664 */	NdrFcShort( 0x2 ),	/* Offset= 2 (666) */
/* 666 */	
			0x12, 0x0,	/* FC_UP */
/* 668 */	NdrFcShort( 0x140 ),	/* Offset= 320 (988) */
/* 670 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 672 */	NdrFcShort( 0x2 ),	/* Offset= 2 (674) */
/* 674 */	
			0x12, 0x0,	/* FC_UP */
/* 676 */	NdrFcShort( 0x14 ),	/* Offset= 20 (696) */
/* 678 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 680 */	NdrFcShort( 0x10 ),	/* 16 */
/* 682 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 684 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 686 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 688 */	
			0x12, 0x0,	/* FC_UP */
/* 690 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (678) */
/* 692 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 694 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 696 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 698 */	NdrFcShort( 0x20 ),	/* 32 */
/* 700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0x0 ),	/* Offset= 0 (702) */
/* 704 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 706 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 708 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 710 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 712 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (252) */
/* 714 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 716 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 718 */	NdrFcShort( 0x4 ),	/* 4 */
/* 720 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 726 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 728 */	NdrFcShort( 0x4 ),	/* 4 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0x12, 0x0,	/* FC_UP */
/* 740 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (696) */
/* 742 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 744 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 746 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x6 ),	/* Offset= 6 (758) */
/* 754 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 756 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 758 */	
			0x11, 0x0,	/* FC_RP */
/* 760 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (716) */
/* 762 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 764 */	NdrFcShort( 0x4 ),	/* 4 */
/* 766 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 768 */	NdrFcShort( 0x0 ),	/* 0 */
/* 770 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 772 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 774 */	NdrFcShort( 0x4 ),	/* 4 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x1 ),	/* 1 */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	0x12, 0x0,	/* FC_UP */
/* 786 */	NdrFcShort( 0xff44 ),	/* Offset= -188 (598) */
/* 788 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 790 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 792 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 798 */	NdrFcShort( 0x6 ),	/* Offset= 6 (804) */
/* 800 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 802 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 804 */	
			0x11, 0x0,	/* FC_RP */
/* 806 */	NdrFcShort( 0xffd4 ),	/* Offset= -44 (762) */
/* 808 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 814 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 816 */	NdrFcShort( 0x10 ),	/* 16 */
/* 818 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 820 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 822 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (808) */
			0x5b,		/* FC_END */
/* 826 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 828 */	NdrFcShort( 0x18 ),	/* 24 */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0xa ),	/* Offset= 10 (842) */
/* 834 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 836 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 838 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (814) */
/* 840 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 842 */	
			0x11, 0x0,	/* FC_RP */
/* 844 */	NdrFcShort( 0xfd5a ),	/* Offset= -678 (166) */
/* 846 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 848 */	NdrFcShort( 0x1 ),	/* 1 */
/* 850 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 854 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 856 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 862 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 864 */	NdrFcShort( 0x4 ),	/* 4 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	0x12, 0x0,	/* FC_UP */
/* 870 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (846) */
/* 872 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 874 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 876 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 878 */	NdrFcShort( 0x2 ),	/* 2 */
/* 880 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 884 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 886 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 892 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	NdrFcShort( 0x4 ),	/* 4 */
/* 898 */	0x12, 0x0,	/* FC_UP */
/* 900 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (876) */
/* 902 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 904 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 906 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 908 */	NdrFcShort( 0x4 ),	/* 4 */
/* 910 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 916 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 922 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 924 */	NdrFcShort( 0x4 ),	/* 4 */
/* 926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 928 */	0x12, 0x0,	/* FC_UP */
/* 930 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (906) */
/* 932 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 934 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 936 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 946 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 950 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 952 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 954 */	NdrFcShort( 0x4 ),	/* 4 */
/* 956 */	NdrFcShort( 0x4 ),	/* 4 */
/* 958 */	0x12, 0x0,	/* FC_UP */
/* 960 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (936) */
/* 962 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 964 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 966 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 970 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 972 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 974 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 978 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 980 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 982 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 984 */	NdrFcShort( 0xffee ),	/* Offset= -18 (966) */
/* 986 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 988 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 990 */	NdrFcShort( 0x28 ),	/* 40 */
/* 992 */	NdrFcShort( 0xffee ),	/* Offset= -18 (974) */
/* 994 */	NdrFcShort( 0x0 ),	/* Offset= 0 (994) */
/* 996 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 998 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1000 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1002 */	NdrFcShort( 0xfc20 ),	/* Offset= -992 (10) */
/* 1004 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1006 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1014 */	NdrFcShort( 0xfc0c ),	/* Offset= -1012 (2) */
/* 1016 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1018 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1020) */
/* 1020 */	
			0x13, 0x0,	/* FC_OP */
/* 1022 */	NdrFcShort( 0xffde ),	/* Offset= -34 (988) */
/* 1024 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1028 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (1016) */
/* 1034 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1036 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1024) */
/* 1038 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1040 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1042 */	
			0x11, 0x0,	/* FC_RP */
/* 1044 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1050) */
/* 1046 */	
			0x13, 0x0,	/* FC_OP */
/* 1048 */	NdrFcShort( 0xfea0 ),	/* Offset= -352 (696) */
/* 1050 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1052 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1054 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1046) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ISATest, ver. 0.0,
   GUID={0xAF45C527,0x4B2E,0x4030,{0x83,0xC1,0x2E,0x99,0x92,0x3F,0x44,0x41}} */

#pragma code_seg(".orpc")
static const unsigned short ISATest_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    56,
    84,
    118,
    146,
    174,
    202,
    230
    };

static const MIDL_STUBLESS_PROXY_INFO ISATest_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ISATest_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISATest_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ISATest_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(16) _ISATestProxyVtbl = 
{
    &ISATest_ProxyInfo,
    &IID_ISATest,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ISATest::MySAFunc1 */ ,
    (void *) (INT_PTR) -1 /* ISATest::MySAFunc2 */ ,
    (void *) (INT_PTR) -1 /* ISATest::MySAFunc3 */ ,
    (void *) (INT_PTR) -1 /* ISATest::MySAFunc4 */ ,
    (void *) (INT_PTR) -1 /* ISATest::TestBool */ ,
    (void *) (INT_PTR) -1 /* ISATest::TestBSTR */ ,
    (void *) (INT_PTR) -1 /* ISATest::TestUnk */ ,
    (void *) (INT_PTR) -1 /* ISATest::TestVariant */ ,
    (void *) (INT_PTR) -1 /* ISATest::TestV */
};


static const PRPC_STUB_FUNCTION ISATest_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ISATestStubVtbl =
{
    &IID_ISATest,
    &ISATest_ServerInfo,
    16,
    &ISATest_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _SAtest_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISATestProxyVtbl,
    0
};

const CInterfaceStubVtbl * _SAtest_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISATestStubVtbl,
    0
};

PCInterfaceName const _SAtest_InterfaceNamesList[] = 
{
    "ISATest",
    0
};

const IID *  _SAtest_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _SAtest_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _SAtest, pIID, n)

int __stdcall _SAtest_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_SAtest_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo SAtest_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _SAtest_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _SAtest_StubVtblList,
    (const PCInterfaceName * ) & _SAtest_InterfaceNamesList,
    (const IID ** ) & _SAtest_BaseIIDList,
    & _SAtest_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

