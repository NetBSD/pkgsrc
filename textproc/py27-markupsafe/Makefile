# $NetBSD: Makefile,v 1.2 2022/06/30 11:18:54 nia Exp $

DISTNAME=	MarkupSafe-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MarkupSafe/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://www.palletsprojects.com/p/markupsafe/
COMMENT=	Implements a unicode subclass that supports HTML strings
LICENSE=	modified-bsd

PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
