# $NetBSD: Makefile,v 1.16 2023/12/21 02:53:53 zafer Exp $
#

DISTNAME=		logtime-1.2
PKGREVISION=		1
CATEGORIES=		sysutils time
MASTER_SITES=		https://software.kimmo.suominen.com/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Prints date and time in a standard format

NO_CONFIGURE=		yes

BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

BUILD_TARGET=		all
INSTALL_TARGET=		install
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
