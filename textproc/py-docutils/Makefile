# $NetBSD: Makefile,v 1.6 2003/09/18 02:28:08 jmc Exp $

DISTNAME=	docutils-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	Python tool to generate documents

USE_BUILDLINK2= YES

PYTHON_VERSIONS_ACCEPTED=	23 23pth 22 22pth 21 21pth
PYDISTUTILSPKG=	# defined

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
