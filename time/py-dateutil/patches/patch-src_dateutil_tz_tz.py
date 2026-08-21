$NetBSD: patch-src_dateutil_tz_tz.py,v 1.1 2026/08/21 12:17:32 wiz Exp $

Support Internet RFC 8536 TZif files
https://github.com/dateutil/dateutil/pull/1091

--- src/dateutil/tz/tz.py.orig	2024-03-01 18:35:19.000000000 +0000
+++ src/dateutil/tz/tz.py
@@ -376,7 +376,8 @@ class _tzfile(object):
     information read from binary tzfiles.
     """
     attrs = ['trans_list', 'trans_list_utc', 'trans_idx', 'ttinfo_list',
-             'ttinfo_std', 'ttinfo_dst', 'ttinfo_before', 'ttinfo_first']
+             'ttinfo_std', 'ttinfo_dst', 'ttinfo_before', 'ttinfo_first',
+             'tz_string_info']
 
     def __init__(self, **kwargs):
         for attr in self.attrs:
@@ -486,8 +487,6 @@ class tzfile(_tzinfo):
             setattr(self, '_' + attr, getattr(tzobj, attr))
 
     def _read_tzfile(self, fileobj):
-        out = _tzfile()
-
         # From tzfile(5):
         #
         # The time zone information files used by tzset(3)
@@ -500,8 +499,22 @@ class tzfile(_tzinfo):
         if fileobj.read(4).decode() != "TZif":
             raise ValueError("magic not found")
 
-        fileobj.read(16)
+        version = fileobj.read(1).decode()
+        fileobj.read(15)
 
+        out = self._read_data_block(fileobj, 4, 'l')
+        if version < '2':
+            return out
+        fileobj.read(20)
+        out = self._read_data_block(fileobj, 8, 'q')
+        fileobj.read(1)
+        tz_string = fileobj.readline()[:-1].decode()
+        out.tz_string_info = tzstr(tz_string, posix_offset=True)
+        return out
+
+    def _read_data_block(self, fileobj, time_size, format_char):
+        out = _tzfile()
+
         (
             # The number of UTC/local indicators stored in the file.
             ttisgmtcnt,
@@ -527,16 +540,18 @@ class tzfile(_tzinfo):
 
         ) = struct.unpack(">6l", fileobj.read(24))
 
-        # The above header is followed by tzh_timecnt four-byte
-        # values  of  type long,  sorted  in ascending order.
+        # The above header is followed by tzh_timecnt TIME_SIZE-byte
+        # signed integer values, sorted in ascending order.
         # These values are written in ``standard'' byte order.
         # Each is used as a transition time (as  returned  by
         # time(2)) at which the rules for computing local time
         # change.
 
         if timecnt:
-            out.trans_list_utc = list(struct.unpack(">%dl" % timecnt,
-                                                    fileobj.read(timecnt*4)))
+            format = ">%d%s" % (timecnt, format_char)
+            size = timecnt * time_size
+            out.trans_list_utc = list(struct.unpack(format,
+                                                    fileobj.read(size)))
         else:
             out.trans_list_utc = []
 
@@ -571,18 +586,18 @@ class tzfile(_tzinfo):
 
         abbr = fileobj.read(charcnt).decode()
 
-        # Then there are tzh_leapcnt pairs of four-byte
+        # Then there are tzh_leapcnt pairs of
         # values, written in  standard byte  order;  the
-        # first  value  of  each pair gives the time (as
+        # first (TIME_SIZE-byte) value of each pair gives the time (as
         # returned by time(2)) at which a leap second
-        # occurs;  the  second  gives the  total  number of
+        # occurs; the second (4-byte) value gives the total number of
         # leap seconds to be applied after the given time.
         # The pairs of values are sorted in ascending order
         # by time.
 
         # Not used, for now (but seek for correct file position)
         if leapcnt:
-            fileobj.seek(leapcnt * 8, os.SEEK_CUR)
+            fileobj.seek(leapcnt * (time_size + 4), os.SEEK_CUR)
 
         # Then there are tzh_ttisstdcnt standard/wall
         # indicators, each stored as a one-byte value;
@@ -712,6 +727,8 @@ class tzfile(_tzinfo):
     def _find_last_transition(self, dt, in_utc=False):
         # If there's no list, there are no transitions to find
         if not self._trans_list:
+            if self._tz_string_info:
+                return -2
             return None
 
         timestamp = _datetime_to_timestamp(dt)
@@ -721,6 +738,8 @@ class tzfile(_tzinfo):
         trans_list = self._trans_list_utc if in_utc else self._trans_list
         idx = bisect.bisect_right(trans_list, timestamp)
 
+        if idx == len(trans_list) and self._tz_string_info:
+            return -2
         # We want to know when the previous transition was, so subtract off 1
         return idx - 1
 
@@ -735,11 +754,6 @@ class tzfile(_tzinfo):
 
         return self._trans_idx[idx]
 
-    def _find_ttinfo(self, dt):
-        idx = self._resolve_ambiguous_time(dt)
-
-        return self._get_ttinfo(idx)
-
     def fromutc(self, dt):
         """
         The ``tzfile`` implementation of :py:func:`datetime.tzinfo.fromutc`.
