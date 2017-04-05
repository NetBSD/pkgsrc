# $NetBSD: Makefile,v 1.10 2017/04/05 12:33:48 fhajny Exp $

MODNAME=		xsl
PKGREVISION=		1
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions

CONFLICTS=	php-xsl-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
