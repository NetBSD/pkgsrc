# $NetBSD: Makefile,v 1.7 2008/07/27 16:41:34 joerg Exp $
#

DISTNAME=	modxslt-${DIST_VER}
PKGNAME=	${APACHE_PKG_PREFIX}-xslt2-${DIST_VER}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.mod-xslt2.com/software/archive/${DIST_VER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mod-xslt2.com/
COMMENT=	Apache module able to apply stylesheets to XML data on the fly

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake bash:run

APACHE_MODULE=	yes
DIST_VER=	2004112100

PKG_APACHE_ACCEPTED=	apache2

CONFIGURE_ARGS+=	--enable-fallback-wraparound
CONFIGURE_ARGS+=	--enable-libxslt-hack
CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs

REPLACE_BASH=	utils/modxslt-config.pre.in

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
