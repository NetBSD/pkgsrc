# $NetBSD: Makefile,v 1.3 2002/12/10 16:02:38 taya Exp $

MOZILLA=	phoenix
MOZILLA_BIN=	phoenix-bin
MOZ_VER=	0.5
EXTRACT_SUFX=	.tar.bz2
DISTNAME=       mozilla-phoenix-${MOZ_VER}
MASTER_SITES=	${MASTER_SITE_LOCAL}

HOMEPAGE=	http://www.mozilla.org/projects/phoenix/
COMMENT=	A redesign of the Mozilla browser component

CONFIGURE_ENV+=	MOZ_PHOENIX=1	
MAKE_ENV+=	MOZ_PHOENIX=1	

CONFIGURE_ARGS+=	--disable-mailnews
CONFIGURE_ARGS+=	--disable-composer

.include	"../../www/mozilla/Makefile.common"
