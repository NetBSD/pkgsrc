# $NetBSD: Makefile,v 1.1.1.1 2002/02/11 09:33:42 manu Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		domxml
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for DOM support

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-dom=shared,${BUILDLINK_DIR}

DEPENDS+=		libxml2>=2.2.7:../../textproc/libxml2

.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
