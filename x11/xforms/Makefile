# $NetBSD: Makefile,v 1.38 2001/11/29 01:12:53 hubertf Exp $
#

DISTNAME=       bxform-088
PKGNAME=	xforms-0.88
PKGREVISION=       1
WRKSRC=		${WRKDIR}/xforms
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/${ARCH_SUBDIR}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://world.std.com/~xforms/
COMMENT=	Graphical user interface toolkit for X Window System

LICENSE=	fee-based-commercial-use

.if (${MACHINE_ARCH} == "arm32")
ARCH_SUBDIR=    netBSD-arm
.elif (${MACHINE_ARCH} == "i386")
ARCH_SUBDIR=    netBSD
.elif (${MACHINE_ARCH} == "ns32k")
ARCH_SUBDIR=    netBSD-pc532
.else
ARCH_SUBDIR=    netBSD-${MACHINE_ARCH}
.endif

DIST_SUBDIR=		xforms-${MACHINE_ARCH}

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mipsel NetBSD-*-ns32k \
			NetBSD-*-sparc NetBSD-*-powerpc SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${OBJECT_FMT} == "ELF"
DISTNAME=	bxform-088-ELF
.endif
.if ${MACHINE_ARCH} == "sparc" && ${OBJECT_FMT} == "ELF"
DISTNAME=	bxform-088-ELF
.endif

.if ${OPSYS} == "SunOS"
DISTNAME=	bxform-088
.if ${MACHINE_ARCH} == "sparc"
ARCH_SUBDIR=	sun/Solaris
.elif ${MACHINE_ARCH} == "i386"
ARCH_SUBDIR=	solaris-x86/2.7
.endif
DIST_SUBDIR=	xforms-${OPSYS}-${MACHINE_ARCH}
.endif

## Define OBJMACHINE so WRKDIR is defined to be ${MACHINE_ARCH}-specific.
OBJMACHINE=	YES

USE_X11BASE=	YES
USE_LIBTOOL=	YES
MAKEFILE=	${FILESDIR}/Makefile
PLIST_SRC=	${PKGDIR}/PLIST.mi ${PKGDIR}/PLIST.shlib

CHECK_SHLIBS=	NO	# fdesigner doesn't find libX11 on i386
# we don't have sources, so don't run this test

# When the XForms API changes and breaks binary-compatibility with the
# previous version, increment the MAJOR by 1 and reset the MINOR to 0.
#
SHLIB_MAJOR=	0
SHLIB_MINOR=	88

MAKE_ENV+=	SHLIB_MAJOR="${SHLIB_MAJOR}" SHLIB_MINOR="${SHLIB_MINOR}"

# XXX Run-time link editor tries to resolve libGL.so symbols when linking
# XXX with shared libxforms, but all the packages that requre xforms seem
# XXX to work OK without -lGL, so for now, remove the shared lib.
PLIST_SRC=	${PKGDIR}/PLIST.mi

post-install:
	${RM} -f \
		${PREFIX}/lib/libforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		${PREFIX}/lib/libforms.so.${SHLIB_MAJOR} \
		${PREFIX}/lib/libforms.so \
		${PREFIX}/lib/libxforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		${PREFIX}/lib/libxforms.so.${SHLIB_MAJOR} \
		${PREFIX}/lib/libxforms.so

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
