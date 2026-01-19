$NetBSD: patch-chrome_browser_ui_autofill_payments_desktop__payments__window__manager.h,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/autofill/payments/desktop_payments_window_manager.h
@@ -14,7 +14,7 @@
 #include "components/autofill/core/browser/payments/payments_window_manager.h"
 #include "content/public/browser/web_contents_observer.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/scoped_observation.h"
 #include "chrome/browser/ui/browser_list.h"
 #include "chrome/browser/ui/browser_list_observer.h"
@@ -39,7 +39,7 @@ class PaymentsWindowUserConsentDialogCon
 // WebContents of the original tab that the pop-up is created in. If there is a
 // pop-up currently present, `this` will observe the WebContents of that pop-up.
 class DesktopPaymentsWindowManager : public PaymentsWindowManager,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
                                      public BrowserListObserver,
 #endif  // BUILDFLAG(IS_LINUX)
                                      public content::WebContentsObserver {
@@ -59,7 +59,7 @@ class DesktopPaymentsWindowManager : pub
       content::NavigationHandle* navigation_handle) override;
   void WebContentsDestroyed() override;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // BrowserListObserver:
   void OnBrowserSetLastActive(Browser* browser) override;
 #endif  // BUILDFLAG(IS_LINUX)
@@ -130,7 +130,7 @@ class DesktopPaymentsWindowManager : pub
   // Used in tests to notify the test infrastructure that the pop-up has closed.
   base::RepeatingClosure popup_closed_closure_for_testing_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::ScopedObservation<BrowserList, BrowserListObserver> scoped_observation_{
       this};
 #endif  // BUILDFLAG(IS_LINUX)
