# $NetBSD: Makefile,v 1.10 2002/11/26 15:07:31 jmmv Exp $
#

DISTNAME=	dillo-0.6.6
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dillo.cipsga.org.br/download/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.cipsga.org.br/
COMMENT=	Very small and fast graphical web-browser

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/dillo
CONF_FILES=	${EGDIR}/dillorc ${PKG_SYSCONFDIR}/dillorc

CFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/dillo

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
