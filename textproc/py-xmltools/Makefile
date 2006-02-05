# $NetBSD: Makefile,v 1.16 2006/02/05 23:11:07 joerg Exp $
#

DISTNAME=	xmltools-1.3.7
PKGNAME=	${PYPKGPREFIX}-xmltools-1.3.7
PKGREVISION=	7
CATEGORIES=	textproc python
MASTER_SITES=	http://www.logilab.org/ftp/pub/xmltools/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.logilab.org/xmltools/
COMMENT=	High level tools to help using XML in python

DEPENDS+=	${PYPKGPREFIX}-FourSuite>=0.12:../../textproc/py-FourSuite

PYDISTUTILSPKG=	yes

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
