# $NetBSD: Makefile,v 1.10 2002/08/29 16:11:22 drochner Exp $
#

DISTNAME=	PyXML-0.8
PKGNAME=	${PYPKGPREFIX}-xml-0.8
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	collection of libraries to process XML with Python

CONFLICTS+=	PyXML-*
USE_BUILDLINK_ONLY=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
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

.include "../../textproc/expat/buildlink.mk"
.include "../../lang/python/extension.buildlink.mk"
.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
