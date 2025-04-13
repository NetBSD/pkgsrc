$NetBSD: patch-khal_icalendar.py,v 1.2 2025/04/13 18:36:18 wiz Exp $

Make it compatible with icalendar>=6.0.0.

Shared upstream via:

 <https://github.com/pimutils/khal/pull/1364>

--- khal/icalendar.py.orig	2025-04-10 21:43:33.000000000 +0000
+++ khal/icalendar.py
@@ -37,6 +37,10 @@ from .utils import generate_random_uid, 
 
 logger = logging.getLogger('khal')
 
+# Force use of pytz because we rely on functionalities not available in
+# zoneinfo.
+icalendar.use_pytz()
+
 
 def split_ics(ics: str, random_uid: bool=False, default_timezone=None) -> List:
     """split an ics string into several according to VEVENT's UIDs
@@ -55,8 +59,8 @@ def split_ics(ics: str, random_uid: bool
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
