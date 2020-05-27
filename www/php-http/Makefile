# $NetBSD: Makefile,v 1.28 2020/05/27 19:37:44 wiz Exp $

MODNAME=		http
PECL_VERSION=		2.6.0
CATEGORIES+=		www

PECL_DISTNAME=		pecl_http-${PECL_VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/pecl_http
COMMENT=		PHP extension for extended HTTP support
PKGREVISION=		14
LICENSE=		2-clause-bsd AND isc

CONFLICTS=		php-http-[0-9]*

PHP_VERSIONS_ACCEPTED=	56

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-http
CONFIGURE_ARGS+=	--with-http-libcurl-dir=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-http-libevent-dir=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-http-libidn-dir=${BUILDLINK_PREFIX.libidn}
CONFIGURE_ARGS+=	--with-http-zlib-dir=${BUILDLINK_PREFIX.zlib}

SUBST_CLASSES+=		ini
SUBST_STAGE.ini=	pre-patch
SUBST_MESSAGE.ini=	Redirecting to temporary php.ini file
SUBST_FILES.ini=	config9.m4
SUBST_SED.ini=		-e 's,PHP_EXECUTABLE -m,PHP_EXECUTABLE -c ${WRKDIR} -m,'

post-extract:
	(${ECHO} "[PHP]" ;\
	${ECHO} "extension=propro.so" ; ${ECHO} "extension=raphf.so" \
	) > ${WRKDIR}/php.ini

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/php-raphf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/php-propro/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
