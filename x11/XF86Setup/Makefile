# $NetBSD: Makefile,v 1.19 2001/04/30 15:06:26 tron Exp $

DISTNAME=		XF86Setup-3.3.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		Graphical configuration tool for XFree86

BUILD_DEPENDS= 		tcl-8.3.2nb1:../../lang/tcl
BUILD_DEPENDS+=		tk-8.3.2:../../x11/tk

ONLY_FOR_PLATFORM=	*-*-i386

TCLLIB=			${LOCALBASE}/lib/libtcl83.a
TKLIB=			${LOCALBASE}/lib/libtk83.a

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

WRKSRC=			${WRKDIR}/hw/xfree86/XF86Setup
USE_IMAKE=		yes

.if !defined(X11_RELEASE) && !defined(CHECK_X11)
X11_RELEASE!=	${MAKE} CHECK_X11=YES print-x11-release
MAKEFLAGS+=	X11_RELEASE="${X11_RELEASE}"
.if (${X11_RELEASE} == "6.4")
IGNORE=		"This package doesn't work with your X11 distribution."
.endif
.endif

pre-configure:
	@${TOUCH} ${WRKSRC}/res_cpp_symbol

.include "../../mk/bsd.pkg.mk"

print-x11-release:
	@${GREP} '^#define SharedXextRev' ${X11BASE}/lib/X11/config/X11.tmpl \
	| ${AWK} '{print($$3)}'
