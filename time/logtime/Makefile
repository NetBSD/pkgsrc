# $NetBSD: Makefile,v 1.8 2004/12/03 15:15:11 wiz Exp $
#

DISTNAME=		logtime-1.2
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes

MAKE_PARAMS+=		PREFIX=${PREFIX}

BUILD_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
