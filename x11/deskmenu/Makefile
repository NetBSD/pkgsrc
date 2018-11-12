# $NetBSD: Makefile,v 1.33 2018/11/12 03:53:06 ryoon Exp $
#

VERSION=	1.4.2
DISTNAME=	deskmenu_${VERSION}
PKGNAME=	deskmenu-${VERSION}
PKGREVISION=	27
CATEGORIES=	x11
MASTER_SITES=	https://www.oroborus.org/debian/dists/sid/main/source/x11/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.oroborus.org/?node=Download
COMMENT=	X utility for providing root menus

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin share/examples/deskmenu

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths
SUBST_FILES.fix-paths=		src/deskmenu.c
SUBST_SED.fix-paths=		-e 's,"/etc,"${PKG_SYSCONFBASE},g'

BUILD_DEFS+=	PKG_SYSCONFBASE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/deskmenu ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example_rc \
		${DESTDIR}${PREFIX}/share/examples/deskmenu/deskmenurc

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
