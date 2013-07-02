# $NetBSD: Makefile,v 1.51 2013/07/02 20:33:37 gls Exp $
#

DISTNAME=	pekwm-0.1.17
CATEGORIES=	wm
MASTER_SITES=	http://www.pekwm.org/projects/pekwm/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	gls@NetBSD.org
HOMEPAGE=	http://www.pekwm.org/
COMMENT=	Window manager based on aewm++
LICENSE=	gnu-gpl-v2

FETCH_USING=	curl
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

PKG_SYSCONFSUBDIR=	pekwm

EGDIR=			${PREFIX}/share/examples/pekwm
CONF_FILES=
.for f in autoproperties config keys menu mouse start vars
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
