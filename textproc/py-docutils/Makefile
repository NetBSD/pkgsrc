# $NetBSD: Makefile,v 1.30 2009/10/31 03:00:27 wiz Exp $

DISTNAME=	docutils-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"

PLIST_VARS+=	std
.if !empty(PYVERSSUFFIX:M2*[12])
PLIST.std=	yes
.endif

.include "../../mk/bsd.pkg.mk"
