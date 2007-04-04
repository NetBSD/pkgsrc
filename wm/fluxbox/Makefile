# $NetBSD: Makefile,v 1.42 2007/04/04 13:34:42 joerg Exp $
#

DISTNAME=	fluxbox-1.0rc3
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

.for option in 9 8 7 6 5 4 3 2 s
BUILDLINK_TRANSFORM+=	rename:-O${option}:-O1
.endfor

CONFIGURE_ARGS+=	--enable-shape
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-xinerama

.include "options.mk"

SUBST_CLASSES+=		cmds
SUBST_STAGE.cmds=	post-build
SUBST_MESSAGE.cmds=	Fixing command names in data files.
SUBST_SED.cmds=		-e 's|bsetroot|fbsetroot|g'
SUBST_FILES.cmds=	data/README.style data/styles/Artwiz\
                        data/styles/MerleyKay data/styles/Outcomes\
		       	data/styles/Rampage data/styles/Results\
		       	data/styles/Spiff

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
