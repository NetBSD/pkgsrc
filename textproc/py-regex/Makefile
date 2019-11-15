# $NetBSD: Makefile,v 1.21 2019/11/15 14:31:02 adam Exp $

DISTNAME=	regex-2019.11.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/regex/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mrabarnett/mrab-regex
COMMENT=	Alternative regular expression module, to replace re
LICENSE=	python-software-foundation

EGG_NAME=	${DISTNAME:S/.0/./g}

do-test:
	${PYTHONBIN} -m regex.test_regex

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
