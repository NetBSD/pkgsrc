# $NetBSD: Makefile,v 1.7 2004/01/20 19:29:37 snj Exp $

PKGREVISION=	2
MOZILLA=	MozillaFirebird
MOZILLA_BIN=	MozillaFirebird-bin
MOZ_VER=	0.7
EXTRACT_SUFX=	.tar.gz
DISTNAME=	MozillaFirebird-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/firebird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firebird/${MOZ_VER}/ \
		http://public.planetmirror.com.au/pub/firebird/releases/${MOZ_VER}/ \
		ftp://public.planetmirror.com.au/pub/firebird/releases/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firebird/
COMMENT=	Lightweight gecko-based web browser

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer
CONFIGURE_ARGS+=	--enable-extensions=default,-irc

BUILD_MATHML=	# defined

.include "../../www/mozilla/Makefile.common"
