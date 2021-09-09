$NetBSD: patch-isc__dhcp__leases_test__iscDhcpLeases.py,v 1.1 2021/09/09 00:21:13 gutteridge Exp $

Support reference datetime for examining historical dhcpd.leases
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/32
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/33

--- isc_dhcp_leases/test_iscDhcpLeases.py.orig	2018-04-13 13:10:47.000000000 +0000
+++ isc_dhcp_leases/test_iscDhcpLeases.py
@@ -1,15 +1,16 @@
+import datetime
 from unittest import TestCase
-from isc_dhcp_leases.iscdhcpleases import IscDhcpLeases, Lease, Lease6
+from isc_dhcp_leases.iscdhcpleases import IscDhcpLeases, Lease, Lease6, utc
 from freezegun import freeze_time
-from datetime import datetime
 
 __author__ = 'Martijn Braam <martijn@brixit.nl>'
 
 
 class TestIscDhcpLeases(TestCase):
-    @freeze_time("2015-07-6 8:15:0")
-    def test_get(self):
-        leases = IscDhcpLeases("isc_dhcp_leases/test_files/debian7.leases")
+    def _test_get(self, now=None):
+        leases = IscDhcpLeases("isc_dhcp_leases/test_files/debian7.leases", now=now)
+        lease_start = datetime.datetime(2013, 12, 10, 12, 57, 4, tzinfo=utc)
+        lease_end = lease_start + datetime.timedelta(minutes=10)
         result = leases.get()
         self.assertEqual(len(result), 5)
         self.assertEqual(result[0].ip, "10.0.0.10")
@@ -19,11 +20,13 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].hardware, "ethernet")
         self.assertEqual(result[0].ethernet, "60:a4:4c:b5:6a:dd")
         self.assertEqual(result[0].hostname, "")
-        self.assertEqual(result[0].start, datetime(2013, 12, 10, 12, 57, 4))
-        self.assertEqual(result[0].end, datetime(2013, 12, 10, 13, 7, 4))
+        self.assertEqual(result[0].start, lease_start)
+        self.assertEqual(result[0].end, lease_end)
         self.assertEqual(result[0].sets, {'vendor-class-identifier': 'Some Vendor Identifier'})
 
-        leases = IscDhcpLeases("isc_dhcp_leases/test_files/pfsense.leases")
+        leases = IscDhcpLeases("isc_dhcp_leases/test_files/pfsense.leases", now=now)
+        lease_start = datetime.datetime(2015, 7, 6, 7, 50, 42, tzinfo=utc)
+        lease_end = lease_start + datetime.timedelta(minutes=30)
         result = leases.get()
         self.assertEqual(len(result), 2)
         self.assertEqual(result[0].ip, "10.0.10.72")
@@ -33,10 +36,10 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].hardware, "ethernet")
         self.assertEqual(result[0].ethernet, "64:5a:04:6a:07:a2")
         self.assertEqual(result[0].hostname, "Satellite-C700")
-        self.assertEqual(result[0].start, datetime(2015, 7, 6, 7, 50, 42))
-        self.assertEqual(result[0].end, datetime(2015, 7, 6, 8, 20, 42))
+        self.assertEqual(result[0].start, lease_start)
+        self.assertEqual(result[0].end, lease_end)
 
-        leases = IscDhcpLeases("isc_dhcp_leases/test_files/dhcpd6-4.2.4.leases")
+        leases = IscDhcpLeases("isc_dhcp_leases/test_files/dhcpd6-4.2.4.leases", now=now)
         result = leases.get()
         self.assertEqual(len(result), 2)
         self.assertEqual(result[0].ip, "2001:610:600:891d::60")
@@ -48,7 +51,9 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].binding_state, 'active')
         self.assertEqual(result[0].preferred_life, 375)
         self.assertEqual(result[0].max_life, 600)
-        self.assertEqual(result[0].last_communication, datetime(2015, 8, 18, 16, 55, 37))
+        self.assertEqual(
+            result[0].last_communication,
+            datetime.datetime(2015, 8, 18, 16, 55, 37, tzinfo=utc))
         self.assertEqual(result[0].type, Lease6.NON_TEMPORARY)
 
         self.assertEqual(result[1].ip, "2001:610:500:fff::/64")
@@ -60,10 +65,12 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[1].binding_state, 'active')
         self.assertEqual(result[1].preferred_life, 175)
         self.assertEqual(result[1].max_life, 200)
-        self.assertEqual(result[1].last_communication, datetime(2015, 8, 18, 16, 55, 40))
+        self.assertEqual(
+            result[1].last_communication,
+            datetime.datetime(2015, 8, 18, 16, 55, 40, tzinfo=utc))
         self.assertEqual(result[1].type, Lease6.PREFIX_DELEGATION)
 
