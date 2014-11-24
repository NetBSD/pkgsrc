# $NetBSD: Makefile,v 1.1 2014/11/24 14:06:12 wiz Exp $

DISTNAME=	uri-template-py-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-template-py/template/}
CATEGORIES=	textproc www python
MASTER_SITES=	https://github.com/uri-templates/uritemplate-py/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uri-templates/uritemplate-py/
COMMENT=	Python implementation of RFC6570, URI Template
LICENSE=	apache-2.0

EGG_NAME=	uritemplate-${PKGVERSION_NOREV}
WRKSRC=		${WRKDIR}/uritemplate-py-${DISTNAME}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
