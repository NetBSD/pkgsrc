# $NetBSD: Makefile,v 1.34 2022/01/04 20:54:55 wiz Exp $

DISTNAME=		feedparser-6.0.8
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc python
MASTER_SITES=		${MASTER_SITE_PYPI:=f/feedparser/}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/feedparser
COMMENT=		Parse RSS and Atom feeds in Python
LICENSE=		2-clause-bsd

USE_LANGUAGES=		# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=		${PYPKGPREFIX}-sgmllib3k-[0-9]*:../../textproc/py-sgmllib3k

post-extract:
	cd ${WRKSRC}/tests/illformed && \
	rm -f chardet/big5.xml undeclared_namespace.xml

TEST_ENV+=		PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
