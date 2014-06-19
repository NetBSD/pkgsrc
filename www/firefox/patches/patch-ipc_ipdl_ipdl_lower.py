$NetBSD: patch-ipc_ipdl_ipdl_lower.py,v 1.5 2014/06/19 20:31:03 martin Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1026499:
Make sure storage provided for attributes is properly aligned
in the generated C++ code.

--- ipc/ipdl/ipdl/lower.py.orig	2014-06-06 03:15:27.000000000 +0200
+++ ipc/ipdl/ipdl/lower.py	2014-06-17 22:35:35.000000000 +0200
@@ -768,7 +768,7 @@
         if self.recursive:
             return self.ptrToType()
         else:
-            return TypeArray(Type('char'), ExprSizeof(self.internalType()))
+            return TypeArray(Type('char'), ExprSizeof(self.internalType()), self.internalType())
 
     def unionValue(self):
         # NB: knows that Union's storage C union is named |mValue|

