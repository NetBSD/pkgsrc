# $NetBSD: Makefile,v 1.4 2006/02/05 23:11:06 joerg Exp $

MODNAME=		dom
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP5 extension for DOM support


CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
