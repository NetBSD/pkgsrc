# $NetBSD: Makefile,v 1.2 2001/10/16 06:58:34 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sablot
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty

MAINTAINER=		uithuis@dds.nl
COMMENT=		PHP4 XSLT functions using Sablotron

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		PHP_ICONV=${BUILDLINK_DIR}
LIBS+=			-lm

.include "../../textproc/sablotron/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
