# $NetBSD: Makefile,v 1.42 2014/01/01 11:52:36 wiz Exp $

DISTNAME=	libxslt-1.1.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	ftp://xmlsoft.org/libxslt/ \
		http://xmlsoft.org/sources/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	Python wrapper for libxslt
LICENSE=	mit # with no-advertising clause

DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-libxml2>=2.6.8:../../textproc/py-libxml2

WRKSRC=		${WRKDIR}/${DISTNAME}/python
PYDISTUTILSPKG=	yes
NO_CONFIGURE=	yes

MAKE_ENV+=		PYLIBXSLTVERSION=${PKGVERSION}

SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Fixing hardcoded paths.
SUBST_STAGE.setup=	pre-build
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,@LIBICONVDIR@,${BUILDLINK_PREFIX.iconv},g"
SUBST_SED.setup+=	-e "s,@LIBXML2DIR@,${BUILDLINK_PREFIX.libxml2},g"
SUBST_SED.setup+=	-e "s,@LIBXSLTDIR@,${BUILDLINK_PREFIX.libxslt},g"

BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=${PKGVERSION}
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../lang/python/extension.mk"
.include "../../converters/libiconv/buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
