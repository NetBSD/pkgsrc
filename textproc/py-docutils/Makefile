# $NetBSD: Makefile,v 1.15 2005/09/22 01:54:35 minskim Exp $

DISTNAME=	docutils-0.3.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	Python tool to generate documents


PYTHON_VERSIONS_ACCEPTED=	24 23 22 21
PYDISTUTILSPKG=	# defined

.include "../../lang/python/extension.mk"

.if !empty(PYVERSSUFFIX:M2*[12])
PLIST_SUBST+=	PYSTDMODULE=""
.else
PLIST_SUBST+=	PYSTDMODULE="@comment "
.endif

.include "../../mk/bsd.pkg.mk"
