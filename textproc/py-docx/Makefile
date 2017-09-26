# $NetBSD: Makefile,v 1.2 2017/09/26 17:52:04 adam Exp $

DISTNAME=	python-docx-0.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-docx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-openxml/python-docx
COMMENT=	Python library for Microsoft Word (.docx) files
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml>=3.1.0:../../textproc/py-lxml
#BUILD_DEPENDS+=	${PYPKGPREFIX}-behave-[0-9]*:../../devel/py-behave
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
