# $NetBSD: Makefile,v 1.4 2014/10/26 11:49:53 wiz Exp $

DISTNAME=	python-dateutil-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	time python
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-dateutil/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://labix.org/python-dateutil
COMMENT=	Extensions to the standard datetime module
LICENSE=	modified-bsd

EGG_NAME=	${DISTNAME:S/-/_/}

pre-build:
	chmod 644 ${WRKSRC}/python_dateutil.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
