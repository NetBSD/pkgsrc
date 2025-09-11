# $NetBSD: Makefile,v 1.38 2025/09/11 06:10:54 adam Exp $

DISTNAME=	feedparser-6.0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedparser/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/feedparser
COMMENT=	Parse RSS and Atom feeds in Python
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-sgmllib3k-[0-9]*:../../textproc/py-sgmllib3k

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC}/tests/illformed && \
	${RM} -f chardet/big5.xml undeclared_namespace.xml

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/runtests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
