$NetBSD: patch-include_wx_wxchar.h,v 1.1 2018/01/29 15:12:54 jperkin Exp $

Don't forward declare struct tm.

--- include/wx/wxchar.h.orig	2011-03-22 12:16:51.000000000 +0000
+++ include/wx/wxchar.h
@@ -1276,7 +1276,6 @@ WXDLLIMPEXP_BASE int      wxSystem(const
     #include <time.h>
 #endif
     /*silent gabby compilers*/
-    struct tm;
     WXDLLIMPEXP_BASE size_t wxStrftime(wxChar *s, size_t max,
                                   const wxChar *fmt, const struct tm *tm);
 #endif /* wxNEED_WX_TIME_H */
