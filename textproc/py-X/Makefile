# $NetBSD: Makefile,v 1.1.1.1 2007/01/03 14:51:07 adrianp Exp $
#

DISTNAME=	PyX-0.9
PKGNAME=	${PYPKGPREFIX}-X-0.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyx/}

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin

PYBINMODULE=	yes
PYDISTUTILSPKG=	yes

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pyx.sourceforge.net/
COMMENT=	Package for the creation of PostScript and PDF files

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
