# $NetBSD: Makefile,v 1.11 2005/09/04 06:05:20 xtraeme Exp $
#

DISTNAME=	windowlab-1.32
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=	YES
USE_TOOLS+=	gmake pkg-config

EGDIR=		${PREFIX}/share/examples/windowlab
CONF_FILES=	${EGDIR}/windowlab.menurc ${PKG_SYSCONFDIR}/windowlab.menurc

INSTALLATION_DIRS=	share/examples/windowlab

post-extract:
	@${CHMOD} -R +x ${WRKSRC}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/windowlab.menurc ${EGDIR}

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
