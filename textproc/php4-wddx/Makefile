# $NetBSD: Makefile,v 1.1.1.1 2001/10/16 06:28:06 jlam Exp $

.include "../php4/Makefile.module"

MODNAME=		wddx
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for WDDX support

DEPENDS+=		php-session>=${PHP_BASE_VERS}:../../www/php4-session
DEPENDS+=		php-xml>=${PHP_BASE_VERS}:../../www/php4-xml

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
