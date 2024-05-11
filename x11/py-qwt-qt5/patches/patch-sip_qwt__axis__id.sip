$NetBSD: patch-sip_qwt__axis__id.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_axis_id.sip.orig	2024-05-11 19:36:19.096356461 +0000
+++ sip/qwt_axis_id.sip
@@ -0,0 +1 @@
+typedef int QwtAxisId;
