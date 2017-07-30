# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:23 wiz Exp $

DISTNAME=	mkdocs-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs/
COMMENT=	Fast and simple static site generator for documentation
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	mkdocs
GITHUB_TAG=	${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-mkdocs-bootswatch-[0-9]*:../../textproc/py-mkdocs-bootswatch
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-livereload-[0-9]*:../../www/py-livereload
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
