# $NetBSD: Makefile,v 1.5 2002/01/16 21:06:44 drochner Exp $
#

DISTNAME=	PyXML-0.6.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	collection of libraries to process XML with Python

DEPENDS+=	expat-[0-9]*:../../textproc/expat

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUPBUILDARGS+=	--with-libexpat=${LOCALBASE}
PYSETUPBUILDARGS+=	--ldflags=-Wl,-R${LOCALBASE}/lib

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
