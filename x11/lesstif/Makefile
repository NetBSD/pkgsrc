# $NetBSD: Makefile,v 1.73 2004/04/24 22:46:13 jlam Exp $

DISTNAME=	lesstif-0.93.94
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lesstif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lesstif.org/
COMMENT=	API compatible clone of the OSF/Motif toolkit

CONFLICTS+=	openmotif-[0-9]*

USE_BUILDLINK3=		YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--disable-build-12
CONFIGURE_ARGS+=	--disable-build-20
CONFIGURE_ARGS+=	--enable-build-21
CONFIGURE_ARGS+=	--enable-production --disable-debug --disable-verbose
CONFIGURE_ARGS+=	--enable-editres --enable-xdnd

# The following forces the build process to use sed as the HTML-to-text
# converter.
#
CONFIGURE_ENV+=		LYNX_CMD=${WRKDIR}/nonexecutable
CONFIGURE_ENV+=		LINKS_CMD=${WRKDIR}/nonexecutable

# Work around an ICE on sparc64-1.6
CONFIGURE_ENV+=		F77=${FALSE}

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
FILES_SUBST=		LOCALBASE=${LOCALBASE}
FILES_SUBST+=		X11BASE=${X11BASE}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		ECHO=${ECHO:Q}
FILES_SUBST+=		GREP=${GREP:Q}
FILES_SUBST+=		LN=${LN:Q}
FILES_SUBST+=		MV=${MV:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
	cd ${WRKSRC}/lib/config; ${MV} -f host.def LessTif.def

# Change references to {Core,Object,Shell}.3 to X{Core,Object,Shell}.3 to
# avoid manpage conflicts with other packages.
#
post-patch:
	cd ${WRKSRC}/doc/lessdox/widgets;				\
	for name in Core Object Shell; do				\
		${MV} -f $${name}.3 X$${name}.3;			\
		files=`${GREP} -l "[[:blank:]]$${name} (3)" *.3`;	\
		for file in $${files}; do				\
			${MV} -f $${file} $${file}.presubst;		\
			${SED} -e "s|\([[:blank:]]\)$${name} (3)|\1X$${name} (3)|g" \
				$${file}.presubst > $${file};		\
			${RM} -f $${file}.presubst;			\
		done;							\
		${MV} -f Makefile.in Makefile.in.presubst;		\
		${SED} -e "s|\([[:space:]]\)$${name}.3|\1X$${name}.3|g"	\
			Makefile.in.presubst > Makefile.in;		\
		${RM} -f Makefile.in.presubst;				\
	done

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