-        leases = IscDhcpLeases("isc_dhcp_leases/test_files/dhcpd6-4.3.3.leases")
+        leases = IscDhcpLeases("isc_dhcp_leases/test_files/dhcpd6-4.3.3.leases", now=now)
         result = leases.get()
         self.assertEqual(len(result), 4)
         self.assertEqual(result[0].ip, "2001:10:10::106")
@@ -75,7 +82,9 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].binding_state, 'active')
         self.assertEqual(result[0].preferred_life, 540)
         self.assertEqual(result[0].max_life, 864)
-        self.assertEqual(result[0].last_communication, datetime(2016, 1, 6, 14, 50, 34))
+        self.assertEqual(
+            result[0].last_communication,
+            datetime.datetime(2016, 1, 6, 14, 50, 34, tzinfo=utc))
         self.assertEqual(result[0].type, Lease6.NON_TEMPORARY)
         self.assertEqual(result[0].sets, dict(iana='2001:10:10:0:0:0:0:106', clientduid='0100011cf710a5002722332b34'))
 
@@ -88,13 +97,17 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[1].binding_state, 'active')
         self.assertEqual(result[1].preferred_life, 540)
         self.assertEqual(result[1].max_life, 864)
-        self.assertEqual(result[1].last_communication, datetime(2016, 1, 6, 14, 52, 37))
+        self.assertEqual(
+            result[1].last_communication,
+            datetime.datetime(2016, 1, 6, 14, 52, 37, tzinfo=utc))
         self.assertEqual(result[1].type, Lease6.PREFIX_DELEGATION)
         self.assertEqual(result[1].sets, dict(iapd='2001:10:30:ff00:0:0:0:0', pdsize='56',
                                               pdnet='2001:10:30:ff00:0:0:0:0/56',
                                               clientduid='0100011d344c000025906ba134'))
 
-        leases = IscDhcpLeases("isc_dhcp_leases/test_files/options.leases")
+        leases = IscDhcpLeases("isc_dhcp_leases/test_files/options.leases", now=now)
+        lease_start = datetime.datetime(2016, 2, 27, 7, 11, 41, tzinfo=utc)
+        lease_end = lease_start + datetime.timedelta(hours=2)
         result = leases.get()
         self.assertEqual(len(result), 1)
         self.assertEqual(result[0].ip, "10.10.10.10")
@@ -104,8 +117,8 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].hardware, "ethernet")
         self.assertEqual(result[0].ethernet, "24:65:11:d9:a6:b3")
         self.assertEqual(result[0].hostname, "KRONOS")
-        self.assertEqual(result[0].start, datetime(2016, 2, 27, 7, 11, 41))
-        self.assertEqual(result[0].end, datetime(2016, 2, 27, 9, 11, 41))
+        self.assertEqual(result[0].start, lease_start)
+        self.assertEqual(result[0].end, lease_end)
         self.assertEqual(len(result[0].options), 4)
         self.assertDictEqual(result[0].options,
                              {'agent.DOCSIS-device-class': '2',
@@ -113,7 +126,9 @@ class TestIscDhcpLeases(TestCase):
                               'agent.remote-id': 'a4:a2:4a:33:db:e5',
                               'agent.unknown-9': '0:0:11:8b:6:1:4:1:2:3:0'})
 
-        leases = IscDhcpLeases("isc_dhcp_leases/test_files/static.leases")
+        leases = IscDhcpLeases("isc_dhcp_leases/test_files/static.leases", now=now)
+        lease_start = datetime.datetime(2015, 9, 10, 0, 29, 0, tzinfo=utc)
+        lease_end = None
         result = leases.get()
         self.assertEqual(len(result), 1)
         self.assertEqual(result[0].ip, "10.0.0.15")
@@ -121,12 +136,28 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].active, False)
         self.assertEqual(result[0].binding_state, "free")
         self.assertEqual(result[0].hardware, "ethernet")
-        self.assertEqual(result[0].start, datetime(2015, 9, 10, 0, 29, 0))
-        self.assertIsNone(result[0].end)
+        self.assertEqual(result[0].start, lease_start)
+        self.assertEqual(result[0].end, lease_end)
+
+    @freeze_time("2015-07-6 8:15:0")
+    def test_get_frozen(self):
+        self._test_get()
+
+    def test_get_historical(self):
+        self._test_get(
+            now=datetime.datetime(2015, 7, 6, 8, 15, 0, tzinfo=utc))
 
     @freeze_time("2015-06-6 8:15:0")
     def test_backup_leases(self):
         leases = IscDhcpLeases("isc_dhcp_leases/test_files/backup.leases")
