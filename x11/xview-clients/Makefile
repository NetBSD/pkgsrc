# $NetBSD: Makefile,v 1.17 2001/05/02 21:46:08 dmcmahill Exp $
# $FreeBSD Id: Makefile,v 1.11 1996/11/16 10:49:52 asami Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-clients-3.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jlam@netbsd.org
COMMENT=		OpenLook applications and man pages

DEPENDS+=		xview-lib>=3.2.1:../../x11/xview-lib
NOT_FOR_PLATFORM=       *-*-alpha       # it builds but everything segfaults...

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/clients ${DISTNAME}/images
WRKSRC=			${WRKDIR}/${DISTNAME}/clients
USE_IMAKE=		# defined

post-patch:
	@cd ${WRKSRC};					\
	for file in olwm/openwin-menu-programs; do	\
		${MV} -f $${file} $${file}.tmp;		\
		${SED}	-e "s,@PREFIX@,${PREFIX},g"	\
			-e "s,@X11BASE@,${X11BASE},g"	\
			< $${file}.tmp > $${file};	\
		${RM} -f $${file}.tmp;			\
	done

.include "../../mk/bsd.pkg.mk"
