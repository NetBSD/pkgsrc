# $NetBSD: Makefile,v 1.18 2004/10/15 12:06:05 tv Exp $
#

DISTNAME=	ion-2-20040729
PKGNAME=	${DISTNAME:S/-2-/-/}
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.cs.tut.fi/~tuomov/ion/dl/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://iki.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

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
CONF_FILES+=		${EGDIR}/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

INSTALLATION_DIRS=	bin lib/ion libexec/ion man/man1
INSTALLATION_DIRS+=	share/doc/ion share/examples/ion share/ion

.include "../../lang/lua/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
