# $NetBSD: Makefile,v 1.13 2012/10/08 13:04:20 asau Exp $
#

DISTNAME=		logtime-1.2
CATEGORIES=		sysutils time
MASTER_SITES=		# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

NO_CONFIGURE=		yes

MAKE_FLAGS+=		PREFIX=${DESTDIR}${PREFIX}

BUILD_TARGET=		all
INSTALL_TARGET=		install
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
