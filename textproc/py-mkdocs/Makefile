# $NetBSD: Makefile,v 1.3 2018/08/31 12:30:47 adam Exp $

DISTNAME=	mkdocs-1.0.3
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
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.3.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-tornado>=5.0:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} mkdocs mkdocs-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
