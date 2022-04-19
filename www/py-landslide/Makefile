# $NetBSD: Makefile,v 1.9 2022/04/19 12:12:09 tnn Exp $

DISTNAME=	landslide-1.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/landslide/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamzap/landslide
COMMENT=	Generate HTML5 slideshows from markdown, ReST, or textile
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.14:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	jinja2 markdown pygments

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} landslide landslide-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
