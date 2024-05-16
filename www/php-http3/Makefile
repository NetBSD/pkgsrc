# $NetBSD: Makefile,v 1.38 2024/05/16 06:15:43 wiz Exp $

MODNAME=		http
PECL_VERSION=		3.3.0
CATEGORIES+=		www

PECL_DISTNAME=		pecl_http-${PECL_VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/pecl_http
COMMENT=		PHP extension for extended HTTP support
PKGREVISION=		6
LICENSE=		2-clause-bsd AND isc

CONFLICTS=		php-http-[0-9]*

PHP_VERSIONS_ACCEPTED=	74

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash

CHECK_PORTABILITY_SKIP+=	configure

CONFIG_SHELL=		${TOOLS_PATH.bash}
CONFIGURE_ARGS+=	--with-http
CONFIGURE_ARGS+=	--with-http-libcurl-dir=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--with-http-libevent-dir=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-http-libidn-dir=${BUILDLINK_PREFIX.libidn}
CONFIGURE_ARGS+=	--with-http-libicu-dir=${BUILDLINK_PREFIX.icu}
CONFIGURE_ARGS+=	--with-http-zlib-dir=${BUILDLINK_PREFIX.zlib}

BUILDLINK_API_DEPENDS.libevent=	libevent>=2

.include "../../devel/libevent/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/php-raphf2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/php-propro2/buildlink3.mk"
.include "../../converters/php-iconv/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
