# $NetBSD: Makefile,v 1.13 2003/04/11 20:26:30 jmmv Exp $
#

DISTNAME=	dillo-0.7.1.2
WRKSRC=		${WRKDIR}/dillo-0.7.1
CATEGORIES=	www
MASTER_SITES=	http://dillo.auriga.wearlab.de/download/

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://dillo.auriga.wearlab.de/
COMMENT=	Very small and fast graphical web-browser

USE_BUILDLINK2=	yes
USE_PKGINSTALL=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/dillo
CONF_FILES=	${EGDIR}/dillorc ${PKG_SYSCONFDIR}/dillorc

CFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=            USE_INET6
.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=        --enable-ipv6
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dillo
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/dillo

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
