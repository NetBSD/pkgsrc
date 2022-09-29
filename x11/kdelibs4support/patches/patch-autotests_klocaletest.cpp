$NetBSD: patch-autotests_klocaletest.cpp,v 1.1 2022/09/29 01:28:23 markd Exp $

__WORDSIZE may not be defined

--- autotests/klocaletest.cpp.orig	2022-08-07 13:22:01.000000000 +0000
+++ autotests/klocaletest.cpp
@@ -1202,7 +1202,7 @@ KLocaleTest::formatByteSize()
     QCOMPARE(locale.formatByteSize(5000000), QString("4.8 MiB"));
     QCOMPARE(locale.formatByteSize(50000000), QString("47.7 MiB"));
     QCOMPARE(locale.formatByteSize(500000000), QString("476.8 MiB"));
-#if (__WORDSIZE == 64) || defined (_LP64) || defined(__LP64__) || defined(__ILP64__)
+#if (defined(__WORDSIZE) && (__WORDSIZE == 64)) || defined (_LP64) || defined(__LP64__) || defined(__ILP64__)
     QCOMPARE(locale.formatByteSize(5000000000), QString("4.7 GiB"));
     QCOMPARE(locale.formatByteSize(50000000000), QString("46.6 GiB"));
     QCOMPARE(locale.formatByteSize(500000000000), QString("465.7 GiB"));
