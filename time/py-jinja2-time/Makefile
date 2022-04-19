# $NetBSD: Makefile,v 1.3 2022/04/19 12:06:47 tnn Exp $

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

PYTHON_VERSIONED_DEPENDENCIES=	jinja2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
