# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:12 wiz Exp $

DISTNAME=	jinja2-time-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
