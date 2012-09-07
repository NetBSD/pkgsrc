# $NetBSD: Makefile,v 1.24 2012/09/07 19:17:39 adam Exp $
#

DISTNAME=	metisse-0.4.1
PKGREVISION=	14
CATEGORIES=	wm x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/metisse/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://insitu.lri.fr/metisse/
COMMENT=	Window manager with novel features
LICENSE=	gnu-gpl-v3

CONFLICTS+=	fvwm-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config msgfmt perl
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_GNU_READLINE=	yes	# uses read_history_range, append_history & history_truncate_file

DEPENDS+=	rxvt>=2.7.10nb5:../../x11/rxvt

CONFIGURE_ARGS+=	--with-fontdir=${X11BASE}/lib/X11/fonts

REPLACE_PERL+=	FvwmCompositor/config/scripting.pl

.include "options.mk"

.include "../../audio/rplay/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/nucleo/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
