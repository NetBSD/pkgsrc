# $NetBSD: Makefile,v 1.4 2003/07/21 17:27:48 martti Exp $

DISTNAME=	docutils-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	Python tool to generate documents

PYTHON_VERSIONS_ACCEPTED=	22 21
PYDISTUTILSPKG=	# defined

NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
