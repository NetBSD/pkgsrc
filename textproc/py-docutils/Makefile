# $NetBSD: Makefile,v 1.3 2003/07/17 22:54:45 grant Exp $

DISTNAME=	docutils-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://docutils.sf.net/
COMMENT=	python tool to generate documents

PYTHON_VERSIONS_ACCEPTED=	22 21
PYDISTUTILSPKG=	# defined

NO_CONFIGURE=	YES

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
