# $NetBSD: Makefile,v 1.14 1999/06/20 21:06:22 tron Exp $
#

DISTNAME=	bxform-088
PKGNAME=	xforms-0.88
WRKSRC=		${WRKDIR}/xforms
CATEGORIES=	x11
MASTER_SITES=	ftp://bragg.phys.uwm.edu/pub/xforms/${ARCH_SUBDIR}/
.if (${MACHINE_ARCH} == "arm32")
ARCH_SUBDIR=	netBSD-arm
.elif (${MACHINE_ARCH} == "i386")
ARCH_SUBDIR=	netBSD
.elif (${MACHINE_ARCH} == "ns32k")
ARCH_SUBDIR=	netBSD-pc532
.else
ARCH_SUBDIR=	netBSD-${MACHINE_ARCH}
.endif
EXTRACT_SUFX=	.tgz

MAINTAINER=	lamj@stat.cmu.edu
HOMEPAGE=	http://bragg.phys.uwm.edu/xforms/

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-ns32k *-*-sparc

DIST_SUBDIR=	xforms-${MACHINE_ARCH}

## Define OBJMACHINE so WRKDIR is defined to be ${MACHINE_ARCH}-specific.
OBJMACHINE=	yes

NO_BUILD=	yes

USE_X11BASE=	yes

post-patch:
	${MV} ${WRKSRC}/mkconfig.h ${WRKSRC}/mkconfig.h.orig
	${CP} ${FILESDIR}/mkconfig.h ${WRKSRC}

post-install:
	(cd ${PREFIX}/lib; ${LN} -fs libforms.a libxforms.a)
	(cd ${PREFIX}/lib; ${LN} -fs libforms.so.0.88 libxforms.so.0.88)

.include "../../mk/bsd.pkg.mk"
