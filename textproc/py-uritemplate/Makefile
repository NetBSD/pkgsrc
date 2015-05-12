# $NetBSD: Makefile,v 1.3 2015/05/12 14:33:29 mef Exp $

DISTNAME=	uri-template-py-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-template-py/template/}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=uri-templates/}
GITHUB_PROJECT=	uritemplate-py
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uri-templates/uritemplate-py/
COMMENT=	Python implementation of RFC6570, URI Template
LICENSE=	apache-2.0

EGG_NAME=	uritemplate-${PKGVERSION_NOREV}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
