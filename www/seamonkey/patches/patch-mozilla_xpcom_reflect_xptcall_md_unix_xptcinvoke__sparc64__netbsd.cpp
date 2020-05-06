$NetBSD: patch-mozilla_xpcom_reflect_xptcall_md_unix_xptcinvoke__sparc64__netbsd.cpp,v 1.2 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/xpcom/reflect/xptcall/md/unix/xptcinvoke_sparc64_netbsd.cpp.orig	2020-05-06 05:38:39.777410609 +0000
+++ mozilla/xpcom/reflect/xptcall/md/unix/xptcinvoke_sparc64_netbsd.cpp
@@ -0,0 +1,84 @@
+/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
+ *
+ * The contents of this file are subject to the Netscape Public
+ * License Version 1.1 (the "License"); you may not use this file
+ * except in compliance with the License. You may obtain a copy of
+ * the License at http://www.mozilla.org/NPL/
+ *
+ * Software distributed under the License is distributed on an "AS
+ * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
+ * implied. See the License for the specific language governing
+ * rights and limitations under the License.
+ *
+ * The Original Code is mozilla.org code.
+ *
+ * The Initial Developer of the Original Code is Netscape
+ * Communications Corporation.  Portions created by Netscape are
+ * Copyright (C) 1998 Netscape Communications Corporation. All
+ * Rights Reserved.
+ *
+ * Contributor(s): 
+ */
+
+/* Platform specific code to invoke XPCOM methods on native objects */
+
+#include "xptcprivate.h"
+
+#if !defined(__sparc64__) && !defined(_LP64)
+#error "This code is for Sparc64 only"
+#endif
+
+extern "C" PRUint32
+invoke_copy_to_stack(PRUint64* d, PRUint32 paramCount, nsXPTCVariant* s)
+{
+  /*
+    We need to copy the parameters for this function to locals and use them
+    from there since the parameters occupy the same stack space as the stack
+    we're trying to populate.
+  */
+  PRUint64 *l_d = d;
+  nsXPTCVariant *l_s = s;
+  PRUint64 l_paramCount = paramCount;
+  PRUint64 regCount = 0;  // return the number of registers to load from the stack
+
+  for(PRUint64 i = 0; i < l_paramCount; i++, l_d++, l_s++)
+  {
+    if (regCount < 5) regCount++;
+
+    if (l_s->IsPtrData())
+    {
+      *l_d = (PRUint64)l_s->ptr;
+      continue;
+    }
+    switch (l_s->type)
+    {
+      case nsXPTType::T_I8    : *((PRInt64*)l_d)     = l_s->val.i8;    break;
+      case nsXPTType::T_I16   : *((PRInt64*)l_d)     = l_s->val.i16;   break;
+      case nsXPTType::T_I32   : *((PRInt64*)l_d)     = l_s->val.i32;   break;
+      case nsXPTType::T_I64   : *((PRInt64*)l_d)     = l_s->val.i64;   break;
+      
+      case nsXPTType::T_U8    : *((PRUint64*)l_d)    = l_s->val.u8;    break;
+      case nsXPTType::T_U16   : *((PRUint64*)l_d)    = l_s->val.u16;   break;
+      case nsXPTType::T_U32   : *((PRUint64*)l_d)    = l_s->val.u32;   break;
+      case nsXPTType::T_U64   : *((PRUint64*)l_d)    = l_s->val.u64;   break;
+
+      /* in the case of floats, we want to put the bits in to the
+         64bit space right justified... floats in the paramter array on
+         sparcv9 use odd numbered registers.. %f1, %f3, so we have to skip
+         the space that would be occupied by %f0, %f2, etc.
+      */
+      case nsXPTType::T_FLOAT : *(((float*)l_d) + 1) = l_s->val.f;     break;
+      case nsXPTType::T_DOUBLE: *((double*)l_d)      = l_s->val.d;     break;
+      case nsXPTType::T_BOOL  : *((PRInt64*)l_d)      = l_s->val.b;     break;
+      case nsXPTType::T_CHAR  : *((PRUint64*)l_d)    = l_s->val.c;     break;
+      case nsXPTType::T_WCHAR : *((PRInt64*)l_d)     = l_s->val.wc;    break;
+
+      default:
+        // all the others are plain pointer types
+        *((void**)l_d) = l_s->val.p;
+        break;
+    }
+  }
+  
+  return regCount;
+}