+        lease_start = [
+            datetime.datetime(2017, 10, 5, 15, 22, 29, tzinfo=utc),
+            datetime.datetime(2017, 10, 10, 12, 5, 14, tzinfo=utc),
+        ]
+        lease_end = [
+            datetime.datetime(2017, 10, 16, 8, 9, 23, tzinfo=utc),
+            None,
+        ]
         result = leases.get()
         self.assertEqual(len(result), 1)
         result = leases.get(include_backups=True)
@@ -136,19 +167,27 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].active, False)
         self.assertEqual(result[0].binding_state, "backup")
         self.assertEqual(result[0].hardware, "ethernet")
-        self.assertEqual(result[0].start, datetime(2017, 10, 5, 15, 22, 29))
-        self.assertEqual(result[0].end, datetime(2017, 10, 16, 8, 9, 23))
+        self.assertEqual(result[0].start, lease_start[0])
+        self.assertEqual(result[0].end, lease_end[0])
         self.assertEqual(result[1].ip, "10.0.0.2")
         self.assertEqual(result[1].valid, False)
         self.assertEqual(result[1].active, False)
         self.assertEqual(result[1].binding_state, "backup")
         self.assertIsNone(result[1].hardware)
-        self.assertEqual(result[1].start, datetime(2017, 10, 10, 12, 5, 14))
-        self.assertIsNone(result[1].end)
+        self.assertEqual(result[1].start, lease_start[1])
+        self.assertEqual(result[1].end, lease_end[1])
 
     @freeze_time("2015-06-6 8:15:0")
     def test_epoch_leases(self):
         leases = IscDhcpLeases("isc_dhcp_leases/test_files/epoch.leases")
+        lease_start = [
+            datetime.datetime(2017, 10, 5, 15, 22, 29, tzinfo=utc),
+            datetime.datetime(2017, 10, 10, 12, 5, 14, tzinfo=utc),
+        ]
+        lease_end = [
+            datetime.datetime(2017, 10, 16, 8, 9, 23, tzinfo=utc),
+            None,
+        ]
         result = leases.get()
         self.assertEqual(len(result), 1)
         result = leases.get(include_backups=True)
@@ -158,15 +197,15 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].active, False)
         self.assertEqual(result[0].binding_state, "backup")
         self.assertEqual(result[0].hardware, "ethernet")
-        self.assertEqual(result[0].start, datetime(2017, 10, 5, 15, 22, 29))
-        self.assertEqual(result[0].end, datetime(2017, 10, 16, 8, 9, 23))
+        self.assertEqual(result[0].start, lease_start[0])
+        self.assertEqual(result[0].end, lease_end[0])
         self.assertEqual(result[1].ip, "10.0.0.2")
         self.assertEqual(result[1].valid, False)
         self.assertEqual(result[1].active, False)
         self.assertEqual(result[1].binding_state, "backup")
         self.assertIsNone(result[1].hardware)
-        self.assertEqual(result[1].start, datetime(2017, 10, 10, 12, 5, 14))
-        self.assertIsNone(result[1].end)
+        self.assertEqual(result[1].start, lease_start[1])
+        self.assertEqual(result[1].end, lease_end[1])
 
     @freeze_time("2015-07-6 8:15:0")
     def test_get_current(self):
@@ -201,6 +240,8 @@ class TestIscDhcpLeases(TestCase):
 
     def test_gzip_handling(self):
         leases = IscDhcpLeases("isc_dhcp_leases/test_files/debian7.leases.gz", True)
+        lease_start = datetime.datetime(2013, 12, 10, 12, 57, 4, tzinfo=utc)
+        lease_end = lease_start + datetime.timedelta(minutes=10)
         result = leases.get()
         self.assertEqual(len(result), 5)
         self.assertEqual(result[0].ip, "10.0.0.10")
@@ -210,6 +251,10 @@ class TestIscDhcpLeases(TestCase):
         self.assertEqual(result[0].hardware, "ethernet")
         self.assertEqual(result[0].ethernet, "60:a4:4c:b5:6a:dd")
         self.assertEqual(result[0].hostname, "")
-        self.assertEqual(result[0].start, datetime(2013, 12, 10, 12, 57, 4))
-        self.assertEqual(result[0].end, datetime(2013, 12, 10, 13, 7, 4))
+        self.assertEqual(result[0].start, lease_start)
+        self.assertEqual(result[0].end, lease_end)
         self.assertEqual(result[0].sets, {'vendor-class-identifier': 'Some Vendor Identifier'})
+
+    def test_naive_time(self):
+        with self.assertRaises(ValueError):
+            IscDhcpLeases("isc_dhcp_leases/test_files/debian7.leases", now=datetime.datetime.now())
