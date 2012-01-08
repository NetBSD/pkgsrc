$NetBSD: patch-build_rules.mk,v 1.1.1.1 2012/01/08 15:22:14 wiz Exp $

Install lua config files to example directory; installed to proper
location via pkgsrc config framework.

--- build/rules.mk.orig	2011-10-29 18:19:21.000000000 +0000
+++ build/rules.mk
@@ -220,9 +220,9 @@ lc_install:
 	done
 
 etc_install:
-	$(INSTALLDIR) $(DESTDIR)$(ETCDIR)
+	$(INSTALLDIR) $(DESTDIR)$(EXAMPLEDIR)
 	for i in $(ETC); do \
-		$(INSTALL) -m $(DATA_MODE) $$i $(DESTDIR)$(ETCDIR); \
+		$(INSTALL) -m $(DATA_MODE) $$i $(DESTDIR)$(EXAMPLEDIR); \
 	done
 
 # Dependencies
