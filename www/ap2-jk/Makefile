# $NetBSD: Makefile,v 1.4 2007/06/30 16:09:08 joerg Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	${APACHE_PKG_PREFIX}-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../www/ap-jk/Makefile.common"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
