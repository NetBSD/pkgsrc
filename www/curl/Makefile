# $NetBSD: Makefile,v 1.305 2026/03/11 07:08:39 wiz Exp $

.include "Makefile.common"

CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath+=	curl-config.in
SUBST_SED.rpath+=	-e 's!-L@libdir@!${COMPILER_RPATH_FLAG}@libdir@ -L@libdir@!'
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Adding rpath to curl-config.

SUPERSEDES+=		wcurl-[0-9]*

.include "options.mk"

# as of 8.17.0
#TESTDONE: 1890 tests were considered during 498 seconds.
#TESTDONE: 1622 tests out of 1623 reported OK: 99%
#
#FAIL 1510: 'HTTP GET connection cache limit (CURLOPT_MAXCONNECTS)' HTTP, verbose logs, flaky

.include "../../mk/bsd.pkg.mk"
