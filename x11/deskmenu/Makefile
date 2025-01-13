# $NetBSD: Makefile,v 1.51 2025/01/13 16:46:27 ktnb Exp $
#

VERSION=	1.4.5
DISTNAME=	deskmenu_${VERSION}
PKGNAME=	deskmenu-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/d/deskmenu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20191129172107/https://www.oroborus.org/
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
