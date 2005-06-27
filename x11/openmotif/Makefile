# $NetBSD: Makefile,v 1.37 2005/06/27 14:08:15 wiz Exp $

PKGVER=		2.1.30
DISTNAME=	openmotif${PKGVER}
PKGNAME=	openmotif-${PKGVER}
PKGREVISION=	4
CATEGORIES=	x11
MOTIF_SITES=	ftp://openmotif.opengroup.org/pub/openmotif/R${PKGVER}/ \
		ftp://ftp.opengroup.org/pub/openmotif/R${PKGVER}/ \
		ftp://ftp.kddlabs.co.jp/X11/openmotif/R${PKGVER}/
MASTER_SITES=	${MOTIF_SITES:=tars/}

PATCH_SITES=		${MOTIF_SITES:=fixes/}
PATCHFILES=		patch1 patch2 patch3 patch4 patch5
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.opengroup.org/openmotif/
COMMENT=		The Open Group Motif toolkit for the X Window System

CONFLICTS+=		lesstif-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/motif
DIST_SUBDIR=		openmotif
USE_X11BASE=		yes
USE_PKGINSTALL=		yes
BUILD_TARGET=		World
USE_TOOLS+=		tbl

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		X11BASE=${X11BASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
PLIST_SUBST+=		AVAILABLE="@comment "
.else
PLIST_SUBST+=		AVAILABLE=
.endif

# We must use GNU make on Linux
.if ${OPSYS} == "Linux"
USE_TOOLS+=		gmake
.endif

INSTALLATION_DIRS=	lib/X11/config man/man1 man/man3 man/man5

.include "../../mk/x11.buildlink3.mk"

post-extract:
	${CP} ${FILESDIR}/NoInstall.rules ${WRKSRC}/config/cf/NoInstall.rules
	${CP} ${FILESDIR}/OpenMotif.def ${WRKSRC}/config/cf/Motif.def
	${CP} ${FILESDIR}/DragonFly.cf ${WRKSRC}/config/cf/DragonFly.cf

# 1) Fix the man pages to refer to the correct sections.
# 2) Link Motif.* to OpenMotif.*.
# 3) Change references to {Core,Object,Shell}.3 to X{Core,Object,Shell}.3 to
#    avoid manpage conflicts with other packages.
#
post-patch:
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
	cd ${WRKSRC}/config/cf;						\
	files="Motif.rules Motif.tmpl";					\
	for configfile in $${files}; do					\
		dest="Open$${configfile}";				\
		${RM} -f $${dest};					\
		${LN} -s $${configfile} $${dest};			\
	done
	cd ${WRKSRC}/doc/man/man3;					\
	for name in Core Object Shell; do                               \
		${MV} -f $${name}.3 X$${name}.3;			\
		files=`${GREP} -l ".fB$${name}.fP(3)" *.3`;		\
		for manpage in $${files}; do				\
			${MV} -f $${manpage} $${manpage}.presubst;	\
			${SED} "s|\(.fB\)$${name}\(.fP(3)\)|\1X$${name}\2|g" \
				$${manpage}.presubst > $${manpage};	\
			${RM} -f $${manpage}.presubst;			\
		done;							\
	done

# Link the appropriate directories since we're building OpenMotif outside
# of the X11R6 source tree.
#
do-configure:
	${MKDIR} ${WRKSRC}/imports/x11
	cd ${WRKSRC}/imports/x11; for dir in bin include lib; do	\
		if [ -d $${dir} ]; then					\
			${RM} $${dir};					\
		fi;							\
		${LN} -s ${BUILDLINK_X11_DIR}/$${dir} $${dir};		\
	done

# Filter the manpages through tbl.
post-build:
	cd ${WRKSRC}/doc/man;						\
	for manpage in man1/*.1 man3/*.3 man4/*.4 man5/*.5; do		\
		${TBL} $${manpage} > $${manpage}.tblized;		\
		${MV} -f $${manpage}.tblized $${manpage};		\
	done

# Install the OpenMotif config files and manpages.
post-install:
	cd ${WRKSRC}/config/cf;						\
	files="Motif.def Motif.rules Motif.tmpl";			\
	for configfile in $${files}; do					\
		dest="${PREFIX}/lib/X11/config/Open$${configfile}";	\
		${INSTALL_DATA} $${configfile} $${dest};		\
	done
	cd ${WRKSRC}/doc/man;						\
	for manpage in man1/*.1 man3/*.3 man5/*.5; do			\
		${INSTALL_MAN} $${manpage} ${PREFIX}/man/$${manpage};	\
	done

.include "../../mk/bsd.pkg.mk"
