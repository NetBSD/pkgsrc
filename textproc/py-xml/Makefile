# $NetBSD: Makefile,v 1.36 2025/11/17 11:01:33 wiz Exp $

DISTNAME=	PyXML-0.8.4
PKGNAME=	${PYPKGPREFIX}-xml-0.8.4
PKGREVISION=	6
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyxml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://pyxml.sourceforge.net/
COMMENT=	Collection of libraries to process XML with Python

CONFLICTS+=	PyXML-[0-9]*

PYSETUPBUILDARGS+=		--with-libexpat=${BUILDLINK_DIR}
PYSETUPBUILDARGS+=		--ldflags="${EXPAT_LDFLAGS}"
EXPAT_LDFLAGS=			${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.expat}/lib

PYTHON_VERSIONS_ACCEPTED=	27 # dead upstream, no plans of porting

PYXML_SCRIPTS=	scripts/xmlproc_parse \
		scripts/xmlproc_val

REPLACE_PYTHON+=	xml/dom/ext/c14n.py
REPLACE_PYTHON+=	xml/dom/html/GenerateHtml.py
REPLACE_PYTHON+=	${PYXML_SCRIPTS:S/$/${PYVERSSUFFIX}/g}

post-extract:
.for s in ${PYXML_SCRIPTS}
	${MV} ${WRKSRC}/${s} ${WRKSRC}/${s}${PYVERSSUFFIX}
.endfor

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
