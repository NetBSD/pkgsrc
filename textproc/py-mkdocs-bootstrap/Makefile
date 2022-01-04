# $NetBSD: Makefile,v 1.3 2022/01/04 20:55:00 wiz Exp $

DISTNAME=	mkdocs-bootstrap-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
PKGREVISION=	1
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
