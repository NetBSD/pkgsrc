# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:23 wiz Exp $

DISTNAME=	mkdocs-bootstrap-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mkdocs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mkdocs/mkdocs-bootstrap/
COMMENT=	Bootstrap theme for MkDocs
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	mkdocs-bootstrap
GITHUB_TAG=	${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
