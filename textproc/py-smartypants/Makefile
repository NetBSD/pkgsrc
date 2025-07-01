# $NetBSD: Makefile,v 1.5 2025/07/01 21:22:58 wiz Exp $

DISTNAME=	smartypants-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/smartypants/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leohemsted/smartypants.py
COMMENT=	Python with the SmartyPants
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils

USE_LANGUAGES=	# none

# as of 2.0.2
# 4 failed, 1 passed

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} smartypants smartypants-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
