# $NetBSD: Makefile,v 1.3 2004/11/05 17:11:40 jdolecek Exp $

MODNAME=		curl
PKGREVISION=		# empty
CATEGORIES+=		www
COMMENT=		PHP extension for curl functions

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-curl=shared,${BUILDLINK_PREFIX.curl}

.include "../../lang/php/ext.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
