# $NetBSD: Makefile,v 1.3 2002/04/12 13:20:01 jlam Exp $
#

DISTNAME=		xplanet-0.93
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://prdownloads.sourceforge.net/xplanet/

MAINTAINER=		atatat@netbsd.org
HOMEPAGE=		http://xplanet.sourceforge.net/
COMMENT=		Rotating rendered map of the Earth in X11 root window

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gl-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-glut-dir=${BUILDLINK_DIR}

USE_GMAKE=		yes

LIBS=			-lpbm -lppm -lpgm
MAKE_ENV+=		LIBS="${LIBS}"

pre-configure:
	cd ${WRKSRC} ; \
	f=xplanet.1 ; \
	[ -f $$f.BAK ] || ${MV} $$f $$f.BAK ; \
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < $$f.BAK > $$f

.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/libungif/buildlink.mk"
.include "../../graphics/netpbm/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../x11/tk/buildlink.mk"

#.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
