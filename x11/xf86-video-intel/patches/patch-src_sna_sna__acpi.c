$NetBSD: patch-src_sna_sna__acpi.c,v 1.1 2016/12/07 21:59:54 wiz Exp $

Upstream patches for xorg-server-1.19.

--- src/sna/sna_acpi.c.orig	2014-08-29 09:33:11.000000000 +0000
+++ src/sna/sna_acpi.c
@@ -92,7 +92,7 @@ void _sna_acpi_wakeup(struct sna *sna)
 		DBG(("%s: error [%d], detaching from acpid\n", __FUNCTION__, n));
 
 		/* XXX reattach later? */
-		RemoveGeneralSocket(sna->acpi.fd);
+		RemoveNotifyFd(sna->acpi.fd);
 		sna_acpi_fini(sna);
 		return;
 	}
@@ -136,6 +136,13 @@ void _sna_acpi_wakeup(struct sna *sna)
 	} while (n);
 }
 
+#if HAVE_NOTIFY_FD
+static void sna_acpi_notify(int fd, int read, void *data)
+{
+	_sna_acpi_wakeup(data);
+}
+#endif
+
 static int read_power_state(const char *path)
 {
 	DIR *dir;
@@ -200,7 +207,7 @@ void sna_acpi_init(struct sna *sna)
 
 	DBG(("%s: attaching to acpid\n", __FUNCTION__));
 
-	AddGeneralSocket(sna->acpi.fd);
+	SetNotifyFd(sna->acpi.fd, sna_acpi_notify, X_NOTIFY_READ, sna);
 	sna->acpi.remain = sizeof(sna->acpi.event) - 1;
 	sna->acpi.offset = 0;
 
