# $NetBSD: Makefile,v 1.22 2025/06/30 19:43:07 adam Exp $

DISTNAME=	bottle-0.13.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bottle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bottlepy.org/docs/stable/
COMMENT=	Fast, simple and lightweight WSGI micro web-framework for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/bottle.py
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} bottle bottle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
