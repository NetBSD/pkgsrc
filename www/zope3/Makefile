# $NetBSD: Makefile,v 1.8 2006/01/24 07:32:50 wiz Exp $
#

DISTNAME=		Zope-3.2.0
PKGNAME=		zope3-3.2.0
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://www.zope.org/Products/Zope3/3.2.0final/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ykomatsu@akaumigame.org
HOMEPAGE=		http://dev.zope.org/Zope3/
COMMENT=		Zope 3 Application Server

DEPENDS+=		${PYPKGPREFIX}-xml>=0.8.4:../../textproc/py-xml

.include "Makefile.common"
.include "../../mk/bsd.prefs.mk"

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force

.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-6]*)
EXTRACT_USING=		gtar
.endif

BUILD_TARGET=		build

RCD_SCRIPTS=		zope3 zss3
PKG_GROUPS=		${ZOPE3_GROUP}
PKG_USERS=		${ZOPE3_USER}:${ZOPE3_GROUP}::Zope3\ user

MESSAGE_SUBST+=		ZOPE3_USER=${ZOPE3_USER:Q} \
			ZOPE3_GROUP=${ZOPE3_GROUP:Q} \
			VARBASE=${VARBASE:Q}

pre-install:
	${FIND} ${WRKSRC} -name "*.orig" -type f -print | ${XARGS} ${RM} -f

post-install:
	${LN} -s ${ZOPE3_DIR}/bin/mkzeoinstance ${PREFIX}/bin
	${LN} -s ${ZOPE3_DIR}/bin/mkzopeinstance ${PREFIX}/bin
	${LN} -s ${ZOPE3_DIR}/bin/zopetest ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${ZOPE3_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Zope/LICENSES.txt ${ZOPE3_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Zope/ZopePublicLicense.txt ${ZOPE3_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/Zope/doc/*.txt ${ZOPE3_DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
