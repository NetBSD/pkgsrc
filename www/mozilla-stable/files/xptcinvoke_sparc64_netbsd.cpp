/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 */

/* Platform specific code to invoke XPCOM methods on native objects */

#include "xptcprivate.h"

/* solaris defines __sparc for workshop compilers and 
   linux defines __sparc__ */

#if !defined(__sparc64__) && !defined(__sparc_v9__)
#error "This code is for Sparc64 only"
#endif

typedef unsigned nsXPCVariant;

extern "C" PRUint32
invoke_count_words(PRUint32 paramCount, nsXPTCVariant* s)
{
    PRUint32 result = 0;
    for(PRUint32 i = 0; i < paramCount; i++, s++)
    {
        if(s->IsPtrData())
        {
            result++;
            continue;
        }
        switch(s->type)
        {
        case nsXPTType::T_I8     :
        case nsXPTType::T_I16    :
        case nsXPTType::T_I32    :
        case nsXPTType::T_I64    :
            result++;
            break;
        case nsXPTType::T_U8     :
        case nsXPTType::T_U16    :
        case nsXPTType::T_U32    :
        case nsXPTType::T_U64    :
            result++;
            break;
        case nsXPTType::T_FLOAT  :
        case nsXPTType::T_DOUBLE :
            result++;
            break;
        case nsXPTType::T_BOOL   :
        case nsXPTType::T_CHAR   :
        case nsXPTType::T_WCHAR  :
            result++;
            break;
        default:
            // all the others are plain pointer types
            result++;
            break;
        }
    }
    // nuts, I know there's a cooler way of doing this, but it's late
    // now and it'll probably come to me in the morning.
    if (result & 0x7) result += 8 - (result & 0x7);     // ensure 16-byte alignment
    return result;
}

extern "C" PRUint32
invoke_copy_to_stack(PRUint64* d, PRUint32 paramCount, nsXPTCVariant* s)
{
/*
    We need to copy the parameters for this function to locals and use them
    from there since the parameters occupy the same stack space as the stack
    we're trying to populate.
*/
    uint64 *l_d = d;
    nsXPTCVariant *l_s = s;
    uint32 l_paramCount = paramCount;
    uint32 regCount = 0;	// return the number of registers to load from the stack

    for(uint32 i = 0; i < l_paramCount; i++, l_d++, l_s++)
    {
	if (regCount < 5) regCount++;
        if(l_s->IsPtrData())
        {
            *((void**)l_d) = l_s->ptr;
            continue;
        }
        switch(l_s->type)
        {
        case nsXPTType::T_I8     : *((int64*)  l_d) = l_s->val.i8;          break;
        case nsXPTType::T_I16    : *((int64*)  l_d) = l_s->val.i16;         break;
        case nsXPTType::T_I32    : *((int64*)  l_d) = l_s->val.i32;         break;
        case nsXPTType::T_I64    : *((int64*)  l_d) = l_s->val.i64;         break;
        case nsXPTType::T_U64    : *((uint64*) l_d) = l_s->val.u64;         break;
        case nsXPTType::T_U8     : *((uint64*) l_d) = l_s->val.u8;          break;
        case nsXPTType::T_U16    : *((uint64*) l_d) = l_s->val.u16;         break;
        case nsXPTType::T_U32    : *((uint64*) l_d) = l_s->val.u32;         break;
        case nsXPTType::T_FLOAT  : 
            struct floats { float pad; float data; };
            ((floats*) l_d)->pad = 0;
            ((floats*) l_d)->data = l_s->val.f;           break;
        case nsXPTType::T_DOUBLE : *((uint64*) l_d) = l_s->val.u64;         break;
        case nsXPTType::T_BOOL   : *((uint64*) l_d) = l_s->val.b;           break;
        case nsXPTType::T_CHAR   : *((uint64*) l_d) = l_s->val.c;           break;
        case nsXPTType::T_WCHAR  : *((uint64*) l_d) = l_s->val.wc;          break;
        default:
            // all the others are plain pointer types
            *((void**)l_d) = l_s->val.p;
            break;
        }
    }
    return regCount;
}

