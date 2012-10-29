# $NetBSD: Makefile,v 1.18 2012/10/29 05:06:31 asau Exp $
#

DISTNAME=	keylaunch_1.3.3
PKGNAME=	keylaunch-1.3.3
CATEGORIES=	x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/?node=Download
COMMENT=	X utility for binding commands to a hot key

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	bin share/examples/keylaunch

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keylaunch ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/example_rc \
		${DESTDIR}${PREFIX}/share/examples/keylaunch/keylaunch.rc

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
