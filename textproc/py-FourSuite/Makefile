# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:06 joerg Exp $
#

DISTNAME=	4Suite-0.12.0a3
PKGNAME=	${PYPKGPREFIX}-FourSuite-0.12.0a3
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://4suite.org/
COMMENT=	XML processing tools

CONFLICTS+=	${PYPKGPREFIX}-4Suite-*

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

#pyxml is needed at runtime to get pyexpat
#.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
