# $NetBSD: Makefile,v 1.19 2025/04/14 13:00:58 adam Exp $

DISTNAME=	Whoosh-2.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Whoosh/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/mchaput/whoosh/wiki/Home
COMMENT=	Fast, featureful full-text indexing and searching library implemented
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
