# $NetBSD: Makefile,v 1.7 2002/11/17 09:11:14 jlam Exp $
#

DISTNAME=		xplanet-0.93
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=		atatat@netbsd.org
HOMEPAGE=		http://xplanet.sourceforge.net/
COMMENT=		Rotating rendered map of the Earth in X11 root window

USE_BUILDLINK2=		yes
USE_CXX=		yes
USE_X11=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gl-dir=${BUILDLINK_PREFIX.Mesa}
CONFIGURE_ARGS+=	--with-glut-dir=${BUILDLINK_PREFIX.Mesa}

LIBS=			-lXext -lpbm -lppm -lpgm
MAKE_ENV+=		LIBS="${LIBS}"

pre-configure:
	cd ${WRKSRC} ; \
	f=xplanet.1 ; \
	[ -f $$f.BAK ] || ${MV} $$f $$f.BAK ; \
	${SED} -e 's|@PREFIX@|${PREFIX}|g' < $$f.BAK > $$f

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/netpbm/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
