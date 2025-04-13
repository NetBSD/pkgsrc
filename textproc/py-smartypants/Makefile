# $NetBSD: Makefile,v 1.4 2025/04/13 10:58:34 wiz Exp $

DISTNAME=	smartypants-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
# source tarball missing on pypi
#MASTER_SITES=	${MASTER_SITE_PYPI:=s/smartypants/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=leohemsted/}
GITHUB_PROJECT=	smartypants.py
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leohemsted/smartypants.py
COMMENT=	Python with the SmartyPants
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-docutils>=0:../../textproc/py-docutils

USE_LANGUAGES=	# none

# as of 2.0.1
# 4 failed, 1 passed

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} smartypants smartypants-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
