# $NetBSD: Makefile,v 1.44 2021/09/17 10:27:34 nia Exp $

DISTNAME=	qvwm-1.1.12
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qvwm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://qvwm.sourceforge.net/index_en.html
COMMENT=	Windows 95-like window manager for X11
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex
USE_LANGUAGES=	c c++03

LIBS.SunOS+=	-lICE -lSM

# Avoid embedding relative paths into the binary.
CONFIGURE_ENV+=		ac_cv_path_PATH_RM=${RM}

CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ARGS+=	--without-imlib
CONFIGURE_ARGS+=	--without-esd

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
