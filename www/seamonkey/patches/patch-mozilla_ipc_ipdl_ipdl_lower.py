$NetBSD: patch-mozilla_ipc_ipdl_ipdl_lower.py,v 1.3 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/ipc/ipdl/ipdl/lower.py.orig	2014-10-14 06:36:14.000000000 +0000
+++ mozilla/ipc/ipdl/ipdl/lower.py
@@ -768,7 +768,7 @@ IPDL union type."""
         if self.recursive:
             return self.ptrToType()
         else:
-            return TypeArray(Type('char'), ExprSizeof(self.internalType()))
+            return TypeArray(Type('char'), ExprSizeof(self.internalType()), self.internalType())
 
     def unionValue(self):
         # NB: knows that Union's storage C union is named |mValue|
