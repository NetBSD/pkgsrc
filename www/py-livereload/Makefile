# $NetBSD: Makefile,v 1.1 2016/01/21 20:26:50 jperkin Exp $

DISTNAME=	livereload-2.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl:S/py//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=lepture/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/lepture/python-livereload/
COMMENT=	Python web server for developers
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	python-livereload
GITHUB_TAG=	v${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
