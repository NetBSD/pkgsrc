# $NetBSD: Makefile,v 1.9 2000/09/13 20:21:53 jlam Exp $
# $FreeBSD Id: Makefile,v 1.9 1998/05/04 03:34:50 steve Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1nb1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config
WRKSRC=      		${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		# defined

XVCONFIGDIR=		${PREFIX}/lib/X11/xview

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

do-build:
	${SED}	-e "s,@X11BASE@,${X11BASE},g" \
		-e "s,@XVCONFIGDIR@,${XVCONFIGDIR},g" \
		< ${FILESDIR}/xvmkmf.in > ${WRKDIR}/xvmkmf

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/xvmkmf ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
