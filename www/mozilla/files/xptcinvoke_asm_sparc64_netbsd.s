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
        .global XPTC_InvokeByIndex
/*
    XPTC_InvokeByIndex(nsISupports* that, PRUint32 methodIndex,
                   PRUint32 paramCount, nsXPTCVariant* params);
    
*/
/*
 * Note:  To simplify stack handling we allocate an extra stack
 *	frame here.  In principle invoke_copy_to_stack() could
 *	save the parameters our caller's frame and we could
 *	reclaim the stackframe and do a tail call to the
 *	function.  However, this gets complicated....
 *
 * The vtable consist of be:
 *
 *  struct { 
 *    short __delta;
 *    short __index;
 *    union {
 *      P __pfn;
 *      short __delta2; 
 *    } __pfn_or_delta2;
 *  };
 *
 * See gcc/cp/cp-tree.h
 */
	
XPTC_InvokeByIndex:
	save	%sp,-(128+8),%sp    ! room for the register window and this
	sllx	%i2,3,%l0	    ! required stack size in bytes
	sub	%sp,%l0,%sp	    ! create the additional stack space
	    
	add	%sp,0x7ff+128,%l2   ! pointer to parameter save area
	add	%l2,8,%o0	    ! %o1's parameter save area
	mov	%i2,%o1		    ! paramCount
	call	invoke_copy_to_stack
	mov	%i3,%o2		    ! params
!
!   calculate the target address from the vtable
!
	inc	%i1		    ! vTable is zero-based, index is 1 based (?)
	ldx	[%i0],%l1	    ! *that --> vTable
	sllx	%i1,4,%i1	    ! Each vtable entry is 16-bytes long
	add	%i1,%l1,%l1
	ldsh	[%l1],%l0	    ! this adjustor
	add	%l0,%i0,%i0	    ! adjust this
	ldx	[%l1 + 8],%l0	    ! target address

.L15:	ldd	[%sp + 0x7ff + 128 + 120],%f30
.L14:	ldd	[%sp + 0x7ff + 128 + 112],%f28
.L13:	ldd	[%sp + 0x7ff + 128 + 104],%f26
.L12:	ldd	[%sp + 0x7ff + 128 + 96],%f24
.L11:	ldd	[%sp + 0x7ff + 128 + 88],%f22
.L10:	ldd	[%sp + 0x7ff + 128 + 80],%f20
.L9:	ldd	[%sp + 0x7ff + 128 + 72],%f18
.L8:	ldd	[%sp + 0x7ff + 128 + 64],%f16
.L7:	ldd	[%sp + 0x7ff + 128 + 56],%f14
.L6:	ldd	[%sp + 0x7ff + 128 + 48],%f12
.L5:	ldx	[%sp + 0x7ff + 128 + 40],%o5
	ldd	[%sp + 0x7ff + 128 + 40],%f10
.L4:	ldx	[%sp + 0x7ff + 128 + 32],%o4
	ldd	[%sp + 0x7ff + 128 + 32],%f8
.L3:	ldx	[%sp + 0x7ff + 128 + 24],%o3
	ldd	[%sp + 0x7ff + 128 + 24],%f6
.L2:	ldx	[%sp + 0x7ff + 128 + 16],%o2
	ldd	[%sp + 0x7ff + 128 + 16],%f4
.L1:	ldx	[%sp + 0x7ff + 128 +  8],%o1
	ldd	[%sp + 0x7ff + 128 +  8],%f2
.L0:
	jmpl	%l0,%o7		    ! call the routine
! always have a 'this', from the incoming 'that'
	 mov	%i0,%o0
	
	ret
	 restore	%o0,0,%o0   ! propogate return value
