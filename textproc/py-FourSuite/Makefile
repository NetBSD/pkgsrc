# $NetBSD: Makefile,v 1.3 2002/09/21 23:46:58 jlam Exp $
#

DISTNAME=	4Suite-0.12.0a2
PKGNAME=	${PYPKGPREFIX}-FourSuite-0.12.0a2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://4suite.org/
COMMENT=	XML processing tools

CONFLICTS+=	${PYPKGPREFIX}-4Suite-*

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

#pyxml is needed at runtime to get pyexpat
#.include "../../textproc/py-xml-base/buildlink.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
