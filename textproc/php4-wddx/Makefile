# $NetBSD: Makefile,v 1.11 2003/11/29 12:12:10 jdolecek Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for WDDX support

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
