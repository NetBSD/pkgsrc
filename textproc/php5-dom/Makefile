# $NetBSD: Makefile,v 1.1.1.1 2004/11/05 21:13:00 jdolecek Exp $

MODNAME=		dom
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP5 extension for DOM support

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

PHP_VERSION_REQD=	5
.include "../../lang/php/ext.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
