# $NetBSD: Makefile,v 1.40 2024/05/29 16:34:48 adam Exp $

DISTNAME=	cppcms-1.2.1
PKGREVISION=	5
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcms/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cppcms.com/
COMMENT=	High performance C++ web development framework
LICENSE=	mit

USE_LANGUAGES=	c gnu++11
USE_CMAKE=	yes

PYTHON_VERSIONS_ACCEPTED=	27

CMAKE_ARGS+=	-DPYTHON=${PYTHONBIN} -DDISABLE_GCRYPT=yes

LDFLAGS+=	${EXPORT_SYMBOLS_LDFLAGS}

TEST_TARGET=	test
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}:${WRKSRC}/booster

REPLACE_PYTHON=	bin/cppcms_tmpl_cc

pre-install:
	rm -f ${WRKSRC}/cppcms/string_key.h.orig

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
