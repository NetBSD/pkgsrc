# $NetBSD: Makefile,v 1.10 2005/04/11 21:48:02 tv Exp $
#

DISTNAME=		urlget-1.4
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Simple command-line tool to retrieve an HTTP URL


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		svr4
.else
BUILD_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all DEST=${PREFIX}

.include "../../mk/bsd.pkg.mk"
