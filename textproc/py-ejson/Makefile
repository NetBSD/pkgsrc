# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:41 wiz Exp $

DISTNAME=	ejson-0.1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=e/ejson/}
DIST_SUBDIR=	${PKGBASE:S/${PYPKGPREFIX}/py/1}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/Yipit/ejson/
COMMENT=	Extensible JSON serializers and deserializers
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
