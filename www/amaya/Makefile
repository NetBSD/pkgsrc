# $NetBSD: Makefile,v 1.62 2011/01/13 13:39:36 wiz Exp $

DISTNAME=	amaya-fullsrc-10.0.1
PKGNAME=	${DISTNAME:S/-fullsrc//}
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web browser/editor from the World Wide Web Consortium (W3C)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/Amaya/work
CONFIGURE_SCRIPT=	../configure
BUILD_TARGET=		all

CFLAGS+=		-Dunix

FONTS_DIRS.ttf+=	${PREFIX}/share/Amaya/fonts
REQD_DIRS+=		${PREFIX}/share/Amaya ${PREFIX}/share/Amaya/fonts

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mgcc*)
CFLAGS+=		-fno-strict-aliasing
.endif

# GNOME/KDE desktop icon and related bits
# These used to get installed only on Linux; in 10.0.1 they don't seem
# to exist any more, but given the makefiles in this package that
# doesn't prove anything, and I can't test on Linux easily. So I'm
# going to leave this here commented out, along with the PLIST
# entries, until they're confirmed to be gone.
#PLIST_VARS+=	desktop
#.if ${OPSYS} == "Linux"
#PLIST.desktop=	yes
#.endif

#
# Some notes on the build issues, for the benefit of the next person
# hacking this package:
#
# - The build directory must be a subdir of the Amaya dir of the
# distribution. If it isn't, the build breaks. Hence WRKSRC.
#
# - The copy of libwww that comes in the distfile is required; it is
# custom-patched in unspecified ways. The copy of expat in that copy
# of libwww is also custom-patched. This means we need to use that
# expat and not the pkgsrc one, which is problematic because wxWidgets
# also uses expat.
#
# - The build system is incapable of building that libwww without
# help; if the libwww subdir of the build directory does not exist,
# the makefiles won't create it, and it's not created by the configure
# script. Thus the manual invocation of make libwww_config in
# post-configure.
#
# - The distfile contains not just one but multiple included copies of
# various basic libraries (libpng, libjpeg, zlib, expat) and for the
# most part we don't want to use those copies, because they're out of
# date. It is like pulling teeth - you have to patch all over the
# place, even though the configure script ostensibly supports using
# the system versions.
#
# - For now I'm using the included copy of wxWidgets, because the
# pkgsrc copy is too old. This has a couple of its own issues, but,
# once one forcibly persuades the Amaya configure script to configure
# it correctly, isn't a big problem.
#
# - The code using redland does not work, even using the copy of
# redland included in the distfile. The schemas it tries to build are
# syntactically invalid. It *might* be a simple problem, I don't know
# enough about that stuff to fix it. Maybe someone else does.
#
# - The DAV code does not build. It requires generated files from a
# later part of the build to already exist when it's compiled. I don't
# know if it also must come before that part of the build, but it
# wouldn't entirely surprise me if it did; between this and the libwww
# issue it's clear that whoever develops this thing never tries
# building a clean tree. By the time I got to this I was tired of the
# lossage and just disabled the DAV code entirely.
#
# - The build target is "all". This is not the default. The default
# build target (if you just run make) also sort of builds the package
# but doesn't actually work.
#
# - The makefiles link some of the internal portions of the program
# using -l/-L, and some by explicitly listing .a files. The pkgsrc
# wrappers reorder these and break the build. I patched the makefiles
# to always explicitly name .a files for internal program pieces.
#

post-extract:
	${MKDIR} ${WRKSRC}

post-configure:
	${CP} ${WRKSRC}/Options.orig ${WRKSRC}/Options
	${TOUCH} ${WRKSRC}/Makefile
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${GMAKE} libwww_config

#
# Components, deps, and included copies of libraries
#

EXTRACT_ELEMENTS=	Amaya

# Requires its own custom-patched libwww,
# which also incl. a custom-patched expat.
EXTRACT_ELEMENTS+=	libwww
# -or-
#.include "../../www/libwww/buildlink3.mk"
#.include "../../textproc/expat/buildlink3.mk"

# The Amaya portion of the distfile inclues copies of libpng, jpeg, and zlib.
# Use pkgsrc's libpng, jpeg, and zlib instead.
CONFIGURE_ARGS+=	--without-graphic-libs	# Use pkgsrc libraries
# link correctly with pkgsrc zlib (XXX: is this needed or correct?)
LIBS+=			${COMPILER_RPATH_FLAG}${PREFIX}/lib
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

# The davlib code doesn't build.
CONFIGURE_ARGS+=	--without-dav

# pkgsrc doesn't have redland (yet?)
# disable; currently doesn't work and I don't have time to chase down why
#EXTRACT_ELEMENTS+=	redland
#  -or-
#CONFIGURE_ARGS+=	--enable-system-redland
#.include "../../???/redland/buildlink3.mk"

# pkgsrc's wxGTK is too old (2.6.3; 2.8.x is required)
EXTRACT_ELEMENTS+=	wxWidgets
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xf86vidmodeproto/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
CONFIGURE_ENV+=		BUILDLINK_DIR=${BUILDLINK_DIR:Q}
# wxWidgets has *another* copy of a bunch of image libs.
CONFIGURE_ARGS+=	--with-libpng=sys	# Use pkgsrc libraries
CONFIGURE_ARGS+=	--with-libjpeg=sys	# Use pkgsrc libraries
CONFIGURE_ARGS+=	--with-libtiff=sys	# Use pkgsrc libraries
CONFIGURE_ARGS+=	--with-libxpm=sys	# Use pkgsrc libraries
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
# wxWidgets also has a private copy of expat; since Amaya ostensibly
# needs the patched expat in its libwww, which is at least the same
# version as the one in wxWidgets, we'll let wxWidgets use its builtin
# copy. That way if both are linked the fallout should be limited, and
# maybe (ha!) the Amaya developers have seen to it. This will probably
# break with pkgsrc wxWidgets, but we can worry about that later.
#.include "../../textproc/expat/buildlink3.mk"
# -or-
#CONFIGURE_ARGS+=	--enable-system-wx	# Use pkgsrc libraries
#.include "../../graphics/glu/buildlink3.mk"
#.include "../../x11/wxGTK/buildlink3.mk"

# also uses glib
.include "../../devel/glib2/buildlink3.mk"


.include "../../mk/bsd.pkg.mk"
