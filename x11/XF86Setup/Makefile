# $NetBSD: Makefile,v 1.4 1998/09/08 10:17:21 agc Exp $

DISTNAME=	XF86Setup-3.3.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.xfree86.org/

BUILD_DEPENDS+= ${TCLLIB}:../../lang/tcl80 \
		${TKLIB}:../../x11/tk80

TCLLIB=		${LOCALBASE}/lib/libtcl80.a
TKLIB=		${LOCALBASE}/lib/libtk80.a

MIRROR_DISTFILE= no
WRKSRC=		${WRKDIR}/XF86Setup
USE_IMAKE=	yes

pre-configure:
	@touch ${WRKSRC}/res_cpp_symbol

.include "../../mk/bsd.pkg.mk"
