# $NetBSD: Makefile,v 1.6 2004/06/19 17:37:37 xtraeme Exp $

MOZILLA=	firefox
MOZILLA_BIN=	firefox-bin
MOZCONFDIR=	.mozilla
MOZ_VER=	0.8
PKGREVISION=	3
EXTRACT_SUFX=	.tar.bz2
DISTNAME=	${MOZILLA}-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firefox/releases/${MOZ_VER}/ \
		http://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/ \
		ftp://public.planetmirror.com.au/pub/firefox/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firefox/
COMMENT=	Lightweight gecko-based web browser

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer
CONFIGURE_ARGS+=	--enable-extensions=default,-irc

BUILD_MATHML=	# defined

.include "../../www/mozilla/Makefile.common"
