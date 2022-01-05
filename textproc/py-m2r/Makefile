# $NetBSD: Makefile,v 1.16 2022/01/05 15:41:25 wiz Exp $

DISTNAME=	m2r-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m2r/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miyakogi/m2r
COMMENT=	Markdown to reStructuredText converter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-mistune-[0-9]*:../../textproc/py-mistune

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	pygments:test

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} m2r m2r-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
