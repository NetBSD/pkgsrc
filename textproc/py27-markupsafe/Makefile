# $NetBSD: Makefile,v 1.1 2022/04/19 11:06:43 tnn Exp $

DISTNAME=	MarkupSafe-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MarkupSafe/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://www.palletsprojects.com/p/markupsafe/
COMMENT=	Implements a unicode subclass that supports HTML strings
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
