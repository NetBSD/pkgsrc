# $NetBSD: Makefile,v 1.1.1.1 2002/10/14 06:40:53 martti Exp $

MODNAME=		curl
CATEGORIES+=		www
PKGREVISION=		# empty
COMMENT=		PHP4 extension for curl functions

USE_BUILDLINK2=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_DIR}

.include "../../www/curl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