@@ -768,12 +782,18 @@ class tzfile(_tzinfo):
 
         # First treat UTC as wall time and get the transition we're in.
         idx = self._find_last_transition(dt, in_utc=True)
-        tti = self._get_ttinfo(idx)
 
-        dt_out = dt + datetime.timedelta(seconds=tti.offset)
+        # For a timestamp in indefinite future, use the TZ string if available.
+        if idx == -2:
+            tzinfo = self._tz_string_info
+            dt_out = tzinfo.fromutc(dt.replace(tzinfo=tzinfo))
+            fold = tzinfo._fold(dt_out)
+            dt_out = dt_out.replace(tzinfo=self)
+        else:
+            tti = self._get_ttinfo(idx)
+            dt_out = dt + datetime.timedelta(seconds=tti.offset)
+            fold = self.is_ambiguous(dt_out, idx=idx)
 
-        fold = self.is_ambiguous(dt_out, idx=idx)
-
         return enfold(dt_out, fold=int(fold))
 
     def is_ambiguous(self, dt, idx=None):
@@ -793,6 +813,10 @@ class tzfile(_tzinfo):
         if idx is None:
             idx = self._find_last_transition(dt)
 
+        # For a timestamp in indefinite future, use the TZ string if available.
+        if idx == -2:
+            return self._tz_string_info.is_ambiguous(dt)
+
         # Calculate the difference in offsets from current to previous
         timestamp = _datetime_to_timestamp(dt)
         tti = self._get_ttinfo(idx)
@@ -809,11 +833,11 @@ class tzfile(_tzinfo):
         idx = self._find_last_transition(dt)
 
         # If we have no transitions, return the index
-        _fold = self._fold(dt)
-        if idx is None or idx == 0:
+        if idx is None or idx <= 0:
             return idx
 
         # If it's ambiguous and we're in a fold, shift to a different index.
+        _fold = self._fold(dt)
         idx_offset = int(not _fold and self.is_ambiguous(dt, idx))
 
         return idx - idx_offset
@@ -822,19 +846,27 @@ class tzfile(_tzinfo):
         if dt is None:
             return None
 
+        idx = self._resolve_ambiguous_time(dt)
+        if idx == -2:
+            return self._tz_string_info.utcoffset(dt)
+
         if not self._ttinfo_std:
             return ZERO
 
-        return self._find_ttinfo(dt).delta
+        return self._get_ttinfo(idx).delta
 
     def dst(self, dt):
         if dt is None:
             return None
 
+        idx = self._resolve_ambiguous_time(dt)
+        if idx == -2:
+            return self._tz_string_info.dst(dt)
+
         if not self._ttinfo_dst:
             return ZERO
 
-        tti = self._find_ttinfo(dt)
+        tti = self._get_ttinfo(idx)
 
         if not tti.isdst:
             return ZERO
@@ -845,15 +877,21 @@ class tzfile(_tzinfo):
 
     @tzname_in_python2
     def tzname(self, dt):
-        if not self._ttinfo_std or dt is None:
+        if dt is None:
             return None
-        return self._find_ttinfo(dt).abbr
+        idx = self._resolve_ambiguous_time(dt)
+        if idx == -2:
+            return self._tz_string_info.tzname(dt)
+        if not self._ttinfo_std:
+            return None
+        return self._get_ttinfo(idx).abbr
 
     def __eq__(self, other):
         if not isinstance(other, tzfile):
             return NotImplemented
         return (self._trans_list == other._trans_list and
                 self._trans_idx == other._trans_idx and
+                self._tz_string_info == other._tz_string_info and
                 self._ttinfo_list == other._ttinfo_list)
 
     __hash__ = None
