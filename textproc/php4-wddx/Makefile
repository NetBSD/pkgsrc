# $NetBSD: Makefile,v 1.12 2004/04/25 00:52:39 xtraeme Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for WDDX support

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
