# $NetBSD: Makefile,v 1.18 2004/07/06 19:52:01 jdolecek Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PKGREVISION=		# empty
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
