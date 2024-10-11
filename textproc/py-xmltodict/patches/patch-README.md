$NetBSD: patch-README.md,v 1.2 2024/10/11 10:54:34 adam Exp $

Drop non-ASCII characters.

--- README.md.orig	2024-10-08 17:41:22.000000000 +0000
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
@@ -215,7 +215,7 @@ For installing `xmltodict` using Anacond
 $ conda install -c conda-forge xmltodict
 ```
 
-### RPM-based distro (Fedora, RHEL, …)
+### RPM-based distro (Fedora, RHEL)
 
 There is an [official Fedora package for xmltodict](https://apps.fedoraproject.org/packages/python-xmltodict).
 
@@ -231,7 +231,7 @@ There is an [official Arch Linux package
 $ sudo pacman -S python-xmltodict
 ```
 
-### Debian-based distro (Debian, Ubuntu, …)
+### Debian-based distro (Debian, Ubuntu)
 
 There is an [official Debian package for xmltodict](https://tracker.debian.org/pkg/python-xmltodict).
 
