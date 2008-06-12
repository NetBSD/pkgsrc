# $NetBSD: Makefile,v 1.14 2008/06/12 02:14:51 joerg Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
COMMENT=		PHP extension for WDDX support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-wddx-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}

USE_PHP_EXT_PATCHES=	# defined

# appease some PHP build assumpsions
CFLAGS+=	-I${BUILDLINK_DIR}/include/libxml2 \
		-I${BUILDLINK_DIR}/include/php/ext/date/lib


.include "../../lang/php/phpversion.mk"

# link against libxml2 on PHP5
.if ${PKG_PHP_VERSION} == 5
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_DIR}
.include "../../textproc/libxml2/buildlink3.mk"
.else
.include "../../textproc/expat/buildlink3.mk"
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
