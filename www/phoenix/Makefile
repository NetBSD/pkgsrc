# $NetBSD: Makefile,v 1.11 2003/05/02 11:56:45 wiz Exp $

MOZILLA=	phoenix
MOZILLA_BIN=	phoenix-bin
PKGREVISION=	6
MOZ_VER=	0.5
EXTRACT_SUFX=	.tar.bz2
DISTNAME=       mozilla-phoenix-${MOZ_VER}
MASTER_SITES=	${MASTER_SITE_LOCAL}

HOMEPAGE=	http://www.mozilla.org/projects/phoenix/
COMMENT=	Lightweight gecko-based web browser

CONFIGURE_ENV+=	MOZ_PHOENIX=1
MAKE_ENV+=	MOZ_PHOENIX=1

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer

.include	"../../www/mozilla/Makefile.common"
