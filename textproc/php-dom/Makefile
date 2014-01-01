# $NetBSD: Makefile,v 1.6 2014/01/01 11:52:36 wiz Exp $

MODNAME=		dom
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP5 extension for DOM support

CONFLICTS=	php-dom-[0-9]*

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-libxml-dir=${BUILDLINK_PREFIX.libxml2}

.include "../../lang/php/ext.mk"
#.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
