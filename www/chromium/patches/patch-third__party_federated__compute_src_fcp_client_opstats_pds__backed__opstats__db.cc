$NetBSD: patch-third__party_federated__compute_src_fcp_client_opstats_pds__backed__opstats__db.cc,v 1.1 2026/08/09 06:31:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/federated_compute/src/fcp/client/opstats/pds_backed_opstats_db.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ third_party/federated_compute/src/fcp/client/opstats/pds_backed_opstats_db.cc
@@ -17,6 +17,7 @@
 
 #include <fcntl.h>
 #include <sys/file.h>
+#include <sys/stat.h>
 
 #include <algorithm>
 #include <cstdint>
