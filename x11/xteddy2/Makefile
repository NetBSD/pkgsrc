# $NetBSD: Makefile,v 1.5 2001/07/09 15:49:07 zuntum Exp $

DISTNAME=	xteddy-2.0.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy/
COMMENT=	Teddy bear for your desktop

CONFLICT+=	xteddy-1.*

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=	yes
USE_X11=	yes

CPPFLAGS+=	-I${X11BASE}/include

pre-configure:
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/configure >${WRKSRC}/configure.new
	${MV} ${WRKSRC}/configure.new ${WRKSRC}/configure
	${CHMOD} 755 ${WRKSRC}/configure
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/xteddy_test >${WRKSRC}/xteddy_test.new
	${MV} ${WRKSRC}/xteddy_test.new ${WRKSRC}/xteddy_test
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		${WRKSRC}/xtoys >${WRKSRC}/xtoys.new
	${MV} ${WRKSRC}/xtoys.new ${WRKSRC}/xtoys

.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
