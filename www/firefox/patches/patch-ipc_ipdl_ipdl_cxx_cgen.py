$NetBSD: patch-ipc_ipdl_ipdl_cxx_cgen.py,v 1.1 2014/06/19 20:31:03 martin Exp $

Part of https://bugzilla.mozilla.org/show_bug.cgi?id=1026499:
Make sure storage provided for attributes is properly aligned
in the generated C++ code.

--- ipc/ipdl/ipdl/cxx/cgen.py.orig	2014-06-06 03:15:27.000000000 +0200
+++ ipc/ipdl/ipdl/cxx/cgen.py	2014-06-18 18:10:27.000000000 +0200
@@ -101,6 +101,7 @@
     def visitDecl(self, d):
         # C-syntax arrays make code generation much more annoying
         if isinstance(d.type, TypeArray):
+	    self.write('MOZ_ALIGNED_DECL(')
             d.type.basetype.accept(self)
         else:
             d.type.accept(self)
@@ -111,7 +112,9 @@
         if isinstance(d.type, TypeArray):
             self.write('[')
             d.type.nmemb.accept(self)
-            self.write(']')
+            self.write('], MOZ_ALIGNOF(')
+	    d.type.alignType.accept(self)
+	    self.write('))')
 
     def visitParam(self, p):
         self.visitDecl(p)

