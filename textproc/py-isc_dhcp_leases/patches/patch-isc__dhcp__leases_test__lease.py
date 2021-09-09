$NetBSD: patch-isc__dhcp__leases_test__lease.py,v 1.1 2021/09/09 00:21:13 gutteridge Exp $

Support reference datetime for examining historical dhcpd.leases
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/32
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/33

--- isc_dhcp_leases/test_lease.py.orig	2018-04-13 13:10:47.000000000 +0000
+++ isc_dhcp_leases/test_lease.py
@@ -1,7 +1,7 @@
+import datetime
 from unittest import TestCase
-from isc_dhcp_leases.iscdhcpleases import Lease
+from isc_dhcp_leases.iscdhcpleases import Lease, utc
 from freezegun import freeze_time
-from datetime import datetime
 
 __author__ = 'Martijn Braam <martijn@brixit.nl>'
 
@@ -19,14 +19,14 @@ class TestLease(TestCase):
             'client-hostname': '"Satellite-C700"'
         }
 
-    @freeze_time("2015-07-6 8:15:0")
     def test_init(self):
         lease = Lease("192.168.0.1", self.lease_data)
         self.assertEqual(lease.ip, "192.168.0.1")
         self.assertEqual(lease.hardware, "ethernet")
         self.assertEqual(lease.ethernet, "60:a4:4c:b5:6a:dd")
         self.assertEqual(lease.hostname, "Satellite-C700")
-        self.assertEqual(lease.start, datetime(2013, 12, 10, 12, 57, 4))
+        self.assertEqual(
+            lease.start, datetime.datetime(2013, 12, 10, 12, 57, 4, tzinfo=utc))
         self.assertIsNone(lease.end)
         self.assertTrue(lease.valid)
         self.assertFalse(lease.active)
@@ -36,21 +36,28 @@ class TestLease(TestCase):
         lease = Lease("192.168.0.1", self.lease_data)
         self.assertEqual(repr(lease), '<Lease 192.168.0.1 for 60:a4:4c:b5:6a:dd (Satellite-C700)>')
 
-    @freeze_time("2015-07-6 8:15:0")
-    def test_valid(self):
-        lease = Lease("192.168.0.1", self.lease_data)
+    def _test_valid(self, now=None):
+        lease = Lease("192.168.0.1", self.lease_data, now=now)
         self.assertTrue(lease.valid)  # Lease is forever
 
-        lease.end = datetime(2015, 7, 6, 13, 57, 4)
+        lease.end = datetime.datetime(2015, 7, 6, 13, 57, 4, tzinfo=utc)
         self.assertTrue(lease.valid)  # Lease is within start and end
 
-        lease.end = datetime(2015, 7, 6, 6, 57, 4)
+        lease.end = lease.end - datetime.timedelta(hours=7)
         self.assertFalse(lease.valid)  # Lease is ended
 
-        lease.start = datetime(2015, 7, 6, 12, 57, 4)
-        lease.end = datetime(2015, 7, 6, 13, 57, 4)
+        lease.start = datetime.datetime(2015, 7, 6, 12, 57, 4, tzinfo=utc)
+        lease.end = lease.start + datetime.timedelta(hours=1)
         self.assertFalse(lease.valid)  # Lease is in the future
 
+    @freeze_time("2015-07-6 8:15:0")
+    def test_valid_frozen(self):
+        self._test_valid()
+
+    def test_valid_historical(self):
+        self._test_valid(
+            now=datetime.datetime(2015, 7, 6, 8, 15, 0, tzinfo=utc))
+
     def test_eq(self):
         lease_a = Lease("192.168.0.1", self.lease_data)
         lease_b = Lease("192.168.0.1", self.lease_data)
@@ -83,8 +90,12 @@ class TestLease(TestCase):
         lease = Lease("192.168.0.1", self.lease_data)
         self.assertTrue(lease.valid)  # Lease is forever
 
-        lease.end = datetime(2015, 7, 6, 6, 57, 4)
+        lease.end = datetime.datetime(2015, 7, 6, 6, 57, 4, tzinfo=utc)
         self.assertFalse(lease.valid)  # Lease is ended
 
-        lease.end = datetime(2015, 7, 6, 9, 57, 4)
+        lease.end = lease.end + datetime.timedelta(hours=3)
         self.assertTrue(lease.valid)  # Lease is not expired
+
+    def test_naive_time(self):
+        with self.assertRaises(ValueError):
+            Lease("192.168.0.1", self.lease_data, now=datetime.datetime.now())
