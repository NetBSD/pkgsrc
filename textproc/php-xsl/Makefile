# $NetBSD: Makefile,v 1.10.6.1 2017/11/01 19:19:23 spz Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions

CONFLICTS=	php-xsl-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
