# $NetBSD: Makefile,v 1.39.2.1 2006/01/08 05:33:48 salo Exp $

PKGVER=		2.2.3
DISTNAME=	openMotif-${PKGVER}
PKGNAME=	openmotif-${PKGVER}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://ftp.motifzone.com/src/

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://www.opengroup.org/openmotif/
COMMENT=		The Open Group Motif toolkit for the X Window System

CONFLICTS+=		lesstif-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_X11BASE=		yes
USE_LIBTOOL=		yes
USE_TOOLS=		gmake tbl
GNU_CONFIGURE=		yes

SUBST_CLASSES+=			man_rename
SUBST_STAGE.man_rename=		pre-configure
SUBST_MESSAGE.man_rename=	"Fixing hardcoded paths."
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
