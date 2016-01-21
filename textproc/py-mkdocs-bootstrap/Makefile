# $NetBSD: Makefile,v 1.1 2016/01/21 20:32:27 jperkin Exp $

DISTNAME=	mkdocs-bootstrap-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mkdocs/mkdocs-bootstrap/
COMMENT=	Bootstrap theme for MkDocs
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	mkdocs-bootstrap
GITHUB_TAG=	${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
