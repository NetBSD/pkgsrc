# $NetBSD: Makefile,v 1.4 2005/12/10 02:51:35 taca Exp $
#

DISTNAME=		Zope-3.1.0
PKGNAME=		zope3-3.1.0
CATEGORIES=		www
MASTER_SITES=		http://www.zope.org/Products/Zope3/3.1.0final/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ykomatsu@akaumigame.org
HOMEPAGE=		http://dev.zope.org/Zope3/
COMMENT=		Zope 3 Application Server

DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.3nb1:../../textproc/py-xml

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${PREFIX}/share/zope3 \
			--force

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-6]*)
EXTRACT_USING=		gtar
.endif

BUILD_TARGET=		build

USE_PKGINSTALL=		yes
RCD_SCRIPTS=		zope3 zss3
ZOPE3_GROUP?=		zope3
ZOPE3_USER?=		zope3
PKG_GROUPS=		${ZOPE3_GROUP}
PKG_USERS=		${ZOPE3_USER}:${ZOPE3_GROUP}::Zope3\ user

PYTHON_VERSIONS_ACCEPTED=	24 23

MESSAGE_SUBST+=		ZOPE3_USER=${ZOPE3_USER} ZOPE3_GROUP=${ZOPE3_GROUP} \
			VARBASE=${VARBASE}

ZOPE3_DOCDIR=		${PREFIX}/share/doc/zope3

.include "../../lang/python/application.mk"

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -type f -print | ${XARGS} ${RM} -f

post-install:
	${LN} -s ${PREFIX}/share/zope3/bin/mkzeoinstance ${PREFIX}/bin
	${LN} -s ${PREFIX}/share/zope3/bin/mkzopeinstance ${PREFIX}/bin
	${LN} -s ${PREFIX}/share/zope3/bin/zopetest ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${ZOPE3_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Zope/LICENSES.txt ${ZOPE3_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Zope/ZopePublicLicense.txt ${ZOPE3_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Zope/doc/*.txt ${ZOPE3_DOCDIR}

.include "../../mk/bsd.pkg.mk"
