# $NetBSD: Makefile,v 1.16 2005/12/10 15:59:28 darcy Exp $

DISTNAME=	docutils-0.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
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
