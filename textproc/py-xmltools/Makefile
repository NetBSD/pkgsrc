# $NetBSD: Makefile,v 1.2 2003/05/02 11:56:32 wiz Exp $
#

DISTNAME=	xmltools-1.3.7
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-xmltools-1.3.7
CATEGORIES=	textproc
MASTER_SITES=	http://www.logilab.org/ftp/pub/xmltools/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.logilab.org/xmltools/
COMMENT=	High level tools to help using XML in python

PYDISTUTILSPKG=	yes
USE_BUILDLINK2=	YES

.include "../../textproc/pyxml/buildlink2.mk"
.include "../../textproc/py-FourSuite/buildlink2.mk"
.include "../../x11/pygtk/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
