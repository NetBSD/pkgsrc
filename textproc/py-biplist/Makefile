# $NetBSD: Makefile,v 1.11 2022/08/24 09:25:56 wiz Exp $

DISTNAME=	biplist-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/biplist/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/wooster/biplist
COMMENT=	Library for reading/writing binary plists
LICENSE=	modified-bsd

TEST_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose

PYTHON_VERSIONED_DEPENDENCIES+=	coverage:test

USE_LANGUAGES=	# none

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
