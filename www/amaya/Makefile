# $NetBSD: Makefile,v 1.33 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=	amaya-src-8.2
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=			1
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web browser/editor from the World Wide Web Consortium (W3C)

EXTRACT_ELEMENTS=	Amaya libwww

WRKSRC=		${WRKDIR}/Amaya/work
USE_BUILDLINK3=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--without-graphic-libs	# Use pkgsrc libraries
CFLAGS+=		-Dunix

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

.include "../../graphics/imlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
