# $NetBSD: Makefile,v 1.70 2025/04/13 10:59:53 wiz Exp $

DISTNAME=	pytz-2025.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytz/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/pytz/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pytz/tzfile.py

do-test:
	cd ${WRKSRC}/pytz/tests && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
