# $NetBSD: Makefile,v 1.7 2017/09/28 16:21:21 adam Exp $

DISTNAME=	python-cjson-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cjson/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/AGProjects/python-cjson
COMMENT=	Fast JSON encoder/decoder for Python
LICENSE=	gnu-lgpl-v2

PYDISTUTILSPKG=	yes

PYTHON_VERSIONS_ACCEPTED=	27 # Uses old string API.

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} jsontest.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
