# $NetBSD: Makefile,v 1.7 2003/12/03 17:41:21 gson Exp $
# based on
#    FreeBSD port:
#    ID: ports/x11-wm/bbapm/Makefile,v 1.5 2002/09/02 01:30:15 lioux Exp
#    OpenBSD patch for apm, available from:
#    http://bbtools.windsofstorm.net/sources/bbapm-0.0.1-openbsd-patch.diff

DISTNAME=	bbapm-0.0.1
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	jschauma@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/
COMMENT=	APM monitor for Blackbox

GNU_CONFIGURE=	yes
USE_X11=	yes

# For now:
# We use i386/apmvar.h; other architectures will require modification
# of the patches, probably something like ${MACHINE_ARCH}/apmvar.h in
# patch-ak
ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-*

post-patch:
	${SED} -e 's,@PREFIX@,${PREFIX},' ${WRKSRC}/data/bbapm.1.tmp > \
		${WRKSRC}/data/bbapm.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbapm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/data/bbapm.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/bbtools
.for a in README.bbapm bbapm.conf bbapm.nobb bbapm.style
	${INSTALL_DATA} ${WRKSRC}/data/${a} ${PREFIX}/share/bbtools
.endfor

.include "../../mk/bsd.pkg.mk"

.if ${OPSYS} == "Linux"
LDFLAGS+=	-lapm
.endif
