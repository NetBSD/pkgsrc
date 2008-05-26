# $NetBSD: Makefile,v 1.3 2008/05/26 02:13:24 joerg Exp $
#

DISTNAME=		saytime_11nov1995
PKGNAME=		saytime-19951111
CATEGORIES=		time audio
MASTER_SITES=		http://www.acme.com/software/saytime/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.acme.com/software/saytime/
COMMENT=		Talking clock

USE_TOOLS+=	pax

ONLY_FOR_PLATFORM=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

WRKSRC=			${WRKDIR}/saytime

.include "../../mk/bsd.prefs.mk"

pre-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.template
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|' \
		${WRKSRC}/Makefile.template > ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/saytime
	cd ${WRKSRC}/times && pax -rw * ${LOCALBASE}/share/saytime/

.include "../../mk/bsd.pkg.mk"
