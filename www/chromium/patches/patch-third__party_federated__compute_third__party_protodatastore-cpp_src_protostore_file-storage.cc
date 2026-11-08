$NetBSD: patch-third__party_federated__compute_third__party_protodatastore-cpp_src_protostore_file-storage.cc,v 1.9 2026/11/08 15:39:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/federated_compute/third_party/protodatastore-cpp/src/protostore/file-storage.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ third_party/federated_compute/third_party/protodatastore-cpp/src/protostore/file-storage.cc
@@ -130,7 +130,7 @@ absl::Status IOError(absl::string_view c
     case ENETUNREACH:   // Network unreachable
     case ENOLCK:        // No locks available
     case ENOLINK:       // Link has been severed
-#if !(defined(__APPLE__) || defined(__FreeBSD__) || defined(_WIN32))
+#if !(defined(__APPLE__) || defined(__FreeBSD__) || defined(_WIN32) || defined(__OpenBSD__) || defined(__NetBSD__))
     case ENONET:  // Machine is not on the network
 #endif
       return absl::UnavailableError(message);
