# $NetBSD: Makefile,v 1.11 2004/07/30 18:28:25 recht Exp $

DISTNAME=	docutils-0.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	Python tool to generate documents

USE_BUILDLINK3= YES

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth 21 21pth
PYDISTUTILSPKG=	# defined

.include "../../lang/python/extension.mk"

.if !empty(PYVERSSUFFIX:M2*[12])
PLIST_SUBST+=	PYSTDMODULE=""
.else
PLIST_SUBST+=	PYSTDMODULE="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
