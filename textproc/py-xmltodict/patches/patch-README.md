$NetBSD: patch-README.md,v 1.1 2019/12/21 23:47:39 joerg Exp $

Drop non-ASCII input

--- README.md.orig	2019-12-21 21:31:20.863530649 +0000
+++ README.md
@@ -86,7 +86,7 @@ True
 >>> xmltodict.parse(GzipFile('discogs_artists.xml.gz'),
 ...     item_depth=2, item_callback=handle_artist)
 A Perfect Circle
-Fantômas
+Fantomas
 King Crimson
 Chris Potter
 ...
@@ -173,7 +173,7 @@ You just need to
 $ pip install xmltodict
 ```
 
-### RPM-based distro (Fedora, RHEL, …)
+### RPM-based distro (Fedora, RHEL)
 
 There is an [official Fedora package for xmltodict](https://apps.fedoraproject.org/packages/python-xmltodict).
 
@@ -189,7 +189,7 @@ There is an [official Arch Linux package
 $ sudo pacman -S python-xmltodict
 ```
 
-### Debian-based distro (Debian, Ubuntu, …)
+### Debian-based distro (Debian, Ubuntu)
 
 There is an [official Debian package for xmltodict](https://tracker.debian.org/pkg/python-xmltodict).
 
