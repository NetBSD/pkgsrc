# $NetBSD: Makefile,v 1.27 2011/11/01 06:02:40 sbd Exp $
#

DISTNAME=		3ddesktop-0.2.9
PKGREVISION=		6
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=desk3d/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://desk3d.sourceforge.net/
COMMENT=		3D Virtual Desktop Switcher

PKG_DESTDIR_SUPPORT=	user-destdir

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
