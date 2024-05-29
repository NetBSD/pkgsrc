# $NetBSD: Makefile,v 1.52 2024/05/29 16:34:46 adam Exp $
#

DISTNAME=	wbar-2.2.2
PKGREVISION=	44
CATEGORIES=	wm
MASTER_SITES=	http://wbar.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rodolf0/wbar
COMMENT=	Simple and highly customizable quick-launch tool
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake gsed:build intltool pkg-config msgfmt

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

BUILDLINK_TRANSFORM+=	rm:-Werror
PKG_SYSCONFSUBDIR=	wbar
CONF_FILES+=		${PREFIX}/share/examples/wbar/wbar.cfg ${PKG_SYSCONFDIR}/wbar.cfg

SUBST_CLASSES+=		sed
SUBST_FILES.sed+=	configure
SUBST_SED.sed=		-e "s/sed -i/gsed -i/"
SUBST_STAGE.sed=	post-extract
SUBST_MESSAGE.sed=	Needs GNU sed.

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
