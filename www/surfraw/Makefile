# $NetBSD: Makefile,v 1.12 2001/09/27 23:18:58 jlam Exp $
#

DISTNAME=	surfraw-1.0.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=surfraw/}

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/
COMMENT=	Shell Users' Revolutionary Front Rage Against the Web

CONFLICTS+=	surfaw-[0-9]*

GNU_CONFIGURE=	# defined

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL
INSTALL_FILE=	${WRKDIR}/INSTALL

DOCDIR=		${PREFIX}/share/doc/surfraw

FILES_SUBST=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/surfraw.conf ${PREFIX}/etc/surfraw.conf.dist
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
