# $NetBSD: Makefile,v 1.20 2006/10/04 22:01:00 wiz Exp $
#

DISTNAME=	xmltools-1.3.7
PKGNAME=	${PYPKGPREFIX}-xmltools-1.3.7
PKGREVISION=	7
CATEGORIES=	textproc python
MASTER_SITES=	http://www.logilab.org/ftp/pub/xmltools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.logilab.org/projects/xmltools/
COMMENT=	High level tools to help using XML in python

DEPENDS+=	${PYPKGPREFIX}-FourSuite>=0.12:../../textproc/py-FourSuite

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED=	24 23 22

.include "../../textproc/py-xml/buildlink3.mk"
.include "../../x11/pygtk/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
