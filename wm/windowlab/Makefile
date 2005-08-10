# $NetBSD: Makefile,v 1.10 2005/08/10 20:56:25 jlam Exp $
#

DISTNAME=	windowlab-1.12
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager

USE_PKGINSTALL=	YES
USE_TOOLS+=	gmake pkg-config

PKG_SYSCONFSUBDIR=	windowlab

EGDIR=		${PREFIX}/share/examples/windowlab
CONF_FILES=	${EGDIR}/menurc.default ${PKG_SYSCONFDIR}/menurc

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/menurc.sample ${EGDIR}/menurc.default

.include "../../fonts/Xft2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
