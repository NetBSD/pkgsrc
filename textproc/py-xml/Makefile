# $NetBSD: Makefile,v 1.6 2005/01/13 19:20:59 drochner Exp $
#

DISTNAME=	PyXML-0.8.4
PKGNAME=	${PYPKGPREFIX}-xml-0.8.4
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	Collection of libraries to process XML with Python

CONFLICTS+=	PyXML-*
USE_BUILDLINK3=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
BUILDLINK_DEPENDS.expat= expat>=1.95.6
PYSETUPBUILDARGS+=	--with-libexpat=${BUILDLINK_DIR}
PYSETUPBUILDARGS+=	--ldflags="${EXPAT_LDFLAGS}"
EXPAT_LDFLAGS=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.expat}/lib
FIX_RPATH+=		EXPAT_LDFLAGS

PYXML_SCRIPTS=	scripts/xmlproc_parse \
		scripts/xmlproc_val

post-extract:
.for s in ${PYXML_SCRIPTS}
	${MV} ${WRKSRC}/$s ${WRKSRC}/$s${PYVERSSUFFIX}
.endfor

PYTHON_PATCH_SCRIPTS=	${PYXML_SCRIPTS:S/$/${PYVERSSUFFIX}/g}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
