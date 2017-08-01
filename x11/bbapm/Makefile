# $NetBSD: Makefile,v 1.17 2017/08/01 14:59:07 wiz Exp $
# based on
#    FreeBSD port:
#    ID: ports/x11-wm/bbapm/Makefile,v 1.5 2002/09/02 01:30:15 lioux Exp
#    OpenBSD patch for apm, available from:
#    http://bbtools.windsofstorm.net/sources/bbapm-0.0.1-openbsd-patch.diff

DISTNAME=	bbapm-0.0.1
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bbtools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/bbtools/?source=directory
COMMENT=	APM monitor for Blackbox

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

# For now:
# We use i386/apmvar.h; other architectures will require modification
# of the patches, probably something like ${MACHINE_ARCH}/apmvar.h in
# patch-ak
ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-*

LDFLAGS.Linux+=		-lapm

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/bbapm.1.tmp > \
		${WRKSRC}/data/bbapm.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbapm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/data/bbapm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/bbtools
.for a in README.bbapm bbapm.conf bbapm.nobb bbapm.style
	${INSTALL_DATA} ${WRKSRC}/data/${a} ${DESTDIR}${PREFIX}/share/bbtools
.endfor

.include "../../mk/bsd.pkg.mk"
