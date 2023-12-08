$NetBSD: patch-sipbuild_generator_outputs_code.py,v 1.1 2023/12/08 15:04:29 gdt Exp $

Cherry-pick upstream fix for egregious typo in 6.8.0, which causes
pretty much everything to break.  (Should be fixed in 6.8.1.)

https://www.riverbankcomputing.com/hg/sip/rev/67e0294b505c

--- sipbuild/generator/outputs/code.py.orig	2023-12-08 14:48:11.909538594 +0000
+++ sipbuild/generator/outputs/code.py
@@ -8408,7 +8408,7 @@ def _class_docstring(sf, spec, bindings,
     else:
         is_first = True
 
-    if klass.docstring is None or klass.docstring.signature is not SocstringSignature.DISCARDED:
+    if klass.docstring is None or klass.docstring.signature is not DocstringSignature.DISCARDED:
         for ctor in klass.ctors:
             if ctor.access_specifier is AccessSpecifier.PRIVATE:
                 continue
