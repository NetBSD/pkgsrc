# $NetBSD: Makefile,v 1.3 2001/02/17 17:22:42 wiz Exp $
#

DISTNAME=		urlget-1.3
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		simple command-line tool to retrieve an HTTP URL

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
.if ${OPSYS} == "SunOS"
ALL_TARGET=		svr4
.else
ALL_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all DEST=${PREFIX}

.include "../../mk/bsd.pkg.mk"
