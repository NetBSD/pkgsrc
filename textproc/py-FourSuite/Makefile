# $NetBSD: Makefile,v 1.5 2003/07/17 22:54:44 grant Exp $
#

DISTNAME=	4Suite-0.12.0a3
PKGNAME=	${PYPKGPREFIX}-FourSuite-0.12.0a3
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://4suite.org/
COMMENT=	XML processing tools

CONFLICTS+=	${PYPKGPREFIX}-4Suite-*

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_BUILDLINK2=	yes

#pyxml is needed at runtime to get pyexpat
#.include "../../textproc/pyxml/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
