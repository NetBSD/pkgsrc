# $NetBSD: Makefile,v 1.7 2004/02/08 23:30:53 kim Exp $
#

DISTNAME=		logtime-1.2
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes

MAKE_PARAMS+=		PREFIX=${PREFIX}

ALL_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
