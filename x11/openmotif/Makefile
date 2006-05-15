# $NetBSD: Makefile,v 1.47 2006/05/15 13:26:40 gdt Exp $

PKGVER=		2.2.3
DISTNAME=	openMotif-${PKGVER}
PKGNAME=	openmotif-${PKGVER}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://ftp.motifzone.com/src/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.opengroup.org/openmotif/
COMMENT=		The Open Group Motif toolkit for the X Window System

LICENSE=		openmotif-license
RESTRICTED=		Only for Open Source OS; complex terms for commercial distribution.
# See end of file for setting NO_*_ON_FTP.
# NO_*_ON_CDROM: License seems to require indemnification for
# "commercial product offering", but doesn't define commercial product
# offering.  Err on the side of caution and mark restricted.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

CONFLICTS+=		lesstif-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11BASE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		flex gmake tbl
GNU_CONFIGURE=		yes

SUBST_CLASSES+=			man_rename
SUBST_STAGE.man_rename=		pre-configure
SUBST_MESSAGE.man_rename=	Fixing hardcoded paths.
SUBST_FILES.man_rename=		doc/man/man3/Makefile.in
SUBST_SED.man_rename=		-e 's: Core.3: XCore.3:g' \
	-e 's: Object.3: XObject.3:g' -e 's: Shell.3: XShell.3:g'


# 1) Fix the man pages to refer to the correct sections.
# 2) Change references to {Core,Object,Shell}.3 to X{Core,Object,Shell}.3 to
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

# Filter the manpages through tbl.
post-build:
	cd ${WRKSRC}/doc/man;						\
	for manpage in man1/*.1 man3/*.3 man4/*.4 man5/*.5; do		\
		${TBL} $${manpage} > $${manpage}.tblized;		\
		${MV} -f $${manpage}.tblized $${manpage};		\
	done

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# XXX This fragment is at the end because OPSYS is defined via bsd.pkg.mk.
OPSYS_OK=	NO
# List OSes known to be Open Source; default to not acceptable for new ones.
OPSYS_OK_LIST=	DragonFly FreeBSD Linux NetBSD OpenBSD
.if !empty(OPSYS_OK_LIST:M${OPSYS})
OPSYS_OK=YES
.  endif
.if !empty(OPSYS_OK:MYES)
# Open Source OS ==> non-commercial distribution acceptable
.else
# other than Open Source OS ==> no distribution
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
.endif
