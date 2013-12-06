# $NetBSD: Makefile,v 1.10 2013/12/06 11:16:56 asau Exp $

PKGVER=		2.3.4
PKGREVISION=	7
DISTNAME=	motif-${PKGVER}-src
PKGNAME=	motif-${PKGVER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif/}
EXTRACT_SUFX=	.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://motif.ics.com/
COMMENT=		LGPLed Motif toolkit for the X Window System
LICENSE=		gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/motif-${PKGVER}

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=		lesstif-[0-9]* openmotif-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		flex gmake tbl pkg-config automake yacc
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no # PR 37233

CFLAGS.SunOS+=		-Dsun

SUBST_CLASSES+=			man_rename
SUBST_STAGE.man_rename=		pre-configure
SUBST_MESSAGE.man_rename=	Fixing hardcoded paths.
SUBST_FILES.man_rename=		doc/man/man3/Makefile.in
SUBST_SED.man_rename=		-e 's: Core.3: XCore.3:g'
SUBST_SED.man_rename+=		-e 's: Object.3: XObject.3:g'
SUBST_SED.man_rename+=		-e 's: Shell.3: XShell.3:g'

CONFIGURE_ARGS+= \
		--enable-jpeg --enable-png \
		--with-libjpeg-includes=${JPEGBASE}/include \
		--with-libjpeg-lib=${JPEGBASE}/lib \
		--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
		--with-libpng-lib=${BUILDLINK_PREFIX.png}/lib \
		--x-libraries=${X11BASE}/lib

CONFIGURE_ARGS+= --disable-printing

BUILDLINK_TRANSFORM+=	l:Xft:Xft:fontconfig

# Don't compress manual pages as they include each other.
.undef MANZ

.if ${OPSYS} == "NetBSD"
CONFIGURE_ENV+=		ac_cv_func_setpgrp_void=no
.endif
CONFIGURE_ARGS+=	--enable-xft
CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_FLAGS+=	CROSS_COMPILING=yes CC_FOR_BUILD=${NATIVE_CC:Q} \
    CPPFLAGS_FOR_BUILD=-I${PREFIX}/include
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
	${CP} -f man4/mwmrc.4 man5/mwmrc.5
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

pre-configure:
	set -e; cd ${WRKSRC} ; sh ./autogen.sh

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
