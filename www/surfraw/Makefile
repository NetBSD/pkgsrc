# $NetBSD: Makefile,v 1.13 2001/11/06 10:58:04 jlam Exp $
#

DISTNAME=	surfraw-1.0.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/proff/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/
COMMENT=	Shell Users' Revolutionary Front Rage Against the Web

CONFLICTS+=	surfaw-[0-9]*

USE_BUILDLINK_ONLY=	YES
AUTOMAKE_OVERRIDE=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${SURFRAW_SYSCONFDIR}

# Override sysconfdir so that the installation puts the example config file
# in ${EGDIR}.
#
MAKE_FLAGS+=		sysconfdir=${EGDIR}

SURFRAW_SYSCONFDIR?=	${PREFIX}/etc
DOCDIR=			${PREFIX}/share/doc/surfraw
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

PLIST_SUBST+=           PKGBASE=${PKGBASE}

FILES_SUBST+=           PKGBASE=${PKGBASE}
FILES_SUBST+=           SURFRAW_SYSCONFDIR=${SURFRAW_SYSCONFDIR}
FILES_SUBST+=           CAT=${CAT:Q}
FILES_SUBST+=           CHMOD=${CHMOD:Q}
FILES_SUBST+=           CMP=${CMP:Q}
FILES_SUBST+=           CP=${CP:Q}
FILES_SUBST+=           ECHO=${ECHO:Q}
FILES_SUBST+=           MKDIR=${MKDIR:Q}
FILES_SUBST+=           RM=${RM:Q}
FILES_SUBST+=           RMDIR=${RMDIR:Q}
FILES_SUBST+=           TR=${TR:Q}
FILES_SUBST+=           TRUE=${TRUE:Q}
FILES_SUBST_SED=        ${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
