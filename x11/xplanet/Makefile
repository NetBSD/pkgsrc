# $NetBSD: Makefile,v 1.1 2002/03/25 16:08:07 atatat Exp $
#

DISTNAME=		xplanet-0.93
CATEGORIES=		x11
MASTER_SITES=		http://prdownloads.sourceforge.net/xplanet/

MAINTAINER=		atatat@netbsd.org
HOMEPAGE=		http://xplanet.sourceforge.net/
COMMENT=		Rotating rendered map of the Earth in X11 root window

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--with-gl-dir=${X11BASE} --with-glut-dir=${X11BASE}
USE_GMAKE=		yes

DEPENDS+=		MesaLib-*:../../graphics/MesaLib
DEPENDS+=		glut-*:../../graphics/glut
DEPENDS+=		glu-*:../../graphics/glu

LIBS=			-lpbm -lppm -lpgm
MAKE_ENV+=		LIBS="${LIBS}"

.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/netpbm/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
