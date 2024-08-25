# $NetBSD: Makefile,v 1.283 2024/08/25 06:06:00 wiz Exp $

.include "Makefile.common"
PKGREVISION=		1

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
