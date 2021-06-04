$NetBSD: patch-flask__admin_tests_sqla_test__basic.py,v 1.1 2021/06/04 05:18:01 adam Exp $

Fix building for Python < 3.7.

--- flask_admin/tests/sqla/test_basic.py.orig	2021-06-04 05:13:49.000000000 +0000
+++ flask_admin/tests/sqla/test_basic.py
@@ -1666,7 +1666,7 @@ def test_hybrid_property_nested():
 
         @hybrid_property
         def fullname(self):
-            return f'{self.firstname} {self.lastname}'
+            return self.firstname + ' ' + self.lastname
 
     class Model2(db.Model):
         id = db.Column(db.Integer, primary_key=True)
