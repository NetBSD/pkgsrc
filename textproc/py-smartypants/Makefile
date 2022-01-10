# $NetBSD: Makefile,v 1.2 2022/01/10 18:54:33 wiz Exp $

DISTNAME=	smartypants-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
