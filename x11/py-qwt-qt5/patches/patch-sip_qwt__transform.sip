$NetBSD: patch-sip_qwt__transform.sip,v 1.1 2020/08/30 08:21:15 tnn Exp $

https://github.com/GauiStori/PyQt-Qwt/commit/8f6e01a10f29417214ae2266f3e5c13443e989a0

--- sip/qwt_transform.sip.orig	2019-02-23 12:55:34.000000000 +0000
+++ sip/qwt_transform.sip
@@ -123,4 +123,6 @@ public:
 
     virtual QwtTransform *copy() const;
 
+private:
+    QwtPowerTransform& operator=(const QwtPowerTransform&);
 };
