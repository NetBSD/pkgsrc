$NetBSD: patch-src_log__rules.cpp,v 1.1 2023/01/16 01:15:44 dholland Exp $

Use standard functions.

--- src/log_rules.cpp~	2020-11-05 14:53:59.000000000 +0000
+++ src/log_rules.cpp
@@ -48,7 +48,7 @@ void log_rule3(const char *func, const c
       }
    }
 #else // not WIN32
-   where = rindex(func, ':');
+   where = strrchr(func, ':');
 #endif /* ifdef WIN32 */
 
    if (where == nullptr)
