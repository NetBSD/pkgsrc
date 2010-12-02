# $NetBSD: Makefile,v 1.31 2010/12/02 15:00:03 wiz Exp $

DISTNAME=	docutils-0.7
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
