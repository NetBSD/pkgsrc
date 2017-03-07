$NetBSD: patch-toolkit_library_dependentlibs.py,v 1.1 2017/03/07 20:45:43 ryoon Exp $

--- toolkit/library/dependentlibs.py.orig	2016-11-14 16:12:26.000000000 +0000
+++ toolkit/library/dependentlibs.py
@@ -57,11 +57,15 @@ def dependentlibs_readelf(lib):
     for line in proc.stdout:
         # Each line has the following format:
         #  tag (TYPE)          value
+        # or with BSD readelf:
+        #  tag TYPE            value
         # Looking for NEEDED type entries
         tmp = line.split(' ', 3)
-        if len(tmp) > 3 and tmp[2] == '(NEEDED)':
+        if len(tmp) > 3 and 'NEEDED' in tmp[2]:
             # NEEDED lines look like:
             # 0x00000001 (NEEDED)             Shared library: [libname]
+            # or with BSD readelf:
+            # 0x00000001 NEEDED               Shared library: [libname]
             match = re.search('\[(.*)\]', tmp[3])
             if match:
                 deps.append(match.group(1))
