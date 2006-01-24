# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:38 wiz Exp $
#

DISTNAME=	xmltools-1.3.7
PKGNAME=	${PYPKGPREFIX}-xmltools-1.3.7
PKGREVISION=	6
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
