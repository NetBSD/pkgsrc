# $NetBSD: Makefile,v 1.22 2023/10/23 06:37:56 wiz Exp $

DISTNAME=	Genshi-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Genshi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://genshi.edgewall.org/
COMMENT=	Python toolkit for generation of output for the web
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

# "error: 'for' loop initial declarations are only allowed in C99 mode"
FORCE_C_STD=	c99

PYTHON_VERSIONED_DEPENDENCIES=	babel

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
