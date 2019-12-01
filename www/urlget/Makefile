# $NetBSD: Makefile,v 1.16 2019/12/01 05:18:57 kim Exp $
#

DISTNAME=		urlget-1.5
CATEGORIES=		www
MASTER_SITES=		http://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Simple command-line tool to retrieve an HTTP URL

BUILD_TARGET.SunOS=	svr4
BUILD_TARGET.*=		bsd

INSTALL_TARGET=		inst-all
INSTALL_MAKE_FLAGS+=	DEST=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
