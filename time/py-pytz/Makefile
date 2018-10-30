# $NetBSD: Makefile,v 1.43 2018/10/30 10:10:03 adam Exp $

DISTNAME=	pytz-2018.7
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
