# $NetBSD: Makefile,v 1.1.1.1 2000/12/05 22:54:01 hubertf Exp $

DISTNAME=	xteddy-2.0.1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy

DEPENDS+=	imlib-1.9.*:../../graphics/imlib

CONFLICT+=	xteddy-1.*

GNU_CONFIGURE=	yes
USE_X11=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${X11BASE}/include"
LDFLAGS+=	-L${X11BASE}/lib -R${X11BASE}/lib 	# for libImlib

pre-configure:
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${WRKSRC}/configure >${WRKSRC}/configure.new
	${MV} ${WRKSRC}/configure.new ${WRKSRC}/configure
	${CHMOD} 755 ${WRKSRC}/configure
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${WRKSRC}/xteddy_test >${WRKSRC}/xteddy_test.new
	${MV} ${WRKSRC}/xteddy_test.new ${WRKSRC}/xteddy_test
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|' \
		<${WRKSRC}/xtoys >${WRKSRC}/xtoys.new
	${MV} ${WRKSRC}/xtoys.new ${WRKSRC}/xtoys

.include "../../mk/bsd.pkg.mk"
