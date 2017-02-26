# $NetBSD: Makefile,v 1.2 2017/02/26 15:39:59 kamil Exp $

GITHUB_PROJECT=	landslide
DISTNAME=	landslide-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=adamzap/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adamzap/landslide/
COMMENT=	Generate HTML5 slideshows from markdown, ReST, or textile
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-markdown-[0-9]*:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/landslide \
		${DESTDIR}${PREFIX}/bin/landslide-${PYVERSSUFFIX}


.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
