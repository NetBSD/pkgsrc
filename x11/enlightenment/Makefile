# $NetBSD: Makefile,v 1.14 1999/10/28 04:58:35 jlam Exp $

DISTNAME=		enlightenment-0.16.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		esound-*:../../audio/esound
DEPENDS+=		imlib-*:../../graphics/imlib
DEPENDS+=		fnlib-0.5:../../graphics/fnlib
DEPENDS+=		freetype-*:../../graphics/freetype
DEPENDS+=		libghttp-*:../../www/libghttp

USE_PERL5=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fsstd
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=		-I${LOCALBASE}/include

EMPTY_DIRS=	config/backup \
		themes/BlueSteel/borders/BORDERLESS/images \
		themes/BlueSteel/borders/FIXEDSIZE/images \
		themes/BlueSteel/borders/SMALL/images \
		themes/BlueSteel/borders/ICONBOX/images \
		themes/BlueSteel/borders/VERYSMALLFIXED/images \
		themes/BlueSteel/borders/SMALLFIXED/images \
		themes/BlueSteel/buttons/images \
		themes/BlueSteel/coords/images \
		themes/BlueSteel/slideouts/images \
		themes/BlueSteel/sound/samples \
		themes/BrushedMetal-Tigert/borders/DEFAULT/images \
		themes/BrushedMetal-Tigert/borders/BORDERLESS/images \
		themes/BrushedMetal-Tigert/borders/ICONBOX/images \
		themes/BrushedMetal-Tigert/borders/MENU/images \
		themes/BrushedMetal-Tigert/borders/BORDER_ONLY/images \
		themes/BrushedMetal-Tigert/borders/SHAPED/images \
		themes/BrushedMetal-Tigert/borders/FIXED_SIZE/images \
		themes/BrushedMetal-Tigert/borders/TRANSIENT/images \
		themes/BrushedMetal-Tigert/borders/MENU_BORDER_ONLY/images \
		themes/BrushedMetal-Tigert/buttons/images \
		themes/BrushedMetal-Tigert/cursors/images \
		themes/BrushedMetal-Tigert/slideouts/images \
		themes/BrushedMetal-Tigert/ttfonts \
		themes/ShinyMetal/borders/images \
		themes/ShinyMetal/slideouts

post-install:
.for DIR in ${EMPTY_DIRS}
	@${TOUCH} ${PREFIX}/share/enlightenment/${DIR}/.directory
.endfor

.include "../../mk/bsd.pkg.mk"
