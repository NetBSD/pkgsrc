# $NetBSD: Makefile,v 1.18 2006/02/05 23:11:06 joerg Exp $

DISTNAME=	docutils-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	Python tool to generate documents


PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PYDISTUTILSPKG=	YES

.include "../../lang/python/extension.mk"

.if !empty(PYVERSSUFFIX:M2*[12])
PLIST_SUBST+=	PYSTDMODULE=""
.else
PLIST_SUBST+=	PYSTDMODULE="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
