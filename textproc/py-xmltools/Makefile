# $NetBSD: Makefile,v 1.18 2006/06/04 16:43:46 joerg Exp $
#

DISTNAME=	xmltools-1.3.7
PKGNAME=	${PYPKGPREFIX}-xmltools-1.3.7
PKGREVISION=	7
CATEGORIES=	textproc python
MASTER_SITES=	http://www.logilab.org/ftp/pub/xmltools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logilab.org/xmltools/
COMMENT=	High level tools to help using XML in python

DEPENDS+=	${PYPKGPREFIX}-FourSuite>=0.12:../../textproc/py-FourSuite

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
