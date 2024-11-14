# $NetBSD: Makefile,v 1.289 2024/11/14 22:22:03 wiz Exp $

PKGREVISION=	2
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
