# $NetBSD: Makefile,v 1.20 2003/10/11 13:40:19 grant Exp $
#

DISTNAME=	PyXML-0.8.3
PKGNAME=	${PYPKGPREFIX}-xml-0.8.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	Collection of libraries to process XML with Python

CONFLICTS+=	PyXML-*
USE_BUILDLINK2=	yes

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes
BUILDLINK_DEPENDS.expat= expat>=1.95.6
PYSETUPBUILDARGS+=	--with-libexpat=${BUILDLINK_DIR}
PYSETUPBUILDARGS+=	--ldflags="${EXPAT_LDFLAGS}"
EXPAT_LDFLAGS=		-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.expat}/lib
FIX_RPATH+=		EXPAT_LDFLAGS

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
