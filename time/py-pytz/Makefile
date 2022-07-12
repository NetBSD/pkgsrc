# $NetBSD: Makefile,v 1.55 2022/07/12 09:23:40 adam Exp $

DISTNAME=	pytz-2022.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytz/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/pytz/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pytz/tzfile.py

do-test:
	cd ${WRKSRC}/pytz/tests && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
