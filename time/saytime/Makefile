# $NetBSD: Makefile,v 1.10 2023/07/07 08:35:34 nia Exp $
#

DISTNAME=		saytime_27jan2015
PKGNAME=		saytime-20150127
CATEGORIES=		time audio
MASTER_SITES=		https://www.acme.com/software/saytime/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		https://www.acme.com/software/saytime/
COMMENT=		Talking clock
LICENSE=		2-clause-bsd

USE_TOOLS+=	pax

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS" && !exists(/usr/include/sys/audioio.h)
PKG_SKIP_REASON+=	"Needs /dev/audio"
.endif

WRKSRC=			${WRKDIR}/saytime

pre-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.template
	${SED} -e 's|@LOCALBASE@|${LOCALBASE}|' \
		${WRKSRC}/Makefile.template > ${WRKSRC}/Makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/saytime

post-install:
	cd ${WRKSRC}/times && pax -rw * ${DESTDIR}${PREFIX}/share/saytime/

.include "../../mk/bsd.pkg.mk"
