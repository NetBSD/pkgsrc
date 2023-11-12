# $NetBSD: Makefile,v 1.24 2023/11/12 13:24:19 wiz Exp $

DISTNAME=		motif-2.3.8
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=motif/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://motif.ics.com/
COMMENT=		LGPLed Motif toolkit for the X Window System
LICENSE=		gnu-lgpl-v2.1

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		lesstif-[0-9]* openmotif-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		flex gmake tbl pkg-config yacc
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=		-Dsun

SUBST_CLASSES+=			man_rename
SUBST_STAGE.man_rename=		pre-configure
SUBST_MESSAGE.man_rename=	Fixing hardcoded paths.
SUBST_FILES.man_rename=		doc/man/man3/Makefile.in
SUBST_SED.man_rename=		-e 's: Core.3: XCore.3:g'
SUBST_SED.man_rename+=		-e 's: Object.3: XObject.3:g'
SUBST_SED.man_rename+=		-e 's: Shell.3: XShell.3:g'

CONFIGURE_ARGS+=	--enable-jpeg
CONFIGURE_ARGS+=	--enable-png
CONFIGURE_ARGS+=	--with-libjpeg-includes=${JPEGBASE}/include
CONFIGURE_ARGS+=	--with-libjpeg-lib=${JPEGBASE}/lib
CONFIGURE_ARGS+=	--with-libpng-includes=${BUILDLINK_PREFIX.png}/include
CONFIGURE_ARGS+=	--with-libpng-lib=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib

CONFIGURE_ARGS+=	--disable-printing

BUILDLINK_TRANSFORM+=	l:Xft:Xft:fontconfig

# Don't compress manual pages as they include each other.
.undef MANZ

CONFIGURE_ENV.NetBSD+=	ac_cv_func_setpgrp_void=no
CONFIGURE_ARGS+=	--enable-xft
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

MAKE_FLAGS+=		CC_FOR_BUILD=${NATIVE_CC:Q:U${CC:Q}}
MAKE_FLAGS+=		AR_FOR_BUILD=${NATIVE_AR:Q:U${AR:Q}}
MAKE_FLAGS+=		RANLIB_FOR_BUILD=${NATIVE_RANLIB:Q:U${RANLIB:Q}}
MAKE_FLAGS+=		CPPFLAGS_FOR_BUILD=${CPPFLAGS_FOR_BUILD:Q}
MAKE_FLAGS+=		LDFLAGS_FOR_BUILD=${LDFLAGS_FOR_BUILD:Q}
MAKE_FLAGS+=		LIBS_FOR_BUILD=-lXt

# wml.c has
#
#	#ifdef HAVE_CONFIG_H
#	#include <config.h>
#	#endif
#	...
#	#ifdef HAVE_FCNTL_H
#	#include <fcntl.h>
#	#else
#	#include <sys/file.h>
#	#endif
#
# Using config.h doesn't make sense for cross-builds because it
# describes the target system, not the native system.  But <fcntl.h> is
# in POSIX and has been for a very long time.  If there are any systems
# that _don't_ have it and really need <sys/file.h>, and still run
# pkgsrc, we can make this conditional or find another way to do it.
#
CPPFLAGS_FOR_BUILD+=	-DHAVE_FCNTL_H

.if empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CPPFLAGS_FOR_BUILD+=	${BUILDLINK_CPPFLAGS}
LDFLAGS_FOR_BUILD+=	${BUILDLINK_LDFLAGS}
.else
MAKE_FLAGS+=		CROSS_COMPILING=yes
# XXX should support independent cross PREFIX
CPPFLAGS_FOR_BUILD+=	-I${PREFIX:Q}/include
LDFLAGS_FOR_BUILD+=	-L${PREFIX:Q}/lib
LDFLAGS_FOR_BUILD+=	${COMPILER_RPATH_FLAG:Q}${PREFIX:Q}/lib
CONFIGURE_ARGS.NetBSD+=	ac_cv_file__usr_X_include_X11_X_h=no
CONFIGURE_ARGS.NetBSD+=	ac_cv_file__usr_X11R6_include_X11_X_h=no
.  if ${X11_TYPE} != "native"
# Motif's build involves building and running tools, wml*, that are
# linked against libXt.  Thus we need libXt as a tool dependency, not
# as a build or run dependency.  This occurs for both native and cross
# builds -- but missing this dependency only causes problems for cross
# builds, because the build dependency on libXmu effectively brings in
# libXt for this purpose in native builds.
TOOL_DEPENDS+=		libXt>=0:../../x11/libXt
.  endif
.endif

# 1) Fix the man pages to refer to the correct sections.
# 2) Change references to {Core,Object,Shell}.3 to X{Core,Object,Shell}.3 to
#    avoid manpage conflicts with other packages.
#
post-patch:
	set -e; \
	cd ${WRKSRC}/doc/man;						\
	for manpage in man1/*.1 man3/*.3 man4/*.4 man5/*.5; do		\
		${SED}	-e "s|user cmd|1|g"				\
			-e "s|library call|3|g"				\
			-e "s|special file|5|g"				\
			-e "s|file formats|5|g"				\
			$${manpage} > $${manpage}.fixed;		\
		${MV} -f $${manpage}.fixed $${manpage};			\
	done;								\
	set -e; \
	cd ${WRKSRC}/doc/man/man3;					\
	for name in Core Object Shell; do                               \
		${MV} -f $${name}.3 X$${name}.3;			\
		files=`${GREP} -l ".fB$${name}.fP(3)" *.3`;		\
		for manpage in $${files}; do				\
			${MV} -f $${manpage} $${manpage}.presubst;	\
			${SED} "s|\\(.fB\\)$${name}\\(.fP(3)\\)|\\1X$${name}\\2|g" \
				$${manpage}.presubst > $${manpage};	\
			${RM} -f $${manpage}.presubst;			\
		done;							\
	done
	${ECHO} "#include <X11/Xos_r.h>" > ${WRKSRC}/lib/Xm/Xmos_r.h

# Filter the manpages through tbl.
post-build:
	set -e; \
	cd ${WRKSRC}/doc/man;						\
	for manpage in man1/*.1 man3/*.3 man4/*.4 man5/*.5; do		\
		${TBL} $${manpage} > $${manpage}.tblized;		\
		${MV} -f $${manpage}.tblized $${manpage};		\
	done

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/xbitmaps/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
