$NetBSD: patch-components_search__engines_template__url__service.cc,v 1.25 2026/09/02 13:13:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/search_engines/template_url_service.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/search_engines/template_url_service.cc
@@ -3746,7 +3746,7 @@ bool TemplateURLService::MatchesDefaultS
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs, base::BindRepeating(&TemplateURLService::EnterpriseSearchChanged,
                                  base::Unretained(this)));
