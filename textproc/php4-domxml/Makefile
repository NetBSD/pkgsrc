# $NetBSD: Makefile,v 1.8 2003/08/31 19:55:59 jdolecek Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}

.include "../../devel/zlib/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
