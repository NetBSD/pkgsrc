# $NetBSD: Makefile,v 1.5 2002/02/28 06:18:53 jlam Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for WDDX support

DEPENDS+=		php-session>=${PHP_BASE_VERS}:../../devel/php4-session
DEPENDS+=		php-xml>=${PHP_BASE_VERS}:../../textproc/php4-xml

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
