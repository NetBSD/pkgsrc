# $NetBSD: Makefile,v 1.4 2002/11/27 17:25:25 drochner Exp $
#

DISTNAME=	4Suite-0.12.0a3
PKGNAME=	${PYPKGPREFIX}-FourSuite-0.12.0a3
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/

MAINTAINER=	drochner@netbsd.org
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
