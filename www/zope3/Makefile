# $NetBSD: Makefile,v 1.15 2007/02/28 15:49:55 wiz Exp $
#

DISTNAME=		Zope-3.3.1
PKGNAME=		zope3-3.3.1
CATEGORIES=		www
MASTER_SITES=		http://www.zope.org/Products/Zope3/3.3.1/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.zope.org/DevHome/Zope3/
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

BUILD_DEFS+=		VARBASE ZOPE3_GROUP ZOPE3_USER
BUILD_TARGET=		build

RCD_SCRIPTS=		zope3 zss3
PKG_GROUPS=		${ZOPE3_GROUP}
PKG_USERS=		${ZOPE3_USER}:${ZOPE3_GROUP}

FILES_SUBST+=		ZOPE3_USER=${ZOPE3_USER:Q}
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
	cd ${WRKSRC}/Zope && ${PAX} -r -w LICENSES.txt ZopePublicLicense.txt \
		${ZOPE3_DOCDIR}
	cd ${WRKSRC}/Zope/doc && ${PAX} -r -w *.txt ${ZOPE3_DOCDIR}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
