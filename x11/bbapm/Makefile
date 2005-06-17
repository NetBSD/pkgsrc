# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:43 jlam Exp $
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

# For now:
# We use i386/apmvar.h; other architectures will require modification
# of the patches, probably something like ${MACHINE_ARCH}/apmvar.h in
# patch-ak
ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-*

INSTALLATION_DIRS=	bin man/man1

.include "../../mk/x11.buildlink3.mk"

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
