# $NetBSD: Makefile,v 1.1.1.1 2004/02/29 17:46:52 xtraeme Exp $

MOZILLA=	firefox-gtk2
MOZILLA_BIN=	firefox-bin
MOZ_VER=	0.8
EXTRACT_SUFX=	.tar.bz2

DISTNAME=	firefox-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firefox/${MOZ_VER}/ \
		http://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/ \
		ftp://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser built on gtk2

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

.include "../../www/mozilla/Makefile.common"
