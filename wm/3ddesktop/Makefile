# $NetBSD: Makefile,v 1.18 2006/05/15 22:48:10 joerg Exp $
#

DISTNAME=		3ddesktop-0.2.8
PKGREVISION=		3
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=desk3d/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://desk3d.sourceforge.net/
COMMENT=		3D Virtual Desktop Switcher

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++

EGDIR=			${PREFIX}/share/examples/3ddesktop
CONF_FILES=		${EGDIR}/3ddesktop.conf ${PKG_SYSCONFDIR}/3ddesktop.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/3ddesktop.conf ${EGDIR}

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
