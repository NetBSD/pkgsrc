# $NetBSD: Makefile,v 1.13 2005/01/23 20:41:49 recht Exp $

DISTNAME=	docutils-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	Python tool to generate documents

USE_BUILDLINK3= YES

PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PYDISTUTILSPKG=	# defined

.include "../../lang/python/extension.mk"

.if !empty(PYVERSSUFFIX:M2*[12])
PLIST_SUBST+=	PYSTDMODULE=""
.else
PLIST_SUBST+=	PYSTDMODULE="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
