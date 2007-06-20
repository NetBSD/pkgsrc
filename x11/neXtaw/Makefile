# $NetBSD: Makefile,v 1.24 2007/06/20 16:49:18 jlam Exp $

DISTNAME=	neXtaw-0.15.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siag.nu/neXtaw/
COMMENT=	NeXTstep-like widgets based on the Athena Widget set

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-alpha)
GCC_REQD+=	2.95
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.XAW3D ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/doc/app-defaults; for file in *; do		\
		case "$${file}" in					\
		Makefile*)	continue ;;				\
		esac;							\
		${INSTALL_DATA} $${file} ${EGDIR};			\
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
