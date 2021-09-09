$NetBSD: patch-isc__dhcp__leases_test__lease6.py,v 1.1 2021/09/09 00:21:13 gutteridge Exp $

Support reference datetime for examining historical dhcpd.leases
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/32
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/33

--- isc_dhcp_leases/test_lease6.py.orig	2017-10-18 08:42:39.000000000 +0000
+++ isc_dhcp_leases/test_lease6.py
@@ -1,13 +1,14 @@
+import datetime
 from unittest import TestCase
-from isc_dhcp_leases.iscdhcpleases import Lease6
+from isc_dhcp_leases.iscdhcpleases import Lease6, utc
 from freezegun import freeze_time
-from datetime import datetime
 
 __author__ = 'Martijn Braam <martijn@brixit.nl>'
 
 
 class TestLease6(TestCase):
     def setUp(self):
+        self.lease_time = datetime.datetime(2015, 8, 18, 16, 55, 37, tzinfo=utc)
         self.lease_data = {
             'binding': 'state active',
             'ends': 'never',
@@ -15,9 +16,8 @@ class TestLease6(TestCase):
             'max-life': '600'
         }
 
-    @freeze_time("2015-07-6 8:15:0")
     def test_init(self):
-        lease = Lease6("2001:610:600:891d::60", self.lease_data, datetime(2015, 8, 18, 16, 55, 37),
+        lease = Lease6("2001:610:600:891d::60", self.lease_data, self.lease_time,
                        "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na")
         self.assertEqual(lease.ip, "2001:610:600:891d::60")
 
@@ -29,30 +29,38 @@ class TestLease6(TestCase):
         self.assertEqual(lease.binding_state, 'active')
         self.assertEqual(lease.preferred_life, 375)
         self.assertEqual(lease.max_life, 600)
-        self.assertEqual(lease.last_communication, datetime(2015, 8, 18, 16, 55, 37))
+        self.assertEqual(lease.last_communication, self.lease_time)
         self.assertEqual(lease.type, Lease6.NON_TEMPORARY)
 
     def test_repr(self):
-        lease = Lease6("2001:610:600:891d::60", self.lease_data, datetime(2015, 8, 18, 16, 55, 37),
+        lease = Lease6("2001:610:600:891d::60", self.lease_data, self.lease_time,
                        "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na")
         self.assertEqual(repr(lease), '<Lease6 2001:610:600:891d::60>')
 
-    @freeze_time("2015-07-6 8:15:0")
-    def test_valid(self):
-        lease = Lease6("2001:610:600:891d::60", self.lease_data, datetime(2015, 8, 18, 16, 55, 37),
-                       "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na")
+    def _test_valid(self, now=None):
+        lease = Lease6("2001:610:600:891d::60", self.lease_data, self.lease_time,
+                       "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na",
+                       now=now)
         self.assertTrue(lease.valid)  # Lease is forever
 
-        lease.end = datetime(2015, 7, 6, 13, 57, 4)
+        lease.end = datetime.datetime(2015, 7, 6, 13, 57, 4, tzinfo=utc)
         self.assertTrue(lease.valid)  # Lease is before end
 
-        lease.end = datetime(2015, 7, 6, 6, 57, 4)
+        lease.end = lease.end - datetime.timedelta(hours=7)
         self.assertFalse(lease.valid)  # Lease is ended
 
+    @freeze_time("2015-07-6 8:15:0")
+    def test_valid_frozen(self):
+        self._test_valid()
+
+    def test_valid_historical(self):
+        self._test_valid(
+            now=datetime.datetime(2015, 7, 6, 8, 15, 0, tzinfo=utc))
+
     def test_eq(self):
-        lease_a = Lease6("2001:610:600:891d::60", self.lease_data, datetime(2015, 8, 18, 16, 55, 37),
+        lease_a = Lease6("2001:610:600:891d::60", self.lease_data, self.lease_time,
                          "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na")
-        lease_b = Lease6("2001:610:600:891d::60", self.lease_data, datetime(2015, 8, 18, 16, 55, 37),
+        lease_b = Lease6("2001:610:600:891d::60", self.lease_data, self.lease_time,
                          "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na")
 
         self.assertEqual(lease_a, lease_b)
@@ -63,3 +71,9 @@ class TestLease6(TestCase):
         lease_b.ip = "2001:610:600:891d::60"
         lease_b.host_identifier = "gd4\352\000\001\000\001\035b\037\322\012\000'\000\000\000"
         self.assertNotEqual(lease_a, lease_b)
+
+    def test_naive_time(self):
+        with self.assertRaises(ValueError):
+            Lease6("2001:610:600:891d::60", self.lease_data, self.lease_time,
+                   "4dv\\352\\000\\001\\000\\001\\035f\\037\\342\\012\\000'\\000\\000\\000", "na",
+                   now=datetime.datetime.now())
