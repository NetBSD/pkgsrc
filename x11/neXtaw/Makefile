# $NetBSD: Makefile,v 1.1.1.1 2002/08/02 20:10:47 jlam Exp $

DISTNAME=	neXtaw-0.12
CATEGORIES=	x11
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	packages@netbsd.org
COMMENT=	NeXTstep-like widgets based on the Athena Widget set

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.XAW3D ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in ${WRKSRC}/doc/app-defaults/*; do			\
		${INSTALL_DATA} $${file} ${EGDIR};			\
	done

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD/alpha 1.5.2, gcc has an optimization bug.
.if !empty(MACHINE_PLATFORM:MNetBSD-1.5.2-alpha)
CFLAGS+=	-O0
.endif
