# $NetBSD: Makefile,v 1.50 2023/11/12 13:24:42 wiz Exp $

DISTNAME=	xteddy-2.2
PKGREVISION=	2
CATEGORIES=	x11 games
MASTER_SITES=	http://staffwww.itn.liu.se/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://staffwww.itn.liu.se/~stegu/xteddy/
COMMENT=	Teddy bear for your desktop
LICENSE=	gnu-gpl-v2

CONFLICTS+=	xteddy-1.*

GNU_CONFIGURE=	yes

USE_TOOLS+=	ksh:run pkg-config

LDFLAGS.SunOS+=	-lXext

REPLACE_KSH+=	xtoys

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure xteddy_test xtoys
SUBST_VARS.prefix=	PREFIX

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
