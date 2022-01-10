# $NetBSD: Makefile,v 1.8 2022/01/10 07:59:56 wiz Exp $

DISTNAME=	landslide-1.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/landslide/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamzap/landslide
COMMENT=	Generate HTML5 slideshows from markdown, ReST, or textile
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.14:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.10.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	markdown pygments

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} landslide landslide-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} tests.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
