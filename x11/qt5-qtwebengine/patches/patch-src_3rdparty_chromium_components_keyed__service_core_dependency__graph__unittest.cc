$NetBSD: patch-src_3rdparty_chromium_components_keyed__service_core_dependency__graph__unittest.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/keyed_service/core/dependency_graph_unittest.cc.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/keyed_service/core/dependency_graph_unittest.cc
@@ -9,7 +9,7 @@
 #include "components/keyed_service/core/dependency_graph.h"
 #include "components/keyed_service/core/dependency_node.h"
 #include "testing/gtest/include/gtest/gtest.h"
-#include "third_party/re2/src/re2/re2.h"
+#include <re2/re2.h>
 
 namespace {
 
