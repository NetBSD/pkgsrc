# $NetBSD: Makefile,v 1.37 2020/03/20 11:58:31 nia Exp $
#

DISTNAME=		3ddesktop-0.2.9
PKGREVISION=		13
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=desk3d/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://desk3d.sourceforge.net/
COMMENT=		3D Virtual Desktop Switcher

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c c++

EGDIR=			${PREFIX}/share/examples/3ddesktop
CONF_FILES=		${EGDIR}/3ddesktop.conf ${PKG_SYSCONFDIR}/3ddesktop.conf
INSTALLATION_DIRS=	${EGDIR}

pre-install:
	${INSTALL_DATA} ${WRKSRC}/3ddesktop.conf ${DESTDIR}${EGDIR}

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
