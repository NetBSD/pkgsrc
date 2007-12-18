# $NetBSD: Makefile,v 1.1.1.1 2007/12/18 15:42:32 taca Exp $
# FreeBSD: ports/www/plone/Makefile,v 1.25 2007/02/17 08:32:54 rafan Exp
#

DISTNAME=	Plone-${PLONE25_VERSION}
PKGNAME=	${PLONE_PKG_PREFIX}-${PLONE25_VERSION}
CATEGORIES=	www python
MASTER_SITES=	http://launchpad.net/plone/2.5/2.5.5/+download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plone.org/
COMMENT=	User friendly CMS written on top of ZOPE

PLONE_VERSION=			25
PYTHON_VERSIONS_ACCEPTED=	24
ZOPE_VERSION_ACCEPTED=		29

ZOPE_PRODUCT_NAME=	plone
ZOPE_PRODUCT_VER=	${PLONE25_VERSION}
ZOPE_BUILD_METHOD=	zope-force-build

PRIVILEGED_STAGES+=	clean
CONFLICTS=	zope25-BTreeFolder2-[0-9]* \
		zope25-CMF-[0-9]* \
		zope25-CMFPlone-[0-9]*

CHECK_INTERPRETER_SKIP=	${PLONE_BASE}/ATContentTypes/utilities/XXXreport \
	${PLONE_BASE}/MimetypesRegistry/tests/runtests.sh.example \
	${PLONE_BASE}/PortalTransforms/tests/runtests.sh.example \
	${PLONE_BASE}/validation/tests/runtests.sh.example

REPLACE_PYTHON_DIRS=	${WRKSRC}/kupu
REPLACE_PYTHON_PAT=	*.cgi *.py

pre-configure:
	${RM} -f ${WRKSRC}/CONTENTS.txt ${WRKSRC}/README.txt
	${RM} -fr ${WRKSRC}/CacheFu

.include "../../www/plone/ploneversion.mk"
.include "../../www/zope/replace.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
