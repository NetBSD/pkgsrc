# $NetBSD: Makefile,v 1.15 2003/05/06 16:10:15 salo Exp $
#

DISTNAME=	dillo-0.7.2
CATEGORIES=	www
MASTER_SITES=	http://dillo.auriga.wearlab.de/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.auriga.wearlab.de/
COMMENT=	Very small and fast graphical web-browser

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=		${PREFIX}/share/examples/dillo
CONF_FILES=	${EGDIR}/dillorc.default ${PKG_SYSCONFDIR}/dillorc

.include "../../mk/bsd.prefs.mk"

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
BUILD_DEFS+=		USE_INET6
CONFIGURE_ARGS+=	--enable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/dillo
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dillorc ${EGDIR}/dillorc.default

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
