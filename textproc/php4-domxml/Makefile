# $NetBSD: Makefile,v 1.12 2003/11/29 11:58:05 jdolecek Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PKGREVISION=		1
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--with-dom-xslt=${BUILDLINK_PREFIX.libxslt}
CONFIGURE_ARGS+=	--with-dom-exslt=${BUILDLINK_PREFIX.libxslt}

.include "../../devel/zlib/buildlink2.mk"
# remove the BUILDLINK_DEPENDS on next libxml2 package buildlink update
BUILDLINK_DEPENDS.libxml2=	libxml2>=2.5.10nb1
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
