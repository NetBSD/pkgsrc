# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:23 tv Exp $
#

DISTNAME=	windowlab-1.12
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://www.nickgravgaard.com/windowlab/
EXTRACT_SUFX=	.tar

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nickgravgaard.com/windowlab/
COMMENT=	Small and simple window manager

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

PKG_SYSCONFSUBDIR=	windowlab

EGDIR=		${PREFIX}/share/examples/windowlab
CONF_FILES=	${EGDIR}/menurc.default ${PKG_SYSCONFDIR}/menurc

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/menurc.sample ${EGDIR}/menurc.default

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
