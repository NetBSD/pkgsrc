# $NetBSD: Makefile,v 1.7 2003/07/13 13:53:35 wiz Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
PKGREVISION=		3
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
