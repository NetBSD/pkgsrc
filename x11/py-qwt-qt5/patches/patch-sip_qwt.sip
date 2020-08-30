$NetBSD: patch-sip_qwt.sip,v 1.1 2020/08/30 08:21:15 tnn Exp $

sip: sip/qwt.sip:13: syntax error
Error: Unable to create the C++ code.
*** Error code 1

Hint:
  http://gnats.netbsd.org/54558

--- sip/qwt.sip.orig	2019-02-23 12:55:34.000000000 +0000
+++ sip/qwt.sip
@@ -10,7 +10,6 @@
 %Module(name=Qwt, keyword_arguments="Optional")
 
 %Import QtCore/QtCoremod.sip
-typedef unsigned long size_t;
 %Import QtGui/QtGuimod.sip
 
 %If (Qt_5_0_0 -)
