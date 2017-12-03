

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Nov 12 16:23:42 2017
 */
/* Compiler settings for SAtest.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "SAtest.h"

#define TYPE_FORMAT_STRING_SIZE   1041                              
#define PROC_FORMAT_STRING_SIZE   349                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _SAtest_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } SAtest_MIDL_TYPE_FORMAT_STRING;

typedef struct _SAtest_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } SAtest_MIDL_PROC_FORMAT_STRING;

typedef struct _SAtest_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } SAtest_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const SAtest_MIDL_TYPE_FORMAT_STRING SAtest__MIDL_TypeFormatString;
extern const SAtest_MIDL_PROC_FORMAT_STRING SAtest__MIDL_ProcFormatString;
extern const SAtest_MIDL_EXPR_FORMAT_STRING SAtest__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ISATest_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ISATest_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const SAtest_MIDL_PROC_FORMAT_STRING SAtest__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure MySAFunc1 */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x1 ),	/* 1 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 26 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 28 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Return value */

/* 32 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MySAFunc2 */

/* 38 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 40 */	NdrFcLong( 0x0 ),	/* 0 */
/* 44 */	NdrFcShort( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x8 ),	/* 8 */
/* 52 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 54 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 56 */	NdrFcShort( 0x1 ),	/* 1 */
/* 58 */	NdrFcShort( 0x1 ),	/* 1 */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 64 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 66 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 68 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 70 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 72 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 74 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MySAFunc3 */

/* 76 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 78 */	NdrFcLong( 0x0 ),	/* 0 */
/* 82 */	NdrFcShort( 0x9 ),	/* 9 */
/* 84 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 86 */	NdrFcShort( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 92 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 94 */	NdrFcShort( 0x1 ),	/* 1 */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pArray */

/* 102 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 104 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MySAFunc4 */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0xa ),	/* 10 */
/* 122 */	NdrFcShort( 0x20 ),	/* X64 Stack size/offset = 32 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x24 ),	/* 36 */
/* 128 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 130 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x1 ),	/* 1 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 142 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 144 */	NdrFcShort( 0x3da ),	/* Type Offset=986 */

	/* Parameter pRes */

/* 146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 148 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 154 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestBool */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0xb ),	/* 11 */
/* 166 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 172 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 174 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 176 */	NdrFcShort( 0x1 ),	/* 1 */
/* 178 */	NdrFcShort( 0x1 ),	/* 1 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 184 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 186 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 192 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestBSTR */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0xc ),	/* 12 */
/* 204 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 210 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 212 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 214 */	NdrFcShort( 0x1 ),	/* 1 */
/* 216 */	NdrFcShort( 0x1 ),	/* 1 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 222 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 224 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 226 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestUnk */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0xd ),	/* 13 */
/* 242 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 250 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 252 */	NdrFcShort( 0x1 ),	/* 1 */
/* 254 */	NdrFcShort( 0x1 ),	/* 1 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 260 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 262 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 264 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 268 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestVariant */

/* 272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0xe ),	/* 14 */
/* 280 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 286 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 288 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 290 */	NdrFcShort( 0x1 ),	/* 1 */
/* 292 */	NdrFcShort( 0x1 ),	/* 1 */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter array */

/* 298 */	NdrFcShort( 0x9b ),	/* Flags:  must size, must free, in, out, by val, */
/* 300 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 302 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 306 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure TestV */

/* 310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0xf ),	/* 15 */
/* 318 */	NdrFcShort( 0x18 ),	/* X64 Stack size/offset = 24 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 324 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 326 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 328 */	NdrFcShort( 0x1 ),	/* 1 */
/* 330 */	NdrFcShort( 0x1 ),	/* 1 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVar */

/* 336 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 338 */	NdrFcShort( 0x8 ),	/* X64 Stack size/offset = 8 */
/* 340 */	NdrFcShort( 0x406 ),	/* Type Offset=1030 */

	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0x10 ),	/* X64 Stack size/offset = 16 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const SAtest_MIDL_TYPE_FORMAT_STRING SAtest__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x12, 0x0,	/* FC_UP */
