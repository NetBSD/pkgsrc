# $NetBSD: Makefile,v 1.15 2003/01/30 10:50:59 drochner Exp $
#

DISTNAME=	PyXML-0.8.2
PKGNAME=	${PYPKGPREFIX}-xml-0.8.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	collection of libraries to process XML with Python

CONFLICTS+=	PyXML-*
USE_BUILDLINK2=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
BUILDLINK_DEPENDS.expat= expat>=1.95.6
PYSETUPBUILDARGS+=	--with-libexpat=${BUILDLINK_DIR}
PYSETUPBUILDARGS+=	--ldflags=-Wl,-R${BUILDLINK_PREFIX.expat}/lib

PYXML_SCRIPTS=	scripts/xmlproc_parse \
		scripts/xmlproc_val

post-extract:
.for s in ${PYXML_SCRIPTS}
	${MV} ${WRKSRC}/$s ${WRKSRC}/$s${PYVERSSUFFIX}
.endfor

PYTHON_PATCH_SCRIPTS=	${PYXML_SCRIPTS:S/$/${PYVERSSUFFIX}/g}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../textproc/expat/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
