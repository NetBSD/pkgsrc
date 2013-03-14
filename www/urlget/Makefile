# $NetBSD: Makefile,v 1.14 2013/03/14 17:04:27 kim Exp $
#

DISTNAME=		urlget-1.5
CATEGORIES=		www
MASTER_SITES=		http://oss.gw.com/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Simple command-line tool to retrieve an HTTP URL

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=		svr4
.else
BUILD_TARGET=		bsd
.endif
INSTALL_TARGET=		inst-all
INSTALL_MAKE_FLAGS+=	DEST=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
