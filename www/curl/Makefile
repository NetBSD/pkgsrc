# $NetBSD: Makefile,v 1.309.2.1 2026/10/21 00:39:16 maya Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath+=	curl-config.in
SUBST_SED.rpath+=	-e 's!-L@libdir@!${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@!'
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to curl-config.

SUPERSEDES+=		wcurl-[0-9]*

.include "options.mk"

# 8.23.0
# TESTDONE: 2138 tests were considered during 672 seconds.
# TESTDONE: 1668 tests out of 1668 reported OK: 100%

.include "../../mk/bsd.pkg.mk"
