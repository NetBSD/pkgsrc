# $NetBSD: Makefile,v 1.18 2014/01/01 11:52:37 wiz Exp $
#

DISTNAME=	modxslt-${DIST_VER}
PKGNAME=	${APACHE_PKG_PREFIX}-xslt2-${DIST_VER}
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.mod-xslt2.com/software/archive/${DIST_VER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mod-xslt2.com/
COMMENT=	Apache module able to apply stylesheets to XML data on the fly

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake bash:run
MAKE_JOBS_SAFE=	no

APACHE_MODULE=	yes
DIST_VER=	2004112100

PKG_APACHE_ACCEPTED=	apache2

CONFIGURE_ARGS+=	--enable-fallback-wraparound
CONFIGURE_ARGS+=	--enable-libxslt-hack
CONFIGURE_ARGS+=	--with-apxs=${PREFIX}/sbin/apxs \
			--with-xml2-config=${BUILDLINK_PREFIX.libxml2}/bin/xml2-config \
			--with-apr-config=${BUILDLINK_PREFIX.apr}/bin/apr-config \
			--with-apu-config=${BUILDLINK_PREFIX.apr}/bin/apu-config

REPLACE_BASH=	utils/modxslt-config.pre.in

INSTALLATION_DIRS+=	bin lib/httpd

.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
