$NetBSD: patch-mozilla_ipc_ipdl_ipdl_cxx_cgen.py,v 1.1 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/ipc/ipdl/ipdl/cxx/cgen.py.orig	2014-10-14 06:36:14.000000000 +0000
+++ mozilla/ipc/ipdl/ipdl/cxx/cgen.py
@@ -101,6 +101,7 @@ class CxxCodeGen(CodePrinter, Visitor):
     def visitDecl(self, d):
         # C-syntax arrays make code generation much more annoying
         if isinstance(d.type, TypeArray):
+            self.write('MOZ_ALIGNED_DECL(')
             d.type.basetype.accept(self)
         else:
             d.type.accept(self)
@@ -111,7 +112,9 @@ class CxxCodeGen(CodePrinter, Visitor):
         if isinstance(d.type, TypeArray):
             self.write('[')
             d.type.nmemb.accept(self)
-            self.write(']')
+            self.write('], MOZ_ALIGNOF(')
+            d.type.alignType.accept(self)
+            self.write('))')
 
     def visitParam(self, p):
         self.visitDecl(p)
