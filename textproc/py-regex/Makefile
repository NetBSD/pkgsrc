# $NetBSD: Makefile,v 1.10 2018/02/09 08:52:07 adam Exp $

DISTNAME=	regex-2018.02.08
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

.include "../../lang/python/pyversion.mk"

.if !empty(_PYTHON_VERSION:M3*)
TESTDIR=	${WRKSRC}/regex_3
.else
TESTDIR=	${WRKSRC}/regex_2
.endif

EGG_NAME=	${DISTNAME:S/.0/./g}

do-test:
	cd ${TESTDIR} && ${PYTHONBIN} test_regex.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
