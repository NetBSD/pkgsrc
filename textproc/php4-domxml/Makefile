# $NetBSD: Makefile,v 1.3 2002/09/10 16:06:50 wiz Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
PKGREVISION=		1
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK_ONLY=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_DIR}

.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
