# $NetBSD: Makefile,v 1.12 2016/03/05 11:29:36 jperkin Exp $

DISTNAME=	cppcms-1.0.4
PKGREVISION=	9
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcms/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://cppcms.com/
COMMENT=	High performance C++ web development framework
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

CMAKE_ARGS+=	-DPYTHON=${PYTHONBIN} -DDISABLE_GCRYPT=yes

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-std=c++11
.endif

CXXFLAGS.Cygwin+=	-std=gnu++11

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
