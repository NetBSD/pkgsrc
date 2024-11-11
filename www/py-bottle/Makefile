# $NetBSD: Makefile,v 1.19 2024/11/11 07:29:16 wiz Exp $

DISTNAME=	bottle-0.13.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bottle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bottlepy.org/docs/stable/
COMMENT=	Fast, simple and lightweight WSGI micro web-framework for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/bottle.py
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} bottle bottle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
