# $NetBSD: Makefile,v 1.22 2005/12/05 20:51:07 rillig Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
COMMENT=		PHP4 extension for DOM support


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-dom-xslt=${BUILDLINK_PREFIX.libxslt}
CONFIGURE_ARGS+=	--with-dom-exslt=${BUILDLINK_PREFIX.libxslt}

PHP_VERSION_REQD=	4
.include "../../lang/php/ext.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
