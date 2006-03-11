# $NetBSD: Makefile,v 1.23 2006/03/11 10:07:50 ghen Exp $

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

.include "../../graphics/imlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
