# $NetBSD: Makefile,v 1.15 2016/02/26 10:57:46 jperkin Exp $
#

DISTNAME=		urlget-1.5
CATEGORIES=		www
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Simple command-line tool to retrieve an HTTP URL

BUILD_TARGET.SunOS=	svr4
BUILD_TARGET.*=		bsd

INSTALL_TARGET=		inst-all
INSTALL_MAKE_FLAGS+=	DEST=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
