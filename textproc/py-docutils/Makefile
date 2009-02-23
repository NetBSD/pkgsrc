# $NetBSD: Makefile,v 1.27 2009/02/23 11:33:44 wiz Exp $

DISTNAME=	docutils-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	25 24 23
PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"

PLIST_VARS+=	std
.if !empty(PYVERSSUFFIX:M2*[12])
PLIST.std=	yes
.endif

.include "../../mk/bsd.pkg.mk"
