# $NetBSD: Makefile,v 1.78 2020/09/21 03:43:22 mef Exp $

DISTNAME=	gnustep-gui-0.22.0
PKGREVISION=	23
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep AppKit Implementation
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

# problem:
# | In file included from ../Headers/AppKit/AppKit.h:117:
# | ../Headers/AppKit/NSWorkspace.h:169:14: error: redefinition of 'NSAppleEventDescriptor' as different kind of symbol
# | typedef void NSAppleEventDescriptor;
# |              ^
# | /tmp/x11/gnustep-gui/work/.buildlink/include/Foundation/NSAppleEventDescriptor.h:36:12: note: previous definition is here
# | @interface NSAppleEventDescriptor : NSObjec

# hint: https://www.mail-archive.com/gnustep-cvs@gna.org/msg17908.html
SUBST_CLASSES+=	gs
SUBST_FILES.gs=	Source/NSAnimation.m
SUBST_STAGE.gs=	pre-configure
SUBST_SED.gs=	-e 's/GS_GC_UNHIDE//'
SUBST_SED.gs+=	-e 's/GS_GC_HIDE//'

INSTALLATION_DIRS+=	share/GNUstep/Applications

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
