# $NetBSD: Makefile,v 1.15 2021/12/08 16:06:45 adam Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions
PKGREVISION=		4

CONFLICTS=	php-xsl-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
