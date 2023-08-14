# $NetBSD: Makefile,v 1.8 2023/08/14 05:25:24 wiz Exp $

DISTNAME=	cssselect2-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cssselect2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Kozea/cssselect2
COMMENT=	CSS selectors for Python ElementTree
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-tinycss2-[0-9]*:../../textproc/py27-tinycss2
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py27-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
