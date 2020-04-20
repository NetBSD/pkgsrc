# $NetBSD: Makefile,v 1.129 2020/04/20 17:04:18 adam Exp $

DISTNAME=	WindowMaker-0.95.9
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	wm windowmaker
MASTER_SITES=	https://windowmaker.org/pub/source/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.windowmaker.org/
COMMENT=	GNUStep-compliant NEXTSTEP(tm) window manager clone
LICENSE=	gnu-gpl-v2

BROKEN_GETTEXT_DETECTION=	yes

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt perl:run pkg-config xgettext
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-magick
CONFIGURE_ARGS+=	--enable-pango
CONFIGURE_ARGS+=	--enable-usermenu
CONFIGURE_ARGS+=	--enable-xinerama
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-defsdatadir=${PREFIX}/share/examples/WindowMaker
CONFIGURE_ARGS+=	--with-gnustepdir=${PREFIX}/share/GNUstep
CONFIGURE_ENV+=		LINGUAS="bg ca cs cz da de el es et fi fr gl he hr hu it ja ko nl ms no pl pt ro ru se sk sl sv tr zh_CN zh_TW"
CONFIGURE_ENV+=		CPP_PATH=${CPP:Q}
REPLACE_PERL+=		util/wkdemenu.pl

INSTALLATION_DIRS=	share/WindowMaker/SoundSets
INSTALLATION_DIRS+=	share/WindowMaker/Sounds
INSTALLATION_DIRS+=	share/doc/WindowMaker

PKGCONFIG_OVERRIDE=		WINGs/WINGs.pc
PKGCONFIG_OVERRIDE+=		WINGs/WUtil.pc
PKGCONFIG_OVERRIDE+=		wmlib/wmlib.pc
PKGCONFIG_OVERRIDE+=		wrlib/wrlib.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../mk/compiler.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.11-*)
CONFIGURE_ENV+=		ac_cv_lib_Xext_XineramaGetInfo=no
.endif

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=	3.0
.endif

CFLAGS.SunOS+=		-D__EXTENSIONS__

PKG_SYSCONFSUBDIR=	WindowMaker
EGDIR=			${PREFIX}/share/examples/WindowMaker
CONF_FILES=
.for f in WMGLOBAL WMRootMenu WMState WMWindowAttributes WindowMaker
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

SUBST_CLASSES+=		fix-path
SUBST_STAGE.fix-path=	pre-configure
SUBST_MESSAGE.fix-path=	Fixing absolute paths.
SUBST_FILES.fix-path=	WINGs/wapplication.c
SUBST_FILES.fix-path+=	WindowMaker/Defaults/WindowMaker.in
SUBST_FILES.fix-path+=	WPrefs.app/Paths.c
SUBST_FILES.fix-path+=	WindowMaker/menu*
SUBST_FILES.fix-path+=	WindowMaker/plmenu*
SUBST_SED.fix-path=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-path+=	-e 's,${PREFIX}/GNUstep,${PREFIX}/share/GNUstep,g'

pre-configure:
	${RM} -f ${WRKSRC}/WindowMaker/Defaults/WMState \
		 ${WRKSRC}/WindowMaker/Defaults/WMWindowAttributes \
		 ${WRKSRC}/WindowMaker/Defaults/WindowMaker \
		 ${WRKSRC}/po/zh_TW.Big5.po

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/share/WindowMaker/SoundSets/.directory
	${TOUCH} ${DESTDIR}${PREFIX}/share/WindowMaker/Sounds/.directory

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
