$NetBSD: patch-services_network_public_cpp_permissions__policy_origin__with__possible__wildcards.cc,v 1.2 2026/04/10 17:31:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/public/cpp/permissions_policy/origin_with_possible_wildcards.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ services/network/public/cpp/permissions_policy/origin_with_possible_wildcards.cc
@@ -94,7 +94,7 @@ bool OriginWithPossibleWildcards::DoesMa
 }
 
 bool operator==(const OriginWithPossibleWildcards& lhs,
-                const OriginWithPossibleWildcards& rhs) = default;
+                const OriginWithPossibleWildcards& rhs) { return lhs.csp_source == rhs.csp_source; }
 
 std::strong_ordering operator<=>(const OriginWithPossibleWildcards& lhs,
                                  const OriginWithPossibleWildcards& rhs) {
