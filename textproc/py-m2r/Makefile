# $NetBSD: Makefile,v 1.17 2022/12/12 08:19:43 adam Exp $

DISTNAME=	m2r-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/m2r/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/miyakogi/m2r
COMMENT=	Markdown to reStructuredText converter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-mistune-[0-9]*:../../textproc/py-mistune
TEST_DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} m2r m2r-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
