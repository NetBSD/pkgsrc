# $NetBSD: Makefile,v 1.1.1.1 2001/06/25 17:40:09 wiz Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		sablot
CATEGORIES+=		textproc
PHP_PKG_VERS=		# empty

MAINTAINER=		uithuis@dds.nl
COMMENT=		PHP4 XSLT functions using Sabloton and expat

DEPENDS+=		sablotron>=0.60:../../textproc/sablotron

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LOCALBASE}

.include "../../mk/bsd.pkg.mk"
