# $NetBSD: Makefile,v 1.11 2000/01/15 15:24:34 tron Exp $

DISTNAME=		XF86Setup-3.3.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2
ONLY_FOR_PLATFORM=	*-*-i386

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.xfree86.org/

BUILD_DEPENDS= 		${TCLLIB}:../../lang/tcl80 \
			${TKLIB}:../../x11/tk80

TCLLIB=			${LOCALBASE}/lib/libtcl80.a
TKLIB=			${LOCALBASE}/lib/libtk80.a

MIRROR_DISTFILE=	no
WRKSRC=			${WRKDIR}/hw/xfree86/XF86Setup
USE_IMAKE=		yes

pre-configure:
	@touch ${WRKSRC}/res_cpp_symbol

.include "../../mk/bsd.pkg.mk"
