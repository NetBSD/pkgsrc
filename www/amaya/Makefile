# $NetBSD: Makefile,v 1.17.2.1 2002/06/30 06:24:30 jlam Exp $

DISTNAME=	amaya-src-5.1
PKGNAME=	amaya-5.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/Amaya/work
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web Browser/Editor from the World Wide Web Consortium

EXTRACT_ELEMENTS=	Amaya
USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--without-graphic-libs	# use pkgsrc libraries
CONFIGURE_ARGS+=	--with-motif
CONFIGURE_ENV+=		ac_cv_path_motif="${ac_cv_path_motif}"
CFLAGS+=		-Dunix

# Craft the ac_cv_path_motif variable so that configure "finds" the Motif
# files in the right place.
#
ac_cv_path_motif=	no_motif=
ac_cv_path_motif+=	ac_motif_includes=${MOTIFBASE}/include
ac_cv_path_motif+=	ac_motif_libraries=${MOTIFBASE}/lib

post-extract:
	${MKDIR} ${WRKSRC}

# Install into ${PREFIX}/lib/Amaya instead of ${PREFIX}/Amaya.
post-patch:
	cd ${WRKSRC}/..;						\
	files="amaya/Makefile.in";					\
	for file in $${files}; do					\
		${MV} $${file} $${file}.fixme;				\
		${SED}	-e "s|\$$(prefix)/Amaya|\$$(prefix)/lib/Amaya|g" \
			$${file}.fixme >  $${file};			\
	done

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/Amaya

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../www/libwww/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
