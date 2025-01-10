# $NetBSD: Makefile,v 1.15 2025/01/10 08:56:11 adam Exp $

DISTNAME=	mistune-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mistune/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lepture/mistune
COMMENT=	Sane Markdown parser with useful plugins and renderers
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
