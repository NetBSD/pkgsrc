# $NetBSD: Makefile,v 1.5 2003/05/02 11:56:32 wiz Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
PKGREVISION=	2
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_PREFIX.libxml2}

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
