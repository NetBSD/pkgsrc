# $NetBSD: Makefile,v 1.25 2006/06/04 16:26:55 joerg Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
COMMENT=		PHP4 extension for DOM support

PHP_VERSIONS_ACCEPTED=	4

CONFLICTS=	php-domxml-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-dom-xslt=${BUILDLINK_PREFIX.libxslt}
CONFIGURE_ARGS+=	--with-dom-exslt=${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
