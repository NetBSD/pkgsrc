# $NetBSD: Makefile,v 1.10 2023/03/29 09:34:14 wiz Exp $

DISTNAME=	aniso8601-9.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/aniso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/nielsenb/aniso8601
COMMENT=	Library for parsing ISO 8601 strings
LICENSE=	modified-bsd

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} == 207
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=2.0.0:../../devel/py-mock
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
