# $NetBSD: Makefile,v 1.107 2020/05/31 15:24:20 rillig Exp $

DISTNAME=	lesstif-0.95.2
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lesstif/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lesstif.org/
COMMENT=	API compatible clone of the OSF/Motif toolkit

CONFLICTS+=	openmotif-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-verbose
CONFIGURE_ARGS+=	--enable-production

# The following forces the build process to use sed as the HTML-to-text
# converter.
CONFIGURE_ENV+=		LYNX_CMD=${WRKDIR}/nonexecutable
CONFIGURE_ENV+=		LINKS_CMD=${WRKDIR}/nonexecutable

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL
FILES_SUBST+=		LOCALBASE=${LOCALBASE:Q}
FILES_SUBST+=		X11BASE=${X11BASE:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		ECHO=${ECHO:Q}
FILES_SUBST+=		GREP=${GREP:Q}
FILES_SUBST+=		LN=${LN:Q}
FILES_SUBST+=		MV=${MV:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}

post-extract:
	cd ${WRKSRC}/lib/config; ${MV} -f host.def LessTif.def

# Change references to {Core,Object,Shell}.3 to X{Core,Object,Shell}.3 to
# avoid manpage conflicts with other packages.
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

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
