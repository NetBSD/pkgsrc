# $NetBSD: Makefile,v 1.28 2003/11/17 15:28:31 wiz Exp $
#

DISTNAME=	amaya-src-8.0
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/Amaya/work
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/Amaya/Distribution/ \
		ftp://ftp.w3.org/pub/amaya/ \
		ftp://mirror.aarnet.edu.au/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web browser/editor from the World Wide Web Consortium (W3C)

EXTRACT_ELEMENTS=	Amaya libwww

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_GMAKE=	YES
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

.include "../../graphics/imlib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
