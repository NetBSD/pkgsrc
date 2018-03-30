$NetBSD: patch-tablib_packages_dbfpy_dbfnew.py,v 1.1 2018/03/30 06:35:44 adam Exp $

Python 3 compatibility.

--- tablib/packages/dbfpy/dbfnew.py.orig	2018-03-30 06:31:28.000000000 +0000
+++ tablib/packages/dbfpy/dbfnew.py
@@ -160,9 +160,9 @@ if __name__ == '__main__':
     dbfn.add_field("date", 'D', 8)
     dbfn.write("tst.dbf")
     # test new dbf
-    print "*** created tst.dbf: ***"
+    print("*** created tst.dbf: ***")
     dbft = Dbf('tst.dbf', readOnly=0)
-    print repr(dbft)
+    print(repr(dbft))
     # add a record
     rec = DbfRecord(dbft)
     rec['name'] = 'something'
@@ -177,13 +177,13 @@ if __name__ == '__main__':
     rec.store()
 
     # show the records
-    print "*** inserted 2 records into tst.dbf: ***"
-    print repr(dbft)
+    print("*** inserted 2 records into tst.dbf: ***")
+    print(repr(dbft))
     for i1 in range(len(dbft)):
         rec = dbft[i1]
         for fldName in dbft.fieldNames:
-            print '%s:\t %s' % (fldName, rec[fldName])
-        print
+            print('%s:\t %s' % (fldName, rec[fldName]))
+        print()
     dbft.close()
 
     # vim: set et sts=4 sw=4 :
