# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:48 jlam Exp $
#

DISTNAME=		logtime-1.0
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

DEPENDS+=		sh-utils-[0-9]*:../../sysutils/sh-utils

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
NO_PATCH=		yes

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GDATE=${LOCALBASE}/bin/gdate

ALL_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
