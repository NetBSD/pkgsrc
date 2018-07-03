# $NetBSD: Makefile,v 1.41 2018/07/03 09:50:21 adam Exp $

DISTNAME=	pytz-2018.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytz/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://pythonhosted.org/pytz/
COMMENT=	World timezone definitions, modern and historical
LICENSE=	mit

USE_LANGUAGES=	# none

REPLACE_PYTHON=	pytz/tzfile.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
