# $NetBSD: Makefile,v 1.235 2020/11/15 20:27:39 leot Exp $

DISTNAME=	curl-7.73.0
CATEGORIES=	www
MASTER_SITES=	https://curl.haxx.se/download/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://curl.haxx.se/
COMMENT=	Client that groks URLs
# not completely, but near enough
LICENSE=	mit

BUILD_DEFS+=	IPV6_READY

TEST_DEPENDS+=	${PYPKGPREFIX}-impacket-[0-9]*:../../net/py-impacket

USE_TOOLS+=		nroff perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-ca-path=${SSLCERTS}
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
