$NetBSD: patch-platform_security_generate__mapfile.py,v 1.1 2024/07/26 08:05:23 nia Exp $

Add NetBSD support.

--- platform/security/generate_mapfile.py.orig	2024-07-25 11:47:02.692533986 +0000
+++ platform/security/generate_mapfile.py
@@ -17,10 +17,10 @@ import buildconfig
 
 
 def main(output, input):
-    if buildconfig.substs['OS_ARCH'] not in ('Linux', 'SunOS', 'Darwin', 'FreeBSD'):
+    if buildconfig.substs['OS_ARCH'] not in ('Linux', 'SunOS', 'Darwin', 'FreeBSD', 'NetBSD'):
         print "Error: unhandled OS_ARCH %s" % buildconfig.substs['OS_ARCH']
         return 1
-    is_linux = buildconfig.substs['OS_ARCH'] in ('Linux', 'SunOS', 'FreeBSD')
+    is_linux = buildconfig.substs['OS_ARCH'] in ('Linux', 'SunOS', 'FreeBSD', 'NetBSD')
 
     with open(input, 'rb') as f:
         for line in f:
@@ -49,4 +49,4 @@ def main(output, input):
             if line and not is_linux:
                 output.write('_')
             output.write(line)
-            output.write('\n')
\ No newline at end of file
+            output.write('\n')
