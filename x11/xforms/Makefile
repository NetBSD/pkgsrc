# $NetBSD: Makefile,v 1.16 1999/08/25 22:48:37 bad Exp $
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

# for OBJECT_FORMAT, LOWER_OPSYS, MACHINE_PLATFORM, ...
.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-ns32k *-*-sparc

# XXX no ELF objects for sparc and i386 on NetBSD
.if (${LOWER_OPSYS} == "netbsd") && ((${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "sparc"))
.if (${OBJECT_FMT} == "ELF")
NOT_FOR_PLATFORM=	${MACHINE_PLATFORM}
.endif
.endif

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
