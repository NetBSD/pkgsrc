# $NetBSD: Makefile,v 1.3 1998/05/08 14:22:04 frueauf Exp $
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
.else
MASTER_SITE_SUBDIR=	netBSD-${MACHINE_ARCH}
.endif
EXTRACT_SUFX=		.tgz

MAINTAINER=		lamj@stat.cmu.edu

ONLY_FOR_ARCHS=		arm32 i386 m68k sparc

DIST_SUBDIR=		xforms/${MASTER_SITE_SUBDIR}

## Define OBJMACHINE so WRKDIR is defined to be ${MACHINE_ARCH}-specific.
OBJMACHINE=		yes

NO_BUILD=		yes

USE_X11=		yes

MAN1=			fdesign.1 fd2ps.1
MAN5=			forms.5 xforms.5

post-patch:
	${MV} ${WRKSRC}/mkconfig.h ${WRKSRC}/mkconfig.h.orig
	${CP} ${FILESDIR}/mkconfig.h ${WRKSRC}

post-install:
	${LDCONFIG} || ${TRUE}

.include "../../mk/bsd.pkg.mk"
