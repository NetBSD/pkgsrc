# $NetBSD: Makefile,v 1.2 2000/10/14 18:09:55 kim Exp $
#

DISTNAME=		urlget-1.3
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
.if ${OPSYS} == "SunOS"
ALL_TARGET=		svr4
.else
ALL_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all DEST=${PREFIX}

.include "../../mk/bsd.pkg.mk"
