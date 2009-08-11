# $NetBSD: Makefile,v 1.5 2009/08/11 12:12:34 drochner Exp $
#

DISTNAME=	fvwm-themes-${THEM_VER}
PKGREVISION=	8
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fvwm-themes/}
EXTRACT_SUFX=	.tar.bz2
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}	\
		fvwm-themes-extra-${THEM_VER}.tar.bz2

MAINTAINER=	gendalia@NetBSD.org
HOMEPAGE=	http://fvwm-themes.sourceforge.net/
COMMENT=	Configuration framework for fvwm2 with samples

DEPENDS+=	{fvwm,fvwm2}>=2.4.8:../../wm/fvwm

THEM_VER=	0.6.2
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	perl:run
USE_X11BASE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-ft-datadir=${PREFIX}/share/fvwm2

REPLACE_PERL+=	themes/cde/modules/create-buttonbar-config

post-install:
	${PREFIX}/bin/fvwm-themes-config --site --install \
		${DISTDIR}/fvwm-themes-extra-${THEM_VER}.tar.bz2

DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick
.include "../../mk/bsd.pkg.mk"
