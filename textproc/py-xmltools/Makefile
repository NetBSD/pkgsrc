# $NetBSD: Makefile,v 1.9 2004/01/23 16:48:54 recht Exp $
#

DISTNAME=	xmltools-1.3.7
PKGNAME=	${PYPKGPREFIX}-xmltools-1.3.7
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.logilab.org/ftp/pub/xmltools/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.logilab.org/xmltools/
COMMENT=	High level tools to help using XML in python

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	YES

.include "../../textproc/py-xml/buildlink2.mk"
.include "../../textproc/py-FourSuite/buildlink2.mk"
.include "../../x11/pygtk/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
