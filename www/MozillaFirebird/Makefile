# $NetBSD: Makefile,v 1.3 2003/11/27 00:10:55 taya Exp $

MOZILLA=	MozillaFirebird
MOZILLA_BIN=	MozillaFirebird-bin
MOZ_VER=	0.7
EXTRACT_SUFX=	.tar.gz
DISTNAME=	MozillaFirebird-source-${MOZ_VER}
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/firebird/releases/${MOZ_VER}/ \
		ftp://ftp.mozilla.org/pub/mozilla.org/firebird/${MOZ_VER}/

HOMEPAGE=	http://www.mozilla.org/projects/firebird/
COMMENT=	Lightweight gecko-based web browser

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer
CONFIGURE_ARGS+=	--enable-extensions=default,-irc

.include "../../www/mozilla/Makefile.common"
