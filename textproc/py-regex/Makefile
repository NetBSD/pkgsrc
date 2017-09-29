# $NetBSD: Makefile,v 1.2 2017/09/29 21:59:48 wiz Exp $

DISTNAME=	regex-2017.07.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

.include "../../lang/python/pyversion.mk"

.if !empty(_PYTHON_VERSION:M3*)
TESTDIR=${WRKSRC}/Python3
.else
TESTDIR=${WRKSRC}/Python2
.endif

EGG_NAME=	regex-2017.7.28

# needs 'make install' first
do-test:
	cd ${TESTDIR} && ${PYTHONBIN} test_regex.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
