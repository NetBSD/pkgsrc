# $NetBSD: Makefile,v 1.17 2024/11/11 07:29:01 wiz Exp $

DISTNAME=	Whoosh-2.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Whoosh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mchaput/whoosh/wiki/Home
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
