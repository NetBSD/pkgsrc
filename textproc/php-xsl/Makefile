# $NetBSD: Makefile,v 1.25 2025/04/17 21:52:37 wiz Exp $

MODNAME=		xsl
PKGREVISION=		14
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions

CONFLICTS=	php-xsl-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
