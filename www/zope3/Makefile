# $NetBSD: Makefile,v 1.18 2007/12/21 16:18:35 taca Exp $
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

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-python ${PYTHONBIN} \
			--prefix ${ZOPE3_DIR} \
			--force
REPLACE_PYTHON= \
	Dependencies/twisted-Zope-3.3.1/twisted/mail/test/pop3testserver.py \
	Dependencies/twisted-Zope-3.3.1/twisted/trial/test/scripttest.py \
	Dependencies/twisted-Zope-3.3.1/twisted/web/test/test_cgi.py \
	Dependencies/twisted-Zope-3.3.1/twisted/web/test/test_distrib.py \
	Dependencies/twisted-Zope-3.3.1/twisted/web2/test/test_cgi.py \
	Dependencies/zdaemon-Zope-3.3.1/zdaemon/zdctl.py \
	Dependencies/zdaemon-Zope-3.3.1/zdaemon/zdrun.py
CHECK_INTERPRETER_SKIP=	\
	share/zope3/lib/python/zope/app/server/zopeskel/bin/*.in \
	share/zope3/zopeskel/bin/*.in
CHECK_PERMS_SKIP=	share/zope3/zopeskel/bin/*.in

BUILD_DEFS+=		VARBASE
BUILD_TARGET=		build

RCD_SCRIPTS=		zope3 zss3
PKG_GROUPS=		${ZOPE3_GROUP}
PKG_USERS=		${ZOPE3_USER}:${ZOPE3_GROUP}

FILES_SUBST+=		ZOPE3_USER=${ZOPE3_USER:Q}
MESSAGE_SUBST+=		ZOPE3_USER=${ZOPE3_USER:Q} \
			ZOPE3_GROUP=${ZOPE3_GROUP:Q} \
			VARBASE=${VARBASE:Q}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-6]*)
EXTRACT_USING=		gtar
.endif

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

.include "Makefile.common"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
