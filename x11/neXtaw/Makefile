# $NetBSD: Makefile,v 1.30 2023/07/17 22:00:25 nia Exp $

DISTNAME=	neXtaw-0.15.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://siag.nu/pub/neXtaw/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siag.nu/neXtaw/
COMMENT=	NeXTstep-like widgets based on the Athena Widget set

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.XAW3D ${DESTDIR}${DOCDIR}
	set -e; cd ${WRKSRC}/doc/app-defaults; for file in *; do	\
		case "$${file}" in					\
		Makefile*)	continue ;;				\
		esac;							\
		${INSTALL_DATA} "$$file" ${DESTDIR}${EGDIR};			\
	done

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
