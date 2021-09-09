$NetBSD: patch-isc__dhcp__leases_iscdhcpleases.py,v 1.1 2021/09/09 00:21:13 gutteridge Exp $

Support reference datetime for examining historical dhcpd.leases
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/32
https://github.com/MartijnBraam/python-isc-dhcp-leases/pull/33

--- isc_dhcp_leases/iscdhcpleases.py.orig	2018-04-13 13:10:47.000000000 +0000
+++ isc_dhcp_leases/iscdhcpleases.py
@@ -8,6 +8,31 @@ import gzip
 from six import iteritems
 
 
+try:
+    utc = datetime.timezone.utc
+except:
+    # Support Python 2.7
+    class UTC(datetime.tzinfo):
+        def fromutc(self, dt):
+            return dt
+
+        def utcffset(self, dt):
+            return datetime.timedelta(0)
+
+        def dst(self, dt):
+            return None
+
+        def tzname(self, dt):
+            return 'UTC'
+
+
+    utc = UTC()
+
+
+def check_datetime(dt):
+    if not (dt is None or (isinstance(dt, datetime.datetime) and dt.tzinfo)):
+        raise ValueError('None or offset-aware datetime required')
+
 def parse_time(s):
     """
     Like datetime.datetime.strptime(s, "%w %Y/%m/%d %H:%M:%S") but 5x faster.
@@ -23,7 +48,7 @@ def parse_time(s):
         hour, minute, sec = time_part.split(':')
         result = datetime.datetime(*map(int, (year, mon, day, hour, minute, sec)))
 
-    return result
+    return result.replace(tzinfo=utc)
 
 
 def _extract_prop_option(line):
@@ -108,9 +133,12 @@ class IscDhcpLeases(object):
         r"ia-(?P<type>ta|na|pd) \"(?P<id>[^\"\\]*(?:\\.[^\"\\]*)*)\" {(?P<config>[\s\S]+?)\n}")
     regex_iaaddr = re.compile(r"ia(addr|prefix) (?P<ip>[0-9a-f:]+(/[0-9]+)?) {(?P<config>[\s\S]+?)\n\s+}")
 
-    def __init__(self, filename, gzip=False):
+    def __init__(self, filename, gzip=False, now=None):
+        check_datetime(now)
+
         self.filename = filename
         self.gzip = gzip
+        self.now = now
 
     def get(self, include_backups=False):
         """
@@ -129,7 +157,7 @@ class IscDhcpLeases(object):
                 if 'hardware' not in properties and not include_backups:
                     # E.g. rows like {'binding': 'state abandoned', ...}
                     continue
-                lease = Lease(block['ip'], properties=properties, options=options, sets=sets)
+                lease = Lease(block['ip'], properties=properties, options=options, sets=sets, now=self.now)
                 leases.append(lease)
 
             for match in self.regex_leaseblock6.finditer(lease_data):
@@ -145,7 +173,7 @@ class IscDhcpLeases(object):
                     properties, options, sets = _extract_properties(block['config'])
 
                     lease = Lease6(block['ip'], properties, last_client_communication, host_identifier, block_type,
-                                   options=options, sets=sets)
+                                   options=options, sets=sets, now=self.now)
                     leases.append(lease)
 
         return leases
@@ -177,7 +205,9 @@ class BaseLease(object):
         sets        Dict of key-value set statement values from this lease
     """
 
-    def __init__(self, ip, properties, options=None, sets=None):
+    def __init__(self, ip, properties, options=None, sets=None, now=None):
+        check_datetime(now)
+
         if options is None:
             options = {}
 
@@ -189,6 +219,7 @@ class BaseLease(object):
         self.options = options
         self.sets = sets
         _, self.binding_state = properties['binding'].split(' ', 1)
+        self._now = now
 
     @property
     def active(self):
@@ -198,6 +229,15 @@ class BaseLease(object):
         """
         return self.binding_state == 'active'
 
+    @property
+    def now(self):
+        """
+        :return: datetime: real current time, unless a historical time is set
+        """
+        if self._now:
+            return self._now
+        else:
+            return datetime.datetime.utcnow().replace(tzinfo=utc)
 
 class Lease(BaseLease):
     """
@@ -214,8 +254,8 @@ class Lease(BaseLease):
         data            Dict of all the info in the dhcpd.leases file for this lease
     """
 
-    def __init__(self, ip, properties, options=None, sets=None):
-        super(Lease, self).__init__(ip, properties=properties, options=options, sets=sets)
+    def __init__(self, ip, properties, **kwargs):
+        super(Lease, self).__init__(ip, properties=properties, **kwargs)
         if 'starts' in properties:
             self.start = parse_time(properties['starts'])
         else:
@@ -242,14 +282,14 @@ class Lease(BaseLease):
         """
         if self.end is None:
             if self.start is not None:
-                return self.start <= datetime.datetime.utcnow()
+                return self.start <= self.now
             else:
                 return True
         else:
             if self.start is not None:
-                return self.start <= datetime.datetime.utcnow() <= self.end
+                return self.start <= self.now <= self.end
             else:
-                return datetime.datetime.utcnow() <= self.end
+                return self.now <= self.end
 
     def __repr__(self):
         return "<Lease {} for {} ({})>".format(self.ip, self.ethernet, self.hostname)
@@ -278,11 +318,8 @@ class Lease6(BaseLease):
 
     (TEMPORARY, NON_TEMPORARY, PREFIX_DELEGATION) = ('ta', 'na', 'pd')
 
-    def __init__(self, ip, properties, cltt, host_identifier, address_type, options=None, sets=None):
-        options = options or {}
-        sets = sets or {}
-
-        super(Lease6, self).__init__(ip, properties=properties, options=options, sets=sets)
+    def __init__(self, ip, properties, cltt, host_identifier, address_type, **kwargs):
+        super(Lease6, self).__init__(ip, properties=properties, **kwargs)
 
         self.type = address_type
         self.last_communication = cltt
@@ -315,7 +352,7 @@ class Lease6(BaseLease):
         if self.end is None:
             return True
         else:
-            return datetime.datetime.utcnow() <= self.end
+            return self.now <= self.end
 
     def __repr__(self):
         return "<Lease6 {}>".format(self.ip)
