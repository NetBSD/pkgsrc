# $NetBSD: Makefile,v 1.18 1999/09/23 03:42:29 jlam Exp $
#

DISTNAME=       bxform-088
PKGNAME=	xforms-0.88
WRKSRC=		${WRKDIR}/xforms
CATEGORIES=	x11
MASTER_SITES=	ftp://bragg.phys.uwm.edu/pub/xforms/${ARCH_SUBDIR}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://bragg.phys.uwm.edu/xforms/

.if (${MACHINE_ARCH} == "arm32")
ARCH_SUBDIR=	netBSD-arm
.elif (${MACHINE_ARCH} == "i386")
ARCH_SUBDIR=	netBSD
.elif (${MACHINE_ARCH} == "ns32k")
ARCH_SUBDIR=	netBSD-pc532
.else
ARCH_SUBDIR=	netBSD-${MACHINE_ARCH}
.endif

ONLY_FOR_PLATFORM=	*-*-arm32 *-*-i386 *-*-m68k *-*-ns32k *-*-sparc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OBJECT_FMT} == "ELF"
.if ${MACHINE_ARCH} == "i386"
DISTNAME=	bxform-088-ELF
.endif
.if ${MACHINE_ARCH} == "sparc"
# XXX no ELF objects for sparc on NetBSD
IGNORE="is not available for ${MACHINE_PLATFORM} using the ELF object format."
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
	${LN} -fs libforms.a ${PREFIX}/lib/libxforms.a
	${LN} -fs libforms.so.0.88 ${PREFIX}/lib/libxforms.so.0.88

.include "../../mk/bsd.pkg.mk"
