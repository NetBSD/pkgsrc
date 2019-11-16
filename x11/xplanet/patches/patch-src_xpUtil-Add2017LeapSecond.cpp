$NetBSD: patch-src_xpUtil-Add2017LeapSecond.cpp,v 1.1 2019/11/16 17:36:28 ng0 Exp $

Add 2017 leap second
Taken from upstream: https://sourceforge.net/p/xplanet/code/209/


--- src/xpUtil.cpp~
+++ src/xpUtil.cpp
@@ -434,6 +434,7 @@ deltaETpost1972(const double jd)
     if (jd >= toJulian(2009, 1, 1, 0, 0, 0)) delta_at++; // 34
     if (jd >= toJulian(2012, 7, 1, 0, 0, 0)) delta_at++; // 35
     if (jd >= toJulian(2015, 7, 1, 0, 0, 0)) delta_at++; // 36
+    if (jd >= toJulian(2017, 1, 1, 0, 0, 0)) delta_at++; // 37
 
     const double J2000 = toJulian(2000, 1, 1, 12, 0, 0);
     const double m = m0 + m1 * (jd - J2000) * 86400;
