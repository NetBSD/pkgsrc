# $NetBSD: Makefile,v 1.10 2001/07/21 15:23:51 jlam Exp $

DISTNAME=	amaya-src-4.3.2
PKGNAME=	amaya-4.3.2
WRKSRC=		${WRKDIR}/Amaya/work
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/amaya/
EXTRACT_SUFX=	.tgz

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://www.w3.org/Amaya/
COMMENT=	Web Browser/Editor from the World Wide Web Consortium

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--without-graphic-libs
CONFIGURE_ARGS+=	--with-motif
CONFIGURE_ENV+=		ac_cv_path_motif="${ac_cv_path_motif}"
CFLAGS+=		-Dunix

# Craft the ac_cv_path_motif variable so that configure "finds" the Motif
# files in the right place.
#
ac_cv_path_motif=	no_motif=
ac_cv_path_motif+=	ac_motif_includes=${BUILDLINK_DIR}/include
ac_cv_path_motif+=	ac_motif_libraries=${BUILDLINK_DIR}/lib

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
