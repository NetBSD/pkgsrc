$NetBSD: patch-khal_icalendar.py,v 1.1 2024/10/31 13:35:05 leot Exp $

Make it compatible with icalendar>=6.0.0.

Shared upstream via:

 <https://github.com/pimutils/khal/pull/1364>

--- khal/icalendar.py.orig	2024-10-31 13:32:32.407885997 +0000
+++ khal/icalendar.py
@@ -37,6 +37,10 @@ from .utils import generate_random_uid, 
 
 logger = logging.getLogger('khal')
 
+# Force use of pytz because we rely on functionalities not available in
+# zoneinfo.
+icalendar.use_pytz()
+
 
 def split_ics(ics: str, random_uid: bool=False, default_timezone=None):
     """split an ics string into several according to VEVENT's UIDs
@@ -56,8 +60,8 @@ def split_ics(ics: str, random_uid: bool
         # Standard Time' for 'Pacific/Auckland' in Olson format), we convert any
         # Windows format timezones to Olson.
         if item.name == 'VTIMEZONE':
-            if item['TZID'] in icalendar.windows_to_olson.WINDOWS_TO_OLSON:
-                key = icalendar.windows_to_olson.WINDOWS_TO_OLSON[item['TZID']]
+            if item['TZID'] in icalendar.timezone.windows_to_olson.WINDOWS_TO_OLSON:
+                key = icalendar.timezone.windows_to_olson.WINDOWS_TO_OLSON[item['TZID']]
             else:
                 key = item['TZID']
             tzs[key] = item
