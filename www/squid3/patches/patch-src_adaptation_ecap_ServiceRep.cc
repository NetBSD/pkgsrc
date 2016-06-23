$NetBSD: patch-src_adaptation_ecap_ServiceRep.cc,v 1.1 2016/06/23 15:10:36 prlw1 Exp $

http://bugs.squid-cache.org/show_bug.cgi?id=4376

--- ./src/adaptation/ecap/ServiceRep.cc.orig	2016-05-08 12:46:35.000000000 +0000
+++ ./src/adaptation/ecap/ServiceRep.cc
@@ -234,7 +234,7 @@ bool Adaptation::Ecap::ServiceRep::probe
 
 bool Adaptation::Ecap::ServiceRep::up() const
 {
-    return theService;
+    return bool(theService);
 }
 
 bool Adaptation::Ecap::ServiceRep::wantsUrl(const String &urlPath) const
