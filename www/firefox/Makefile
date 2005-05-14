# $NetBSD: Makefile,v 1.15 2005/05/14 15:27:10 taya Exp $

MOZILLA=	firefox
EXTRACT_SUFX=	.tar.bz2

COMMENT=	Lightweight gecko-based web browser

MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

PKGCONFIG_OVERRIDE+=	build/unix/firefox-gtkmozembed.pc
PKGCONFIG_OVERRIDE+=	build/unix/firefox-js.pc
PKGCONFIG_OVERRIDE+=	build/unix/firefox-nspr.pc
PKGCONFIG_OVERRIDE+=	build/unix/firefox-nss.pc
PKGCONFIG_OVERRIDE+=	build/unix/firefox-plugin.pc
PKGCONFIG_OVERRIDE+=	build/unix/firefox-xpcom.pc
# Some .pc files are filled in by the build process, so we can't fix the
# rpaths until this has happened.
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../www/firefox/Makefile-firefox.common"
