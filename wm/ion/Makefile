# $NetBSD: Makefile,v 1.41 2013/07/04 21:27:58 adam Exp $
#

DISTNAME=	ion-2-20040729
PKGNAME=	${DISTNAME:S/-2-/-/}
PKGREVISION=	9
CATEGORIES=	wm x11
MASTER_SITES=	http://iki.fi/tuomov/dl/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://modeemi.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BROKEN=		Doesn't work with libtool 2.x

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
INSTALL_MAKE_FLAGS=	INST_ETCDIR=${EGDIR:Q}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

PKG_SYSCONFSUBDIR=	ion
EGDIR=			${PREFIX}/share/examples/ion
EGFILES=		floatws.lua ion-bindings.lua ion-menus.lua	\
			ion.lua ionws.lua kludges.lua			\
			look-clean.lua look-cleanios.lua		\
			look-cleanviolet.lua look-dusky.lua		\
			look-greyviolet.lua look-ios.lua		\
			look-simpleblue.lua look-wheat2.lua menu.lua	\
			query.lua draw.lua pwm.lua pwm-bindings.lua	\
			pwm-menus.lua dock.lua dock-draw.lua
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

INSTALLATION_DIRS=	bin lib/ion libexec/ion ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/ion share/examples/ion share/ion

.include "../../devel/libltdl/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
