# $NetBSD: Makefile,v 1.37 2006/04/22 09:22:16 rillig Exp $
#

DISTNAME=	fluxbox-0.9.15.1
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

BUILDLINK_TRANSFORM+=	rename:-O2:-O1

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


.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
