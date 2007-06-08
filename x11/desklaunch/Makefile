# $NetBSD: Makefile,v 1.1.1.1 2007/06/08 21:57:33 sborrill Exp $
#

VERSION=	1.1.5
DISTNAME=	desklaunch_${VERSION}
PKGNAME=	desklaunch-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/?node=Download
COMMENT=	X utility for binding commands to pixmap icons

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/desklaunch ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/desklaunch.README

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
