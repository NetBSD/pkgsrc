# $NetBSD: Makefile,v 1.4 2003/03/28 21:14:37 wiz Exp $
#

DISTNAME=		logtime-1.0
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

DEPENDS+=		sh-utils-[0-9]*:../../sysutils/sh-utils

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GDATE=${LOCALBASE}/bin/gdate

ALL_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
