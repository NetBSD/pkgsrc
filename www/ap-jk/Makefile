# $NetBSD: Makefile,v 1.41 2012/10/28 06:30:04 asau Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap13-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

INSTALLATION_DIRS+=	lib/httpd

.include "../../www/ap-jk/Makefile.common"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
