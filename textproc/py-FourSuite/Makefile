# $NetBSD: Makefile,v 1.18 2011/06/14 10:57:37 obache Exp $
#

DISTNAME=	4Suite-0.12.0a3
PKGNAME=	${PYPKGPREFIX}-FourSuite-0.12.0a3
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	ftp://ftp.fourthought.com/pub/4Suite/old/4Suite/0.12.0/

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://4suite.org/
COMMENT=	XML processing tools

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	${PYPKGPREFIX}-4Suite-*

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED=	25 24

#pyxml is needed at runtime to get pyexpat
#.include "../../textproc/py-xml/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
