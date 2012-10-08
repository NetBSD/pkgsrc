# $NetBSD: Makefile,v 1.5 2012/10/08 13:04:29 asau Exp $
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/saytime

post-install:
	cd ${WRKSRC}/times && pax -rw * ${DESTDIR}${PREFIX}/share/saytime/

.include "../../mk/bsd.pkg.mk"
