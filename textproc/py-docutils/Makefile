# $NetBSD: Makefile,v 1.23 2008/04/12 22:43:13 jlam Exp $

DISTNAME=	docutils-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"

PLIST_VARS+=	std
.if !empty(PYVERSSUFFIX:M2*[12])
PLIST.std=	yes
.endif

.include "../../mk/bsd.pkg.mk"
