# $NetBSD: Makefile,v 1.1.1.1 2007/06/16 13:06:33 sborrill Exp $
#

VERSION=	1.4.2
DISTNAME=	deskmenu_${VERSION}
PKGNAME=	deskmenu-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.oroborus.org/?node=Download
COMMENT=	X utility for providing root menus

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		src/deskmenu.c
SUBST_SED.fix-paths=		-e 's,"/etc,"${PKG_SYSCONFBASE},g'

BUILD_DEFS+=	PKG_SYSCONFBASE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/deskmenu ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/deskmenu
	${INSTALL_DATA} ${WRKSRC}/example_rc \
		${PREFIX}/share/examples/deskmenu/deskmenurc

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
