# $NetBSD: Makefile,v 1.19 2022/11/14 19:29:38 adam Exp $

DISTNAME=	twill-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/twill/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twill-tools/twill
COMMENT=	Simple scripting language for web browsing
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml>=4.9:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-requests>=2.27:../../devel/py-requests

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in twill twill-fork
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