/*  8 */	NdrFcShort( 0x3c0 ),	/* Offset= 960 (968) */
/* 10 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x89,		/* 137 */
/* 12 */	NdrFcShort( 0x20 ),	/* 32 */
/* 14 */	NdrFcShort( 0xa ),	/* 10 */
/* 16 */	NdrFcLong( 0x8 ),	/* 8 */
/* 20 */	NdrFcShort( 0x66 ),	/* Offset= 102 (122) */
/* 22 */	NdrFcLong( 0xd ),	/* 13 */
/* 26 */	NdrFcShort( 0x98 ),	/* Offset= 152 (178) */
/* 28 */	NdrFcLong( 0x9 ),	/* 9 */
/* 32 */	NdrFcShort( 0xca ),	/* Offset= 202 (234) */
/* 34 */	NdrFcLong( 0xc ),	/* 12 */
/* 38 */	NdrFcShort( 0x2be ),	/* Offset= 702 (740) */
/* 40 */	NdrFcLong( 0x24 ),	/* 36 */
/* 44 */	NdrFcShort( 0x2de ),	/* Offset= 734 (778) */
/* 46 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 50 */	NdrFcShort( 0x2fa ),	/* Offset= 762 (812) */
/* 52 */	NdrFcLong( 0x10 ),	/* 16 */
/* 56 */	NdrFcShort( 0x314 ),	/* Offset= 788 (844) */
/* 58 */	NdrFcLong( 0x2 ),	/* 2 */
/* 62 */	NdrFcShort( 0x32a ),	/* Offset= 810 (872) */
/* 64 */	NdrFcLong( 0x3 ),	/* 3 */
/* 68 */	NdrFcShort( 0x340 ),	/* Offset= 832 (900) */
/* 70 */	NdrFcLong( 0x14 ),	/* 20 */
/* 74 */	NdrFcShort( 0x356 ),	/* Offset= 854 (928) */
/* 76 */	NdrFcShort( 0xffff ),	/* Offset= -1 (75) */
/* 78 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 80 */	NdrFcShort( 0x2 ),	/* 2 */
/* 82 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 84 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 86 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 88 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 90 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 92 */	NdrFcShort( 0x8 ),	/* 8 */
/* 94 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (78) */
/* 96 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 98 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 100 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 110 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 114 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 116 */	
			0x12, 0x0,	/* FC_UP */
/* 118 */	NdrFcShort( 0xffe4 ),	/* Offset= -28 (90) */
/* 120 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 122 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 124 */	NdrFcShort( 0x10 ),	/* 16 */
/* 126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 128 */	NdrFcShort( 0x6 ),	/* Offset= 6 (134) */
/* 130 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 132 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 134 */	
			0x11, 0x0,	/* FC_RP */
/* 136 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (100) */
/* 138 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 148 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 150 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 152 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 154 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 156 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 166 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 170 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 172 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 174 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (138) */
/* 176 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 178 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 180 */	NdrFcShort( 0x10 ),	/* 16 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x6 ),	/* Offset= 6 (190) */
/* 186 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 188 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 190 */	
			0x11, 0x0,	/* FC_RP */
/* 192 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (156) */
/* 194 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 196 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 204 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 206 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 208 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 210 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 212 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 222 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 226 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 228 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 230 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (194) */
/* 232 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 234 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 236 */	NdrFcShort( 0x10 ),	/* 16 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x6 ),	/* Offset= 6 (246) */
/* 242 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 244 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 246 */	
			0x11, 0x0,	/* FC_RP */
/* 248 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (212) */
/* 250 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 252 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 254 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 256 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
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
/* 334 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (138) */
/* 336 */	NdrFcLong( 0x9 ),	/* 9 */
/* 340 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (194) */
/* 342 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 346 */	NdrFcShort( 0xd4 ),	/* Offset= 212 (558) */
/* 348 */	NdrFcLong( 0x24 ),	/* 36 */
/* 352 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (566) */
/* 354 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 358 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (566) */
/* 360 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 364 */	NdrFcShort( 0x100 ),	/* Offset= 256 (620) */
/* 366 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 370 */	NdrFcShort( 0xfe ),	/* Offset= 254 (624) */
/* 372 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 376 */	NdrFcShort( 0xfc ),	/* Offset= 252 (628) */
/* 378 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 382 */	NdrFcShort( 0xfa ),	/* Offset= 250 (632) */
/* 384 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 388 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (636) */
/* 390 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 394 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (640) */
/* 396 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 400 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (624) */
/* 402 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 406 */	NdrFcShort( 0xde ),	/* Offset= 222 (628) */
/* 408 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 412 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (644) */
/* 414 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 418 */	NdrFcShort( 0xde ),	/* Offset= 222 (640) */
/* 420 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 424 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (648) */
/* 426 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 430 */	NdrFcShort( 0xde ),	/* Offset= 222 (652) */
/* 432 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 436 */	NdrFcShort( 0xdc ),	/* Offset= 220 (656) */
/* 438 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 442 */	NdrFcShort( 0xda ),	/* Offset= 218 (660) */
/* 444 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 448 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (672) */
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
/* 490 */	NdrFcShort( 0xbe ),	/* Offset= 190 (680) */
/* 492 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 496 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (690) */
/* 498 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 502 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (694) */
/* 504 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 508 */	NdrFcShort( 0x74 ),	/* Offset= 116 (624) */
/* 510 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 514 */	NdrFcShort( 0x72 ),	/* Offset= 114 (628) */
/* 516 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 520 */	NdrFcShort( 0x70 ),	/* Offset= 112 (632) */
/* 522 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 526 */	NdrFcShort( 0x66 ),	/* Offset= 102 (628) */
/* 528 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 532 */	NdrFcShort( 0x60 ),	/* Offset= 96 (628) */
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
/* 556 */	NdrFcShort( 0xfe2e ),	/* Offset= -466 (90) */
/* 558 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 560 */	NdrFcShort( 0x2 ),	/* Offset= 2 (562) */
/* 562 */	
			0x12, 0x0,	/* FC_UP */
