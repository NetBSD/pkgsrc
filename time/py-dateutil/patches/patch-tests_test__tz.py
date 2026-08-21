$NetBSD: patch-tests_test__tz.py,v 1.1 2026/08/21 12:17:32 wiz Exp $

Support Internet RFC 8536 TZif files
https://github.com/dateutil/dateutil/pull/1091

--- tests/test_tz.py.orig	2024-03-01 18:35:19.000000000 +0000
+++ tests/test_tz.py
@@ -1642,7 +1642,7 @@ def test_valid_dateutil_format(tz_str, expected):
     'hdfiughdfuig,dfughdfuigpu87ñ::',
     ',dfughdfuigpu87ñ::',
     '-1:WART4WARST,J1,J365/25',
-    'WART4WARST,J1,J365/-25',
+    'WART4WARST,J1,J365/--25',
     'IST-2IDT,M3.4.-1/26,M10.5.0',
     'IST-2IDT,M3,2000,1/26,M10,5,0'
 ])
