$NetBSD: patch-wafhelpers_waf.py,v 1.1 2019/03/25 15:40:35 tnn Exp $

Kludge for waf 2.0. Added include paths in CFLAGS in pkgsrc Makefile instead.

--- wafhelpers/waf.py.orig	2019-01-14 05:40:59.000000000 +0000
+++ wafhelpers/waf.py
@@ -6,14 +6,14 @@ from waflib.TaskGen import before_method
 @feature('bld_include')
 def insert_blddir(self):
     bldnode = self.bld.bldnode.parent.abspath()
-    self.includes += [bldnode]
+#    self.includes += [bldnode]
 
 
 @before_method('apply_incpaths')
 @feature('src_include')
 def insert_srcdir(self):
     srcnode = self.bld.srcnode.abspath()
-    self.includes += ["%s/include" % srcnode]
+#    self.includes += ["%s/include" % srcnode]
 
 
 def manpage_subst_fun(self, code):
