# $NetBSD: Makefile,v 1.37 2026/01/07 08:49:06 wiz Exp $

MODNAME=		wddx
PKGREVISION=		15
CATEGORIES+=		textproc
COMMENT=		PHP extension for WDDX support

CONFLICTS=	php-wddx-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_DIR}

PHP_VERSIONS_ACCEPTED=	56
USE_PHP_EXT_PATCHES=	# defined

# appease some PHP build assumpsions
CFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2 \
		-I${BUILDLINK_DIR}/${PHP_INCDIR}/ext/date/lib

.include "../../lang/php/phpversion.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
