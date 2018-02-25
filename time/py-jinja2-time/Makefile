# $NetBSD: Makefile,v 1.1 2018/02/25 00:52:29 minskim Exp $

DISTNAME=	jinja2-time-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jinja2-time/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hackebrot/jinja2-time
COMMENT=	Jinja2 extention for dates and times
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-arrow-[0-9]*:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
