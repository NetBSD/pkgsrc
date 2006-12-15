# $NetBSD: Makefile,v 1.17 2006/12/15 20:33:03 joerg Exp $
#

DISTNAME=	windowlab-1.33
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake pkg-config

EGDIR=		${PREFIX}/share/examples/windowlab
CONF_FILES=	${EGDIR}/windowlab.menurc ${PKG_SYSCONFDIR}/windowlab.menurc

INSTALLATION_DIRS=	share/examples/windowlab

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/windowlab.menurc ${EGDIR}

.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
