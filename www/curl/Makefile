# $NetBSD: Makefile,v 1.279 2024/05/16 06:15:40 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
