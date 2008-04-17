# $NetBSD: Makefile,v 1.29 2008/04/17 08:43:07 abs Exp $

DISTNAME=	libxslt-1.1.22
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	ftp://xmlsoft.org/libxslt/
MASTER_SITES+=	${MASTER_SITE_GNOME:=sources/libxslt/1.1/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	Python wrapper for libxslt

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.8:../../textproc/py-libxml2

WRKSRC=		${WRKDIR}/${DISTNAME}/python
PYTHON_VERSIONS_ACCEPTED=	25 24 23
PYDISTUTILSPKG=	YES
PYBINMODULE=	YES
NO_CONFIGURE=	YES

MAKE_ENV+=		PYLIBXSLTVERSION=${PKGVERSION:Q}

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,@LIBICONVDIR@,${BUILDLINK_PREFIX.iconv},g" \
			-e "s,@LIBXML2DIR@,${BUILDLINK_PREFIX.libxml2},g" \
			-e "s,@LIBXSLTDIR@,${BUILDLINK_PREFIX.libxslt},g"

BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=${PKGVERSION}
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
