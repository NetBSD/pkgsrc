# $NetBSD: Makefile,v 1.1.1.1 2003/09/25 13:50:35 xtraeme Exp $
#

DISTNAME=		3ddesktop-0.2.5
CATEGORIES=		wm
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=desk3d/}

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://desk3d.sourceforge.net/
COMMENT=		3D Virtual Desktop Switcher

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/3ddesktop
CONF_FILES=		${EGDIR}/3ddesktop.conf ${PKG_SYSCONFDIR}/3ddesktop.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/3ddesktop.conf ${EGDIR}

.include "../../graphics/imlib2/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
