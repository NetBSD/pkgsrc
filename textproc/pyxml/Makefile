# $NetBSD: Makefile,v 1.7 2002/02/05 21:58:09 drochner Exp $
#

DISTNAME=	PyXML-0.7
PKGNAME=	${PYPKGPREFIX}-xml-0.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	collection of libraries to process XML with Python

DEPENDS+=	expat-[0-9]*:../../textproc/expat
CONFLICTS+=	PyXML-*

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
PYSETUPBUILDARGS+=	--with-libexpat=${LOCALBASE}
PYSETUPBUILDARGS+=	--ldflags=-Wl,-R${LOCALBASE}/lib

PYXML_SCRIPTS=	scripts/xmlproc_parse \
		scripts/xmlproc_val

post-extract:
.for s in ${PYXML_SCRIPTS}
	${MV} ${WRKSRC}/$s ${WRKSRC}/$s${PYVERSSUFFIX}
.endfor

PYTHON_PATCH_SCRIPTS=	${PYXML_SCRIPTS:S/$/${PYVERSSUFFIX}/g}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/extension.buildlink.mk"
.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
