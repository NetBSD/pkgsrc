# $NetBSD: Makefile,v 1.60 2001/09/14 01:57:44 jlam Exp $

COMMENT=	API compatible clone of the OSF/Motif toolkit

CONFLICTS+=	openmotif-[0-9]*

USE_BUILDLINK_ONLY=	# defined

.include "Makefile.common"

CONFIGURE_ARGS+=	--disable-build-12
CONFIGURE_ARGS+=	--enable-build-20
CONFIGURE_ARGS+=	--disable-build-21
CONFIGURE_ARGS+=	--enable-default-20

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		LOCALBASE=${LOCALBASE}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		GREP=${GREP:Q}
FILES_SUBST+=		LN=${LN:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
