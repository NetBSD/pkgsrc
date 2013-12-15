# $NetBSD: Makefile,v 1.80 2013/12/15 19:42:48 asau Exp $

PKGVER=		2.3.3
DISTNAME=	openmotif-${PKGVER}
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://ftp.ics.com/openmotif/2.3/2.3.3/
MASTER_SITES+=	ftp://ftp.ics.com/openmotif/2.3/2.3.3/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.opengroup.org/openmotif/
COMMENT=		The Open Group Motif toolkit for the X Window System
LICENSE=		openmotif-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

RESTRICTED=		Only for Open Source OS; complex terms for commercial distribution.

# License grants permission to reproduce distfile for use on Open
# Source OSes.  Therefore, do not set NO_SRC_ON_FTP, since the
# distfile is thereby provided with the intent of it being used
# according to the license.  Set NO_BIN_ON_FTP if the operating system
# for which the package is built is not known to be open source.
# List OSes known to be Open Source; default to not acceptable for new ones.
OPSYS_OK_LIST=	DragonFly FreeBSD Linux NetBSD OpenBSD
.if empty(OPSYS_OK_LIST:M${OPSYS})
NO_BIN_ON_FTP=		${RESTRICTED}
.endif

# NO_*_ON_CDROM: License seems to require indemnification for
# "commercial product offering", but doesn't define commercial product
# offering.  Err on the side of caution and mark restricted.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CONFLICTS+=		lesstif-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		flex gmake tbl pkg-config
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
