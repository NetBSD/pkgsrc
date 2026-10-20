# $NetBSD: Makefile,v 1.39 2026/10/20 10:15:50 adam Exp $

DISTNAME=	feedparser-6.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/feedparser/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/kurtmckee/feedparser
COMMENT=	Parse RSS and Atom feeds in Python
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-feedparser-sgmllib>=2:../../textproc/py-feedparser-sgmllib

USE_LANGUAGES=	# none

post-extract:
	cd ${WRKSRC}/tests/illformed && \
	${RM} -f chardet/big5.xml undeclared_namespace.xml

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/runtests.py

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
