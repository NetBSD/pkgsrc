# $NetBSD: Makefile,v 1.2 2002/02/28 06:18:48 jlam Exp $

MODNAME=		domxml
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for DOM support

BUILDLINK_DEPENDS.libxml2=	libxml2>=2.2.7
USE_BUILDLINK_ONLY=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_DIR}

.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
