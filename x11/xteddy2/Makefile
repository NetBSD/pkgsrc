# $NetBSD: Makefile,v 1.45 2019/05/23 19:23:24 rillig Exp $

DISTNAME=	xteddy-2.0.1
PKGREVISION=	23
CATEGORIES=	x11 games
MASTER_SITES=	http://staffwww.itn.liu.se/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://staffwww.itn.liu.se/~stegu/xteddy/
COMMENT=	Teddy bear for your desktop

CONFLICTS+=	xteddy-1.*

GNU_CONFIGURE=	yes

USE_TOOLS+=	ksh:run

REPLACE_KSH+=	xtoys

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure xteddy_test xtoys
SUBST_VARS.prefix=	PREFIX

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
