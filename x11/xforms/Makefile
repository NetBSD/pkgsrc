# $NetBSD: Makefile,v 1.9 1998/11/13 13:04:15 matthias Exp $
#

DISTNAME=		bxform-088
PKGNAME=		xforms-0.88
WRKSRC=			${WRKDIR}/xforms
CATEGORIES=		x11
MASTER_SITES=	ftp://bragg.phys.uwm.edu/pub/xforms/%SUBDIR%/
.if (${MACHINE_ARCH} == "arm32")
MASTER_SITE_SUBDIR=	netBSD-arm
.elif (${MACHINE_ARCH} == "i386")
MASTER_SITE_SUBDIR=	netBSD
.elif (${MACHINE_ARCH} == "ns32k")
MASTER_SITE_SUBDIR=	netBSD-pc532
.else
MASTER_SITE_SUBDIR=	netBSD-${MACHINE_ARCH}
.endif
EXTRACT_SUFX=		.tgz

MAINTAINER=		lamj@stat.cmu.edu
HOMEPAGE=		http://bragg.phys.uwm.edu/xforms/

ONLY_FOR_ARCHS=		arm32 i386 m68k sparc ns32k

DIST_SUBDIR=		xforms/${MASTER_SITE_SUBDIR}

## Define OBJMACHINE so WRKDIR is defined to be ${MACHINE_ARCH}-specific.
OBJMACHINE=		yes

NO_BUILD=		yes

USE_X11=		yes

post-patch:
	${MV} ${WRKSRC}/mkconfig.h ${WRKSRC}/mkconfig.h.orig
	${CP} ${FILESDIR}/mkconfig.h ${WRKSRC}

post-install:
	(cd ${PREFIX}/lib; ${LN} -fs libforms.a libxforms.a)
	(cd ${PREFIX}/lib; ${LN} -fs libforms.so.0.88 libxforms.so.0.88)

.include "../../mk/bsd.pkg.mk"
