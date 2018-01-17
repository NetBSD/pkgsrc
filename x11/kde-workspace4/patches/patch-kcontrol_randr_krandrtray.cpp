$NetBSD: patch-kcontrol_randr_krandrtray.cpp,v 1.1 2018/01/17 19:10:23 markd Exp $

gcc-7 fix

--- kcontrol/randr/krandrtray.cpp.orig	2015-08-12 07:03:15.000000000 +0000
+++ kcontrol/randr/krandrtray.cpp
@@ -361,7 +361,7 @@ void KRandRSystemTray::populateMenu(KMen
 					if (screen->activeCount() != 1)
 					{
 						action = outputMenu->addAction(i18n("Disable"));
-						if (output->crtc() == None)
+						if (output->crtc() == NULL)
 						{
 							QFont font = action->font();
 							font.setBold(true);
