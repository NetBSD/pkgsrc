# $NetBSD: Makefile,v 1.8 2003/09/19 13:19:12 wiz Exp $

MODNAME=		wddx
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for WDDX support

USE_BUILDLINK2=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}=shared,${BUILDLINK_PREFIX.expat}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_PREFIX.expat}

.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
