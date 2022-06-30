# $NetBSD: Makefile,v 1.32 2022/06/30 11:18:58 nia Exp $

DISTNAME=	cppcms-1.0.4
PKGREVISION=	28
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cppcms/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://cppcms.com/
COMMENT=	High performance C++ web development framework
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c gnu++11
USE_CMAKE=	yes

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
