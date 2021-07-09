$NetBSD: patch-src_corelib_global_qendian.h,v 1.1 2021/07/09 22:48:47 markd Exp $

Fix build with GCC 11: include <limits>
Fixes: QTBUG-90395
Change-Id: Iecc74d2000eb40dfbe7bfffd165b5dd3708b7a40
(cherry picked from commit 9c56d4da

--- src/corelib/global/qendian.h.orig	2020-10-27 08:02:11.000000000 +0000
+++ src/corelib/global/qendian.h
@@ -1,7 +1,7 @@
 /****************************************************************************
 **
-** Copyright (C) 2016 The Qt Company Ltd.
-** Copyright (C) 2016 Intel Corporation.
+** Copyright (C) 2021 The Qt Company Ltd.
+** Copyright (C) 2021 Intel Corporation.
 ** Contact: https://www.qt.io/licensing/
 **
 ** This file is part of the QtCore module of the Qt Toolkit.
@@ -44,6 +44,8 @@
 #include <QtCore/qfloat16.h>
 #include <QtCore/qglobal.h>
 
+#include <limits>
+
 // include stdlib.h and hope that it defines __GLIBC__ for glibc-based systems
 #include <stdlib.h>
 #include <string.h>
