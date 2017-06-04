# $NetBSD: Makefile,v 1.3 2017/06/04 19:23:08 adam Exp $

DISTNAME=	m2r-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m2r/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miyakogi/m2r
COMMENT=	Markdown to reStructuredText converter
LICENSE=	mit

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-mistune-[0-9]*:../../textproc/py-mistune

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv m2r m2r${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
