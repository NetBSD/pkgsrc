# $NetBSD: Makefile,v 1.13 2004/04/05 15:21:00 xtraeme Exp $
#

DISTNAME=	ion-2-20040207
PKGNAME=	${DISTNAME:S/-2-/-/}
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://iki.fi/~tuomov/ion/
COMMENT=	Keyboard friendly tiling window manager

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES

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

.include "../../lang/lua/buildlink3.mk"
.include "../../devel/libtool/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
