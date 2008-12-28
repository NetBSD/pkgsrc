# $NetBSD: Makefile,v 1.33 2008/12/28 13:10:29 adrianp Exp $
#

DISTNAME=	lablgtk-2.10.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/lablgtk.html
COMMENT=	GTK+ 2.x bindings for Objective Caml

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

BUILD_TARGET=		world

BUILDLINK_DEPMETHOD.ocaml=	full

CONFLICTS=	lablgtk2-2.*{,nb*}

.include "../../mk/bsd.prefs.mk"

# Stub libraries for functions missing from base system.
PLIST_VARS+=	stubs

.if ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || \
    ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || \
    ${OPSYS} == "SunOS"
PLIST.stubs=	yes
.endif

.include "options.mk"

.include "../../lang/ocaml/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
