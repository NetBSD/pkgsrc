# $NetBSD: Makefile,v 1.7 2004/02/15 21:01:57 kim Exp $
#

DISTNAME=		urlget-1.4
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Simple command-line tool to retrieve an HTTP URL

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=		svr4
.else
ALL_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all DEST=${PREFIX}

.include "../../mk/bsd.pkg.mk"
