# $NetBSD: Makefile,v 1.278 2023/12/07 07:50:54 wiz Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
