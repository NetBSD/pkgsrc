# $NetBSD: Makefile,v 1.10.2.1 2002/06/24 06:02:07 jlam Exp $

DISTNAME=	xteddy-2.0.1
PKGREVISION=	1
CATEGORIES=	x11 games
MASTER_SITES=	http://www.ITN.LiU.SE/~stegu/xteddy/

MAINTAINER=	johnam@mail.kemper.org
HOMEPAGE=	http://www.ITN.LiU.SE/~stegu/xteddy/
COMMENT=	Teddy bear for your desktop

CONFLICT+=	xteddy-1.*

USE_BUILDLINK2=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes

pre-configure:
	files="configure xteddy_test xtoys";				\
	cd ${WRKSRC}; for file in $${files}; do				\
		${MV} $${file} $${file}.fixme;				\
		${SED} -e "s|@PREFIX@|${PREFIX}|g"			\
			$${file}.fixme >> $${file};			\
		if [ -x $${file}.fixme ]; then				\
			${CHMOD} +x $${file};				\
		fi;							\
		${RM} -f $${file}.fixme;				\
	done

.include "../../graphics/imlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
