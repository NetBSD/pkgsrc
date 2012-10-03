# $NetBSD: Makefile,v 1.73.2.1 2012/10/03 12:09:42 spz Exp $

DISTNAME=	amaya-fullsrc-11.3.1
PKGNAME=	${DISTNAME:S/-fullsrc//}
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web browser/editor from the World Wide Web Consortium (W3C)
LICENSE=	amaya-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl pkg-config
GNU_CONFIGURE=		yes

# builds receive SIGSEGV (go figure)
MAKE_JOBS_SAFE=		no

BUILDDIR=		${WRKDIR}/Amaya/work
WRKSRC=			${WRKDIR}
CONFIGURE_DIRS=		Amaya/work		# also sets BUILD_DIRS
CONFIGURE_SCRIPT=	../configure
BUILD_TARGET=		all

CFLAGS+=		-Dunix

FONTS_DIRS.ttf+=	${PREFIX}/share/Amaya/fonts
REQD_DIRS+=		${PREFIX}/share/Amaya ${PREFIX}/share/Amaya/fonts

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_COMPILER:Mgcc*)
CFLAGS+=		-fno-strict-aliasing
.endif

#
# Some notes on the build issues, for the benefit of the next person
# hacking this package:
#
# - The build directory must be a subdir of the Amaya dir of the
# distribution. If it isn't, the build breaks. This is why the
# build dir is put where it is and not directly under ${WRKDIR}.
# (This was true in 10.x; it might not be true any longer.)
#
# - The distfile currently includes copies of Mesa, freetype, libwww,
# redland, and wxWidgets as well as Amaya itself. In 10.x it used to
# also contain a pile of graphics libraries; these have thankfully
# been pruned.
#
# - There is no reason I can see to use or care about the included
# Mesa, freetype, or redland.
#
# - The pkgsrc package used to use the included wxWidgets because at
# the time it was put together pkgsrc didn't have wxGTK28, only
# 26. This is no longer true and it should be safe to ignore the
# included wxWidgets. However, if it needs to come back, beware of
# copies of other libs included in it that Amaya may forcibly build
# and use; in 10.x the only way to get the included wxWidgets to not
# use its own copies of png, jpeg, tiff, and xpm was to patch the
# Amaya build logic. I've left this patch in place for future
# reference, although it's only about 50% likely it'll have any effect
# next time. Do not believe the build docs or the configure script
# when it claims to allow you to disable builtin copies of libs; it
# lies.
#
# - The included libwww, however, appears to be necessary. In 10.x it
# was a custom-patched version; now it appears not to be but it is
# also a newer version than found in pkgsrc. As I don't think a newer
# libwww than the one in pkgsrc has actually been released, it may as
# well be a custom-patched version. Given the history it is unlikely
# that Amaya will work with the older libwww in pkgsrc... assuming it
# works at all of course... so it is probably best to use the included
# libwww until such time as this becoems clearer.
#
# - The included libwww includes in turn its own copy of expat. In
# 10.x this was also a custom-patched version. This may or may not be
# true now. Regardless, Amaya shold be made to use pkgsrc expat,
# because as things stand it is likely to end up with multiple expats
# linked into it at once, and that's unlikely to work. I have not done
# this yet though. (XXX)
#
# - As of 10.x the code using redland did not work, even using the
# copy of redland included in the distfile. The schemas it tries to
# build are syntactically invalid. It *might* be a simple problem, I
# don't know enough about that stuff to fix it. Maybe someone else
# does. I haven't tried this in 11.x yet. (XXX)
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
# - The DAV code does not build by default. It requires generated
# files from a later part of the build to already exist when it's
# compiled. (That is, davlib/ doesn't build until part of amaya/ is
# built, but you can't successfully build amaya/ without davlib/
# because it needs to link with it. It turns out that this can be
# hacked around by forcibly disabling the davlib/ directory in the
# top-level makefile; if davlib is nonetheless enabled, the amaya/
# makefile recurses back to it to build it after generating the file
# it needs. Sheesh. Between this and other issues it's clear that
# whoever develops this thing never tries building a clean tree, and
# sometimes I wonder if they compile it at all before releasing it.
#

post-extract:
	${MKDIR} ${BUILDDIR}

post-configure:
	${CP} ${BUILDDIR}/Options.orig ${BUILDDIR}/Options
	${TOUCH} ${BUILDDIR}/Makefile

# The davlib code doesn't build, so disable it. (no longer necessary)
#CONFIGURE_ARGS+=	--without-dav

#
# Use the supplied (prerelease?) libwww; use pkgsrc for everything else.
# See notes above, and check the cvs history for tips if trying to reenable
# the builtin wxWidgets.
#
EXTRACT_ELEMENTS=	Amaya libwww
CONFIGURE_ARGS+=	--enable-system-redland
CONFIGURE_ARGS+=	--enable-system-wx

#.include "../../www/libwww/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
