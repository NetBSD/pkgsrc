# $NetBSD: Makefile,v 1.7 2003/03/07 01:25:09 salo Exp $
#

DISTNAME=	ion-20020207
CATEGORIES=	x11 wm
MASTER_SITES=	http://modeemi.cs.tut.fi/~tuomov/dl/

MAINTAINER=	daniel@codefactory.se,zuntum@netbsd.org
HOMEPAGE=	http://modeemi.cs.tut.fi/~tuomov/ion/
COMMENT=	keyboard friendly tiling window manager

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GMAKE=	YES

PKG_SYSCONFSUBDIR=	ion
EGDIR=			${PREFIX}/share/examples/ion
EGFILES=		bindings-default.conf bindings-sun.conf kludges.conf \
			look-brownsteel.conf look-greyviolet.conf \
			look-simpleblue.conf look-wheat.conf sample.conf \
			ion.conf
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/$f ${PKG_SYSCONFDIR}/$f
.endfor
.undef f

# ion's sources will append "ion/" to PKG_SYSCONFBASE, that is, the
# PKG_SYSCONFSUBDIR we are currently using.
MAKE_ENV=		PKG_SYSCONFBASE="${PKG_SYSCONFBASE}"

.include "../../mk/bsd.pkg.mk"
