$NetBSD: patch-tests_test__isoparser.py,v 1.1 2026/08/21 11:21:36 wiz Exp $

test: fix isoparser test collection under newer pytest (parametrize generator) - #1531
https://github.com/dateutil/dateutil/pull/1531

--- tests/test_isoparser.py.orig	2024-03-01 18:35:19.000000000 +0000
+++ tests/test_isoparser.py
@@ -118,12 +118,15 @@ DATETIMES = [datetime(2017, 11, 27, 6, 14, 30, 123456)
     _isoparse_date_and_time(dt, date_fmt, time_fmt, tzoffset)
 
 DATETIMES = [datetime(2017, 11, 27, 6, 14, 30, 123456)]
-@pytest.mark.parametrize('dt', tuple(DATETIMES))
-@pytest.mark.parametrize('date_fmt', YMD_FMTS)
-@pytest.mark.parametrize('time_fmt', (x + sep + '%f' for x in HMS_FMTS
-                                      for sep in '.,'))
-@pytest.mark.parametrize('tzoffset', TZOFFSETS)
-@pytest.mark.parametrize('precision', list(range(3, 7)))
+
+
+@pytest.mark.parametrize("dt", tuple(DATETIMES))
+@pytest.mark.parametrize("date_fmt", YMD_FMTS)
+@pytest.mark.parametrize(
+    "time_fmt", [x + sep + "%f" for x in HMS_FMTS for sep in ".,"]
+)
+@pytest.mark.parametrize("tzoffset", TZOFFSETS)
+@pytest.mark.parametrize("precision", list(range(3, 7)))
 def test_ymd_hms_micro(dt, date_fmt, time_fmt, tzoffset, precision):
     # Truncate the microseconds to the desired precision for the representation
     dt = dt.replace(microsecond=int(round(dt.microsecond, precision-6)))
