# $NetBSD: Makefile,v 1.4 2002/09/29 09:15:59 jlam Exp $

DISTNAME=	neXtaw-0.12
CATEGORIES=	x11
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	packages@netbsd.org
COMMENT=	NeXTstep-like widgets based on the Athena Widget set

USE_BUILDLINK2=		# defined
USE_X11BASE=		# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
.  include "../../lang/gcc/buildlink2.mk
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.XAW3D ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${WRKSRC}/doc/app-defaults/*; do			\
		${INSTALL_DATA} $${file} ${EGDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
