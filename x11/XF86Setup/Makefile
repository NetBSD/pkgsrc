# $NetBSD: Makefile,v 1.18 2001/03/27 03:20:25 hubertf Exp $

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

pre-configure:
	@${TOUCH} ${WRKSRC}/res_cpp_symbol

.include "../../mk/bsd.pkg.mk"
