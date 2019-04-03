# $NetBSD: Makefile,v 1.1 2019/04/03 14:49:27 adam Exp $

DISTNAME=	smartypants-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
#MASTER_SITES=	${MASTER_SITE_PYPI:=s/smartypants/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=leohemsted/}
GITHUB_PROJECT=	smartypants.py
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/leohemsted/smartypants.py
COMMENT=	Python with the SmartyPants
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} smartypants smartypants-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
