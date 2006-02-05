# $NetBSD: Makefile,v 1.15 2006/02/05 23:11:15 joerg Exp $
#

DISTNAME=	windowlab-1.33
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
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

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
