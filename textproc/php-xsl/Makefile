# $NetBSD: Makefile,v 1.22 2024/11/01 12:54:39 wiz Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions
PKGREVISION=		11

CONFLICTS=	php-xsl-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
