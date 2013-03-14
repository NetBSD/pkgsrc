# $NetBSD: Makefile,v 1.14 2013/03/14 12:32:51 kim Exp $
#

DISTNAME=		logtime-1.2
PKGREVISION=		1
CATEGORIES=		sysutils time
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Prints date and time in a standard format

NO_CONFIGURE=		yes

BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

BUILD_TARGET=		all
INSTALL_TARGET=		install
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