/* 564 */	NdrFcShort( 0x194 ),	/* Offset= 404 (968) */
/* 566 */	
			0x12, 0x0,	/* FC_UP */
/* 568 */	NdrFcShort( 0x20 ),	/* Offset= 32 (600) */
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
/* 596 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 598 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 600 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 602 */	NdrFcShort( 0x18 ),	/* 24 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0xa ),	/* Offset= 10 (616) */
/* 608 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 610 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 612 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (570) */
/* 614 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 616 */	
			0x12, 0x0,	/* FC_UP */
/* 618 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (588) */
/* 620 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 622 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 624 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 626 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 628 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 630 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 632 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 634 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 636 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 638 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 640 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 642 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 644 */	
			0x12, 0x0,	/* FC_UP */
/* 646 */	NdrFcShort( 0xff9e ),	/* Offset= -98 (548) */
/* 648 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 650 */	NdrFcShort( 0xffa0 ),	/* Offset= -96 (554) */
/* 652 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 654 */	NdrFcShort( 0xfdfc ),	/* Offset= -516 (138) */
/* 656 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 658 */	NdrFcShort( 0xfe30 ),	/* Offset= -464 (194) */
/* 660 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 662 */	NdrFcShort( 0x2 ),	/* Offset= 2 (664) */
/* 664 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 666 */	NdrFcShort( 0x2 ),	/* Offset= 2 (668) */
/* 668 */	
			0x12, 0x0,	/* FC_UP */
/* 670 */	NdrFcShort( 0x12a ),	/* Offset= 298 (968) */
/* 672 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 674 */	NdrFcShort( 0x2 ),	/* Offset= 2 (676) */
/* 676 */	
			0x12, 0x0,	/* FC_UP */
/* 678 */	NdrFcShort( 0x14 ),	/* Offset= 20 (698) */
/* 680 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 682 */	NdrFcShort( 0x10 ),	/* 16 */
/* 684 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 686 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 688 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 690 */	
			0x12, 0x0,	/* FC_UP */
/* 692 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (680) */
/* 694 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 696 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 698 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 700 */	NdrFcShort( 0x20 ),	/* 32 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* Offset= 0 (704) */
/* 706 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 708 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 710 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 712 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 714 */	NdrFcShort( 0xfe30 ),	/* Offset= -464 (250) */
/* 716 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 718 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 726 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 728 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 732 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 734 */	
			0x12, 0x0,	/* FC_UP */
/* 736 */	NdrFcShort( 0xffda ),	/* Offset= -38 (698) */
/* 738 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 740 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 742 */	NdrFcShort( 0x10 ),	/* 16 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x6 ),	/* Offset= 6 (752) */
/* 748 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 750 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 752 */	
			0x11, 0x0,	/* FC_RP */
/* 754 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (718) */
/* 756 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 764 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 766 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 770 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 772 */	
			0x12, 0x0,	/* FC_UP */
/* 774 */	NdrFcShort( 0xff52 ),	/* Offset= -174 (600) */
/* 776 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 778 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 780 */	NdrFcShort( 0x10 ),	/* 16 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x6 ),	/* Offset= 6 (790) */
/* 786 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 788 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 790 */	
			0x11, 0x0,	/* FC_RP */
