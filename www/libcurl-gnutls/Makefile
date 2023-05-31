# $NetBSD: Makefile,v 1.1 2023/05/31 18:37:52 nikita Exp $

DISTNAME=	curl-8.1.1
PKGNAME=	${DISTNAME:S/curl/libcurl-gnutls/}
CATEGORIES=	www
MASTER_SITES=	https://curl.se/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://curl.se/
COMMENT=	Client that groks URLs (build against gnuTLS)
# not completely, but near enough
LICENSE=	mit

BUILD_DEFS+=	IPV6_READY

TEST_DEPENDS+=	${PYPKGPREFIX}-impacket-[0-9]*:../../net/py-impacket
TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-impacket

USE_TOOLS+=		nroff perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gnutls=${BUILDLINK_PREFIX.gnutls}
# Some systems use bundles instead of directories; this needs configuring
# because curl doesn't use default validation.
.if !empty(SSLCERTBUNDLE)
CONFIGURE_ARGS+=	--with-ca-bundle=${SSLCERTBUNDLE}
.else
CONFIGURE_ARGS+=	--with-ca-path=${SSLCERTS}
.endif
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--without-libpsl
PKGCONFIG_OVERRIDE=	libcurl.pc.in
TEST_TARGET=		check

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Adjust hard-coded python invocations
SUBST_FILES.python=	tests/data/test1451
SUBST_SED.python=	-e 's,python,${PYTHONBIN},g'

REPLACE_PERL+=		tests/*.pl tests/*/*.pl
REPLACE_PYTHON+=	tests/*.py

PYTHON_FOR_BUILD_ONLY=	test

INSTALLATION_DIRS+=	lib

do-install:
	cd ${WRKSRC} && \
		${PREFIX}/bin/patchelf \
		--set-soname 'libcurl-gnutls.so.4' \
		lib/.libs/libcurl.so.4.*
	${INSTALL} ${WRKSRC}/lib/.libs/libcurl.so.4.8.0 ${DESTDIR}${PREFIX}/lib/libcurl-gnutls.so.4.8.0
	cd ${DESTDIR}${PREFIX}/lib && \
		${LN} -s libcurl-gnutls.so.4.8.0 libcurl-gnutls.so && \
		${LN} -s libcurl-gnutls.so.4.8.0 libcurl-gnutls.so.4

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
