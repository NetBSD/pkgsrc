# $NetBSD: Makefile,v 1.2 2004/10/31 21:07:14 jdolecek Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP extension for WDDX support

USE_BUILDLINK3=		YES

.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
