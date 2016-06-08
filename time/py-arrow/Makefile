# $NetBSD: Makefile,v 1.2 2016/06/08 17:43:43 wiz Exp $

DISTNAME=	arrow-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	${MASTER_SITE_PYPI:=a/arrow/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://crsmithdev.com/arrow/
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	dateutil

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
