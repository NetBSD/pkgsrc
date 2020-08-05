# $NetBSD: Makefile,v 1.8 2020/08/05 06:46:02 adam Exp $

DISTNAME=	hyperlink-20.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hyperlink/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-hyper/hyperlink
COMMENT=	Featureful, correct URL for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/src && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
