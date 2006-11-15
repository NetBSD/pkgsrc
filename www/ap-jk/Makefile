# $NetBSD: Makefile,v 1.39 2006/11/15 11:04:04 abs Exp $

DISTNAME=	tomcat-connectors-${JK_VERSION}-src
PKGNAME=	ap-jk-${JK_VERSION}

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}

.include "../../www/ap-jk/Makefile.common"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
