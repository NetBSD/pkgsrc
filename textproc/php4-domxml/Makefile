# $NetBSD: Makefile,v 1.16 2004/04/25 00:52:39 xtraeme Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PKGREVISION=		3
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-dom-xslt=${BUILDLINK_PREFIX.libxslt}
CONFIGURE_ARGS+=	--with-dom-exslt=${BUILDLINK_PREFIX.libxslt}

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
