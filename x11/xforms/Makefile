# $NetBSD: Makefile,v 1.24 2000/03/01 01:50:11 dmcmahill Exp $
#

DISTNAME=       bxform-088
PKGNAME=	xforms-0.88
WRKSRC=		${WRKDIR}/xforms
CATEGORIES=	x11
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/${ARCH_SUBDIR}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://world.std.com/~xforms

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

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k \
			NetBSD-*-mipsel NetBSD-*-ns32k NetBSD-*-sparc NetBSD-*-powerpc

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${OBJECT_FMT} == "ELF"
DISTNAME=	bxform-088-ELF
.endif
.if ${MACHINE_ARCH} == "sparc" && ${OBJECT_FMT} == "ELF"
DISTNAME=	bxform-088-ELF
.endif

## Define OBJMACHINE so WRKDIR is defined to be ${MACHINE_ARCH}-specific.
OBJMACHINE=	yes

USE_X11BASE=	yes
USE_LIBTOOL=	yes
MAKEFILE=	${FILESDIR}/Makefile
PLIST_SRC=	${PKGDIR}/PLIST.mi ${PKGDIR}/PLIST.shlib

# When the XForms API changes and breaks binary-compatibility with the
# previous version, increment the MAJOR by 1 and reset the MINOR to 0.
#
SHLIB_MAJOR=	0
SHLIB_MINOR=	88

MAKE_ENV+=	SHLIB_MAJOR="${SHLIB_MAJOR}" SHLIB_MINOR="${SHLIB_MINOR}"

# XXX ELF linker tries to resolve libGL.so symbols when linking with
# XXX shared libxforms, so for now, remove the shared lib.
.if ${OBJECT_FMT} == "ELF"
PLIST_SRC=	${PKGDIR}/PLIST.mi

post-install:
	${RM} -f \
		${PREFIX}/lib/libforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		${PREFIX}/lib/libforms.so.${SHLIB_MAJOR} \
		${PREFIX}/lib/libforms.so \
		${PREFIX}/lib/libxforms.so.${SHLIB_MAJOR}.${SHLIB_MINOR} \
		${PREFIX}/lib/libxforms.so.${SHLIB_MAJOR} \
		${PREFIX}/lib/libxforms.so
.endif

.include "../../mk/bsd.pkg.mk"
