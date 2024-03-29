#pragma once
#include "Opcode.h"

/*
A map of all supported opcodes.
To access a descriptor, access the cell that matches the opcode (e.g. g_OpcodeMap[0xE9] for the JMP instruction, e.t.c).
*/
const OPCODE_DESCRIPTOR g_OpcodeMap[0x100] =
{
/*	00				01				02				03				04				05				06				07 */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{0},
/*	08				09				0A				0B				0C				0D				0E				0F */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{},

/*	10				11				12				13				14				15				16				17 */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{0},
/*	18				19				1A				1B				1C				1D				1E				1F */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{0},

/*	20				21				22				23				24				25				26				27 */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{},
/*	28				29				2A				2B				2C				2D				2E				2F */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{},

/*	30				31				32				33				34				35				36				37 */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{},
/*	38				39				3A				3B				3C				3D				3E				3F */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{1, I,b},		{1, I,z},		{0},			{},

/*	40				41				42				43				44				45				46				47 */
	{0},			{0},			{0},			{0},			{0},			{0},			{0},			{0},
/*	48				49				4A				4B				4C				4D				4E				4F */
	{0},			{0},			{0},			{0},			{0},			{0},			{0},			{0},

/*	50				51				52				53				54				55				56				57 */
	{0},			{0},			{0},			{0},			{0},			{0},			{0},			{0},
/*	58				59				5A				5B				5C				5D				5E				5F */
	{0},			{0},			{0},			{0},			{0},			{0},			{0},			{0},

/*	60				61				62				63				64				65				66				67 */
	{0},			{0},			{2, G,v, M,a},	{},				{},				{},				{},				{},
/*	68				69						6A				6B							6C		6D		6E		6F  */
	{1, I,z},		{3, G,v, E,v, I,z},		{1, I,b},		{3, G,v, E,v, I,b},			{0},	{0},	{0},	{0},

/*	70				71				72				73				74				75				76				77 */
	{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},
/*	78				79				7A				7B				7C				7D				7E				7F */
	{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},

/*	80				81				82				83				84				85				86				87 */
	{2, E,b, I,b},	{2, E,v, I,z},	{2, E,b, I,b},	{2, E,v, I,b},	{2, E,b, G,b},	{2, E,v, G,v},	{2, E,b, G,b},	{2, E,v, G,v},
/*	88				89				8A				8B				8C				8D				8E				8F */
	{2, E,b, G,b},	{2, E,v, G,v},	{2, G,b, E,b},	{2, G,v, E,v},	{2, E,v, S,w},	{2, G,v, M},	{2, S,w, E,w},	{1, E,v},

/*	90				91				92				93				94				95				96				97*/
	{},				{0},			{0},			{0},			{0},			{0},			{0},			{0},
/*	98				99				9A				9B				9C				9D				9E				9F */
	{},				{},				{1, A,p},		{0},			{1, F,v},		{1, F,v},		{0},			{0},

/*	A0				A1				A2				A3				A4				A5				A6				A7 */
	{1, O,b},		{1, O,v},		{1, O,b},		{1, O,v},		{2, Y,b, X,b},	{2, Y,v, X,v},	{2, X,b, Y,b},	{2, X,v, Y,v},
/*	A8				A9				AA				AB				AC				AD				AE				AF */
	{1, I,b},		{1, I,z},		{1, Y,b},		{1, Y,v},		{1, X,b},		{1, X,v},		{1, Y,b},		{1, Y,v},

/*	B0				B1				B2				B3				B4				B5				B6				B7 */
	{1, I,b},		{1, I,b},		{1, I,b},		{1, I,b},		{1, I,b},		{1, I,b},		{1, I,b},		{1, I,b},
/*	B8				B9				BA				BB				BC				BD				BE				BF */
	{1, I,v},		{1, I,v},		{1, I,v},		{1, I,v},		{1, I,v},		{1, I,v},		{1, I,v},		{1, I,v},

/*	C0				C1				C2				C3				C4				C5				C6				C7 */
	{2, E,b, I,b},	{2, E,v, I,b},	{1, I,w},		{0},			{2, G,z, M,p},	{2, G,z, M,p},	{2, E,b, I,b},	{2, E,v, I,z},
/*	C8				C9				CA				CB				CC				CD				CE				CF */
	{2, I,w, I,b},	{0},			{1, I,w},		{0},			{0},			{1, I,b},		{0},			{0},

/*	D0				D1				D2				D3				D4				D5				D6				D7 */
	{1, E,b},		{1, E,v},		{1, E,b},		{1, E,v},		{1, I,b},		{1, I,b},		{0},			{0},
/*	D8				D9				DA				DB				DC				DD				DE				DF */
	{0},			{0},			{0},			{0},			{0},			{0},			{0},			{0},

/*	E0				E1				E2				E3				E4				E5				E6				E7 */
	{1, J,b},		{1, J,b},		{1, J,b},		{1, J,b},		{1, I,b},		{1, I,b},		{1, I,b},		{1, I,b},
/*	E8				E9				EA				EB				EC				ED				EE				EF */
	{1, J,z},		{1, J,z},		{1, A,p},		{1, J,b},		{0},			{0},			{0},			{0},

/*	F0				F1				F2				F3				F4				F5				F6				F7 */
	{0},			{0},			{0},			{0},			{0},			{0},			{1, E,b},		{1, E,v},
/*	F8				F9				FA				FB				FC				FD				FE				FF */
	{0},			{0},			{0},			{0},			{0},			{0},			{},				{},
};
