# $NetBSD: Makefile,v 1.24 2006/03/11 18:22:22 rillig Exp $

DISTNAME=	xteddy-2.0.1
PKGREVISION=	8
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy/
COMMENT=	Teddy bear for your desktop

CONFLICTS+=	xteddy-1.*

GNU_CONFIGURE=	yes

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	/bin/ksh
REPLACE_FILES.bash=	xtoys

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	configure xteddy_test xtoys
SUBST_SED.prefix=	-e 's|@PREFIX@|${PREFIX}|g'

.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
