$NetBSD: patch-src_ipcache.cc,v 1.1 2024/02/21 12:58:50 sborrill Exp $

https://github.com/squid-cache/squid/pull/1691

Since inception in 2017 commit fd9c47d, Dns::CachedIps::have() always
returned position zero after finding a matching IP address (at zero or
positive position). The bug affected two callers:

* markAsBad() always marked the first stored address (as bad);
* forgetMarking() always cleared the first stored address marking.

Buggy markings led to Squid sometimes not attempting to use a working
address (e.g., IPv4) while using a known problematic one (e.g., IPv6).

--- src/ipcache.cc.orig	2023-12-07 01:36:15.000000000 +0000
+++ src/ipcache.cc	2024-02-21 09:14:05.428281018 +0000
@@ -990,6 +990,7 @@
             debugs(14, 7, ip << " at " << pos << " in " << *this);
             return true;
         }
+        ++pos; // TODO: Replace with std::views::enumerate() after upgrading to C++23
     }
     // no such address; leave *position as is
     debugs(14, 7, " no " << ip << " in " << *this);
