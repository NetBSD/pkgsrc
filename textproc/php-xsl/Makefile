# $NetBSD: Makefile,v 1.13 2020/11/05 09:09:14 ryoon Exp $

MODNAME=		xsl
CATEGORIES+=		textproc
COMMENT=		PHP extension for XSLT functions
PKGREVISION=		2

CONFLICTS=	php-xsl-[0-9]*

USE_PHP_EXT_PATCHES=	yes

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.libxslt}

.include "../../lang/php/ext.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
