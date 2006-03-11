# $NetBSD: Makefile,v 1.9 2006/03/11 11:12:34 kim Exp $
#

DISTNAME=		logtime-1.2
CATEGORIES=		sysutils time
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes

MAKE_FLAGS+=		PREFIX=${PREFIX}

BUILD_TARGET=		all
INSTALL_TARGET=		install

.include "../../mk/bsd.pkg.mk"
