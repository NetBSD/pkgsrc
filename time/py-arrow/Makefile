# $NetBSD: Makefile,v 1.1 2014/06/14 14:12:57 rodent Exp $

DISTNAME=	arrow-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python time
MASTER_SITES=	https://pypi.python.org/packages/source/a/arrow/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://crsmithdev.com/arrow/
COMMENT=	Better dates and times for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES+=	dateutil

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
