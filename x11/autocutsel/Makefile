# $NetBSD: Makefile,v 1.5 2023/01/09 12:42:45 vins Exp $
#

DISTNAME=		autocutsel-0.10.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_GITHUB:=sigmike/}
GITHUB_PROJECT=		autocutsel
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://www.nongnu.org/autocutsel/
COMMENT=		Synchronizes the X11 cutbuffer and CLIPBOARD selection
LICENSE=		gnu-gpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		automake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/doc/autocutsel

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal && libtoolize && autoheader && \
	automake --gnu --add-missing && autoconf

post-install:
	${INSTALL_DATA} ${WRKSRC}/README \
	  ${DESTDIR}${PREFIX}/share/doc/autocutsel/

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
