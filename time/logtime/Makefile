# $NetBSD: Makefile,v 1.15 2019/12/01 05:18:56 kim Exp $
#

DISTNAME=		logtime-1.2
PKGREVISION=		1
CATEGORIES=		sysutils time
MASTER_SITES=		http://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Prints date and time in a standard format

NO_CONFIGURE=		yes

BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

BUILD_TARGET=		all
INSTALL_TARGET=		install
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