/* 792 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (756) */
/* 794 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 798 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 800 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 802 */	NdrFcShort( 0x10 ),	/* 16 */
/* 804 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 806 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 808 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (794) */
			0x5b,		/* FC_END */
/* 812 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 814 */	NdrFcShort( 0x20 ),	/* 32 */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0xa ),	/* Offset= 10 (828) */
/* 820 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 822 */	0x36,		/* FC_POINTER */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 824 */	0x0,		/* 0 */
			NdrFcShort( 0xffe7 ),	/* Offset= -25 (800) */
			0x5b,		/* FC_END */
/* 828 */	
			0x11, 0x0,	/* FC_RP */
/* 830 */	NdrFcShort( 0xfd5e ),	/* Offset= -674 (156) */
/* 832 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 834 */	NdrFcShort( 0x1 ),	/* 1 */
/* 836 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 840 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 842 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 844 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x10 ),	/* 16 */
/* 848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 850 */	NdrFcShort( 0x6 ),	/* Offset= 6 (856) */
/* 852 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 854 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 856 */	
			0x12, 0x0,	/* FC_UP */
/* 858 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (832) */
/* 860 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 862 */	NdrFcShort( 0x2 ),	/* 2 */
/* 864 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 870 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 872 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 874 */	NdrFcShort( 0x10 ),	/* 16 */
/* 876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 878 */	NdrFcShort( 0x6 ),	/* Offset= 6 (884) */
/* 880 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 882 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 884 */	
			0x12, 0x0,	/* FC_UP */
/* 886 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (860) */
/* 888 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 890 */	NdrFcShort( 0x4 ),	/* 4 */
/* 892 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 898 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 900 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 902 */	NdrFcShort( 0x10 ),	/* 16 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x6 ),	/* Offset= 6 (912) */
/* 908 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 910 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 912 */	
			0x12, 0x0,	/* FC_UP */
/* 914 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (888) */
/* 916 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 920 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 926 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 928 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x10 ),	/* 16 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x6 ),	/* Offset= 6 (940) */
/* 936 */	0x8,		/* FC_LONG */
			0x40,		/* FC_STRUCTPAD4 */
/* 938 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 940 */	
			0x12, 0x0,	/* FC_UP */
/* 942 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (916) */
/* 944 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 946 */	NdrFcShort( 0x8 ),	/* 8 */
/* 948 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 950 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 952 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 956 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 958 */	NdrFcShort( 0xffc8 ),	/* -56 */
/* 960 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 962 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 964 */	NdrFcShort( 0xffec ),	/* Offset= -20 (944) */
/* 966 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 968 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 970 */	NdrFcShort( 0x38 ),	/* 56 */
/* 972 */	NdrFcShort( 0xffec ),	/* Offset= -20 (952) */
/* 974 */	NdrFcShort( 0x0 ),	/* Offset= 0 (974) */
/* 976 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 978 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 980 */	0x40,		/* FC_STRUCTPAD4 */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 982 */	0x0,		/* 0 */
			NdrFcShort( 0xfc33 ),	/* Offset= -973 (10) */
			0x5b,		/* FC_END */
/* 986 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 994 */	NdrFcShort( 0xfc20 ),	/* Offset= -992 (2) */
/* 996 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 998 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1000) */
/* 1000 */	
			0x13, 0x0,	/* FC_OP */
/* 1002 */	NdrFcShort( 0xffde ),	/* Offset= -34 (968) */
/* 1004 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (996) */
/* 1014 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1016 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1004) */
/* 1018 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1020 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1022 */	
			0x11, 0x0,	/* FC_RP */
/* 1024 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1030) */
/* 1026 */	
			0x13, 0x0,	/* FC_OP */
/* 1028 */	NdrFcShort( 0xfeb6 ),	/* Offset= -330 (698) */
/* 1030 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1032 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1034 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1026) */

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
    38,
    76,
    114,
    158,
    196,
    234,
    272,
    310
    };

static const MIDL_STUBLESS_PROXY_INFO ISATest_ProxyInfo =
    {
    &Object_StubDesc,
    SAtest__MIDL_ProcFormatString.Format,
    &ISATest_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ISATest_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    SAtest__MIDL_ProcFormatString.Format,
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
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
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
    SAtest__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x800025b, /* MIDL Version 8.0.603 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _SAtest_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ISATestProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _SAtest_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ISATestStubVtbl,
    0
};

PCInterfaceName const _SAtest_InterfaceNamesList[] = 
{
    "ISATest",
    0
};

const IID *  const _SAtest_BaseIIDList[] = 
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
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_AMD64)*/

