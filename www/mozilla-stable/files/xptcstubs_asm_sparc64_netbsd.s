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
 * Copyright (C) 1999 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 */

        .global SharedStub

/*
    in the frame for the function that called SharedStub are the
    rest of the parameters we need

*/

SharedStub:
! we don't create a new frame yet, but work within the frame of the calling
! function to give ourselves the other parameters we want

        mov     %o0, %o1            ! shuffle the index up to 2nd place
        mov     %i0, %o0            ! the original 'this'
        add     %fp, 0x7ff+128+(2*8), %o2    ! previous stack top adjusted to the first argument slot (beyond 'this')
! save off the original incoming parameters that arrived in 
! registers, the ABI guarantees the space for us to do this
        st      %i1, [%o2 +  0]
        st      %i2, [%o2 +  8]
        st      %i3, [%o2 + 16]
        st      %i4, [%o2 + 24]
        st      %i5, [%o2 + 32]
! now we can build our own stack frame
        save    %sp,-(176),%sp   ! room for the register window
! our function now appears to have been called
! as SharedStub(nsISupports* that, PRUint32 index, PRUint32* args)
! so we can just copy these through
        
        mov     %i0, %o0
        mov     %i1, %o1
        mov     %i2, %o2
        call    PrepareAndDispatch
         nop
	ret
	 restore	%o0,0,%o0
! XXXX what's all the rest of this for?
        mov     %o0,%i0             ! propogate return value
        b .LL1
        nop
.LL1:
        ret
         restore

       .size    SharedStub, .-SharedStub
       .type    SharedStub, #function
