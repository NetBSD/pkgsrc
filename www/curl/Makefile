# $NetBSD: Makefile,v 1.296 2025/04/19 07:58:31 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath+=	curl-config.in
SUBST_SED.rpath+=	-e 's!-L@libdir@!${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@!'
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to curl-config.

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
