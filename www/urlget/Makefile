# $NetBSD: Makefile,v 1.4 2001/09/27 19:57:02 jlam Exp $
#

DISTNAME=		urlget-1.3
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		simple command-line tool to retrieve an HTTP URL

USE_BUILDLINK_ONLY=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=		svr4
.else
ALL_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all DEST=${PREFIX}

.include "../../mk/bsd.pkg.mk"
