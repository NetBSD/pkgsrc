# $NetBSD: Makefile,v 1.4 2002/02/28 06:18:58 jlam Exp $

MODNAME=		xml
CATEGORIES+=		textproc
PKGREVISION=		# empty
COMMENT=		PHP4 extension for parsing XML

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
