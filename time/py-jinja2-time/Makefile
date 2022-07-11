# $NetBSD: Makefile,v 1.4 2022/07/11 13:33:56 adam Exp $

DISTNAME=	jinja2-time-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jinja2-time/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hackebrot/jinja2-time
COMMENT=	Jinja2 extention for dates and times
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-arrow-[0-9]*:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-arrow

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
