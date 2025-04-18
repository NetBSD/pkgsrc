# $NetBSD: Makefile,v 1.7 2025/04/18 15:26:09 wiz Exp $

DISTNAME=	jmespath-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jmespath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jmespath/jmespath.py
COMMENT=	Query language for JSON
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	jp.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} jp.py jp-${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
