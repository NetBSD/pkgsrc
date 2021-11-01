# $NetBSD: Makefile,v 1.5 2021/11/01 21:05:56 wiz Exp $

DISTNAME=	mkdocs-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs
COMMENT=	Fast and simple static site generator for documentation
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=3.3:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.7.1:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-livereload>=2.5.1:../../www/py-livereload
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

PYTHON_VERSIONED_DEPENDENCIES+=	markdown

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} mkdocs mkdocs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
