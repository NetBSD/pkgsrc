$NetBSD: patch-services_network_public_cpp_permissions__policy_origin__with__possible__wildcards.cc,v 1.1 2026/03/14 12:40:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/network/public/cpp/permissions_policy/origin_with_possible_wildcards.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ services/network/public/cpp/permissions_policy/origin_with_possible_wildcards.cc
@@ -94,7 +94,7 @@ bool OriginWithPossibleWildcards::DoesMa
 }
 
 bool operator==(const OriginWithPossibleWildcards& lhs,
-                const OriginWithPossibleWildcards& rhs) = default;
+                const OriginWithPossibleWildcards& rhs) { return lhs.csp_source == rhs.csp_source; }
 
 std::strong_ordering operator<=>(const OriginWithPossibleWildcards& lhs,
                                  const OriginWithPossibleWildcards& rhs) {
