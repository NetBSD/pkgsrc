# $NetBSD: Makefile,v 1.3 2001/08/06 16:05:57 drochner Exp $
#

DISTNAME=	PyXML-0.6.6
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	collection of libraries to process XML with Python

DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	expat-*:../../textproc/expat

USE_PYTHON=	yes
PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUPBUILDARGS+=	--with-libexpat=${LOCALBASE}
PYSETUPBUILDARGS+=	--ldflags=-Wl,-R${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
