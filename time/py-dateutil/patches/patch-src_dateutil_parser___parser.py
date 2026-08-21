$NetBSD: patch-src_dateutil_parser___parser.py,v 1.1 2026/08/21 12:17:32 wiz Exp $

Support Internet RFC 8536 TZif files
https://github.com/dateutil/dateutil/pull/1091

--- src/dateutil/parser/_parser.py.orig	2024-03-01 18:35:19.000000000 +0000
+++ src/dateutil/parser/_parser.py
@@ -1389,7 +1389,8 @@ class _tzparser(object):
 
     def parse(self, tzstr):
         res = self._result()
-        l = [x for x in re.split(r'([,:.]|[a-zA-Z]+|[0-9]+)',tzstr) if x]
+        token_re = r'([,:./+-]|[a-zA-Z]+|[0-9]+|<[a-zA-Z0-9+-]+>)'
+        l = [x for x in re.split(token_re, tzstr) if x]
         used_idxs = list()
         try:
 
@@ -1398,20 +1399,25 @@ class _tzparser(object):
             i = 0
             while i < len_l:
                 # BRST+3[BRDT[+2]]
+                abbr = ""
                 j = i
-                while j < len_l and not [x for x in l[j]
-                                         if x in "0123456789:,-+"]:
+                while j < len_l and (l[j][0] == '<'
+                                     or not [x for x in l[j]
+                                             if x in "0123456789:,-+"]):
+                    if l[j][0] == '<':
+                        abbr += l[j][1:-1]
+                    else:
+                        abbr += l[j]
+                    used_idxs.append(j)
                     j += 1
                 if j != i:
                     if not res.stdabbr:
                         offattr = "stdoffset"
-                        res.stdabbr = "".join(l[i:j])
+                        res.stdabbr = abbr
                     else:
                         offattr = "dstoffset"
-                        res.dstabbr = "".join(l[i:j])
+                        res.dstabbr = abbr
 
-                    for ii in range(j):
-                        used_idxs.append(ii)
                     i = j
                     if (i < len_l and (l[i] in ('+', '-') or l[i][0] in
                                        "0123456789")):
@@ -1505,7 +1511,7 @@ class _tzparser(object):
                      'TZ variable format.', tz.DeprecatedTzFormatWarning)
             elif (l.count(',') == 2 and l[i:].count('/') <= 2 and
                   not [y for x in l[i:] if x not in (',', '/', 'J', 'M',
-                                                     '.', '-', ':')
+                                                     '.', '-', '+', ':')
                        for y in x if y not in "0123456789"]):
                 for x in (res.start, res.end):
                     if l[i] == 'J':
@@ -1542,6 +1548,12 @@ class _tzparser(object):
                     if i < len_l and l[i] == '/':
                         used_idxs.append(i)
                         i += 1
+                        if l[i] in ('+', '-'):
+                            signal = (-1, 1)[l[i] == '+']
+                            used_idxs.append(i)
+                            i += 1
+                        else:
+                            signal = 1
                         # start time
                         len_li = len(l[i])
                         if len_li == 4:
@@ -1562,6 +1574,7 @@ class _tzparser(object):
                             x.time = (int(l[i][:2]) * 3600)
                         else:
                             return None
+                        x.time *= signal
                         used_idxs.append(i)
                         i += 1
 
