# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:23 tv Exp $
#

DISTNAME=	fvwm-themes-${THEM_VER}
PKGNAME=	${DISTNAME:S/fvwm/&2/}
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fvwm-themes/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}	\
		fvwm-themes-extra-${THEM_VER}.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://fvwm-themes.sourceforge.net/
COMMENT=	Configuration framework for fvwm2 with samples

DEPENDS+=	fvwm2>=2.4.8:../../wm/fvwm2

THEM_VER=	0.6.2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK3=	YES
USE_PERL5=	YES
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-ft-datadir=${PREFIX}/share/fvwm2

post-install:
	${PREFIX}/bin/fvwm-themes-config --site --install \
		${DISTDIR}/fvwm-themes-extra-${THEM_VER}.tar.bz2

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
