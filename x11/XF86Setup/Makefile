# $NetBSD: Makefile,v 1.14 2000/03/16 14:17:13 wiz Exp $

DISTNAME=		XF86Setup-3.3.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xfree86.org/

BUILD_DEPENDS= 		${TCLLIB}:../../lang/tcl80
BUILD_DEPENDS+=		${TKLIB}:../../x11/tk80

ONLY_FOR_PLATFORM=	*-*-i386

TCLLIB=			${LOCALBASE}/lib/libtcl80.a
TKLIB=			${LOCALBASE}/lib/libtk80.a

MIRROR_DISTFILE=	no
WRKSRC=			${WRKDIR}/hw/xfree86/XF86Setup
USE_IMAKE=		yes

pre-configure:
	@${TOUCH} ${WRKSRC}/res_cpp_symbol

.include "../../mk/bsd.pkg.mk"
