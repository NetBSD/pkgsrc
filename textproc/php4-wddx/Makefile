# $NetBSD: Makefile,v 1.4 2001/12/03 08:31:04 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for WDDX support

DEPENDS+=		php-session>=${PHP_BASE_VERS}:../../devel/php4-session
DEPENDS+=		php-xml>=${PHP_BASE_VERS}:../../textproc/php4-xml

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
