# $NetBSD: Makefile,v 1.14 2020/05/17 21:38:46 adam Exp $

DISTNAME=	Whoosh-2.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Whoosh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mchaput/whoosh/wiki/Home
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
