# $NetBSD: Makefile,v 1.1.1.1 2005/07/07 21:23:21 is Exp $
#

DISTNAME=		saytime_11nov1995
EXTRACT_SUFX=    	.tar.gz
PKGNAME=		saytime-19951111
CATEGORIES=		time audio
MASTER_SITES=		http://www.acme.com/software/saytime/

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

MAINTAINER=		is@netbsd.org
HOMEPAGE=		http://www.acme.com/software/saytime/
COMMENT=		a talking clock

WRKSRC=			${WRKDIR}/saytime

.include "../../mk/bsd.prefs.mk"

pre-configure: 
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.template
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|' \
		${WRKSRC}/Makefile.template > ${WRKSRC}/Makefile 


post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/saytime
	cd ${WRKSRC}/times && ${PAX} -rw * ${LOCALBASE}/share/saytime/

.include "../../mk/bsd.pkg.mk"
