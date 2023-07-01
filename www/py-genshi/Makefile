# $NetBSD: Makefile,v 1.20 2023/07/01 14:11:48 nia Exp $

DISTNAME=	Genshi-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=	c99

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	babel

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
