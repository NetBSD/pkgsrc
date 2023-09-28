$NetBSD: patch-pdfrw_pdfreader.py,v 1.1 2023/09/28 22:19:37 joerg Exp $

Handle the case where the xref index starts with the free list, even if
it is supposed to be at a non-zero offset.

--- pdfrw/pdfreader.py.orig	2023-08-31 20:47:41.383788598 +0000
+++ pdfrw/pdfreader.py
@@ -408,7 +408,9 @@ class PdfReader(PdfDict):
                 if tok == 'trailer':
                     return
                 startobj = int(tok)
-                for objnum in range(startobj, startobj + int(next())):
+                objnum = startobj
+                lastobj = int(next())
+                while objnum < startobj + lastobj:
                     offset = int(next())
                     generation = int(next())
                     inuse = next()
@@ -417,6 +419,11 @@ class PdfReader(PdfDict):
                             setdefault((objnum, generation), offset)
                     elif inuse != 'f':
                         raise ValueError
+                    elif startobj and objnum==startobj and offset == 0 and generation == 65535:
+                        startobj = 0
+                        objnum = startobj
+                        log.warning('Invalid first object in non-zero-offset xref table, offset ignored')
+                    objnum += 1
         except:
             pass
         try:
