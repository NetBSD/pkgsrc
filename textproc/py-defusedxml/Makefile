# $NetBSD: Makefile,v 1.10 2025/04/22 20:34:56 wiz Exp $

DISTNAME=	defusedxml-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/defusedxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tiran/defusedxml
COMMENT=	XML bomb protection for Python stdlib modules
LICENSE=	python-software-foundation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

# as of 0.7.1
# 23 failed, 68 passed, 2 warnings

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
