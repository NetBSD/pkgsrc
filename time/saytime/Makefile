# $NetBSD: Makefile,v 1.8 2022/11/20 18:26:21 is Exp $
#

DISTNAME=		saytime_27jan2015
PKGNAME=		saytime-20150127
CATEGORIES=		time audio
MASTER_SITES=		http://www.acme.com/software/saytime/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		https://www.acme.com/software/saytime/
COMMENT=		Talking clock

USE_TOOLS+=	pax

# Needs /dev/audio.
NOT_FOR_PLATFORM=	Interix-*-*

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
