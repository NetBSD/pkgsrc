# $NetBSD: Makefile,v 1.9 1999/09/02 19:51:37 tron Exp $

DISTNAME=		XF86Setup-3.3.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2
ONLY_FOR_PLATFORM=	*-*-i386

MAINTAINER=		tron@netbsd.org
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
