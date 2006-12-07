# $NetBSD: Makefile,v 1.1.1.1 2006/12/07 02:34:01 xtraeme Exp $
#

DISTNAME=	modxslt-${DIST_VER}
PKGNAME=	ap2-xslt2-${DIST_VER}
CATEGORIES=	www
MASTER_SITES=	http://www.mod-xslt2.com/software/archive/${DIST_VER}/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.mod-xslt2.com/
COMMENT=	Apache module able to apply stylesheets to XML data on the fly

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

APACHE_MODULE=	yes
DIST_VER=	2004112100

CONFIGURE_ARGS+=	--enable-fallback-wraparound
CONFIGURE_ARGS+=	--enable-libxslt-hack

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
