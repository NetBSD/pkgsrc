# $NetBSD: Makefile,v 1.8 2004/06/19 17:37:37 xtraeme Exp $

MOZILLA=	firefox-gtk2
MOZILLA_BIN=	firefox-bin
MOZ_VER=	0.8
PKGREVISION=	3
EXTRACT_SUFX=	.tar.bz2

DISTNAME=	firefox-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		http://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/ \
		ftp://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser built with GTK2

DISTINFO_FILE=	${.CURDIR}/../../www/firefox/distinfo
PATCHDIR=	${.CURDIR}/../../www/firefox/patches

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer
CONFIGURE_ARGS+=	--enable-extensions=default,-irc

USE_GCC_SHLIB=		yes
BUILD_MATHML=		# defined
MOZILLA_USE_GTK2=	# defined
MOZILLA_USE_XFT=	YES

.include "../../www/mozilla/Makefile.common"
