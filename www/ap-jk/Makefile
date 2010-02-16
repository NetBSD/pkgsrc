# $NetBSD: Makefile,v 1.40 2010/02/16 14:52:13 joerg Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap13-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	lib/httpd

.include "../../www/ap-jk/Makefile.common"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
