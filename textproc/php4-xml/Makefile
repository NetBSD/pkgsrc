# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 06:26:10 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		xml
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for parsing XML

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
