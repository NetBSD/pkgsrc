# $NetBSD: Makefile,v 1.17 2009/03/05 18:51:32 joerg Exp $
#

DISTNAME=	PyXML-0.8.4
PKGNAME=	${PYPKGPREFIX}-xml-0.8.4
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://pyxml.sourceforge.net/
COMMENT=	Collection of libraries to process XML with Python

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	PyXML-[0-9]*

PYDISTUTILSPKG=	yes
BUILDLINK_API_DEPENDS.expat+=	expat>=1.95.6
PYSETUPBUILDARGS+=	--with-libexpat=${BUILDLINK_DIR}
PYSETUPBUILDARGS+=	--ldflags="${EXPAT_LDFLAGS}"
EXPAT_LDFLAGS=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.expat}/lib
FIX_RPATH+=		EXPAT_LDFLAGS

PYXML_SCRIPTS=	scripts/xmlproc_parse \
		scripts/xmlproc_val

post-extract:
.for s in ${PYXML_SCRIPTS}
	${MV} ${WRKSRC}/${s} ${WRKSRC}/${s}${PYVERSSUFFIX}
.endfor

PYTHON_PATCH_SCRIPTS=	${PYXML_SCRIPTS:S/$/${PYVERSSUFFIX}/g}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
