$NetBSD: patch-sip_qmap__convert.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qmap_convert.sip.orig	2024-05-11 19:32:30.715677253 +0000
+++ sip/qmap_convert.sip
@@ -3,6 +3,7 @@
 %MappedType QMap<double,QString> /TypeHint="Dict[double,QString]", TypeHintValue="{}"/
 {
 %TypeHeaderCode
+#include <qmap.h>
 #include <qwt_compass.h>
 %End
 
