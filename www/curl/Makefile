# $NetBSD: Makefile,v 1.276 2023/10/24 22:11:26 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
