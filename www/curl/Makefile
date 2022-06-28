# $NetBSD: Makefile,v 1.259 2022/06/28 11:37:03 wiz Exp $

DISTNAME=	curl-7.84.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://curl.se/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://curl.se/
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

BUILD_DEFS+=	IPV6_READY

TEST_DEPENDS+=	${PYPKGPREFIX}-impacket-[0-9]*:../../net/py-impacket

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-impacket

USE_TOOLS+=		nroff perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
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

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
