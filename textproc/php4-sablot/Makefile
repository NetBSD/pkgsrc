# $NetBSD: Makefile,v 1.3 2001/12/03 08:31:04 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sablot
CATEGORIES+=		textproc
PKGREVISION=		# empty

MAINTAINER=		uithuis@dds.nl
COMMENT=		PHP4 XSLT functions using Sablotron

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-expat-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ENV+=		PHP_ICONV=${BUILDLINK_DIR}
LIBS+=			-lm

.include "../../textproc/sablotron/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
