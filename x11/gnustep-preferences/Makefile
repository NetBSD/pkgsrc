# $NetBSD: Makefile,v 1.5 2003/05/05 19:05:25 jmmv Exp $
#

DISTNAME=	Preferences-1.2.0
PKGNAME=	gnustep-${DISTNAME:S/P/p/}
PKGREVISION=	3
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prefsapp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://prefsapp.sourceforge.net/
COMMENT=	Application for setting preferences for the GNUstep system

NO_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_X11=	YES
MAKEFILE=	GNUmakefile

#
# Gnustep seems to use it's own idea of architecture names and at least for
# i386 is using ix86. For other archs default for MACHINE_ARCH.
# Tested specifically on x86 and powerpc
.if (${MACHINE_ARCH} == "i386")
PLIST_SUBST+= 	ARCH="ix86"
PLIST_SUBST+=	ARCH_LOC="ix86/${LOWER_OPSYS}elf"
.else
PLIST_SUBST+=	ARCH="${MACHINE_ARCH}"
PLIST_SUBST+=	ARCH_LOC="${MACHINE_ARCH}/${LOWER_OPSYS}"
.endif

.include "../../x11/gnustep-back/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
