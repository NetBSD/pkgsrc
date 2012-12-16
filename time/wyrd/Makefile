# $NetBSD: Makefile,v 1.8 2012/12/16 21:23:51 dholland Exp $
#

DISTNAME=		wyrd-1.4.5
CATEGORIES=		time
MASTER_SITES=		http://pessimization.com/software/wyrd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pessimization.com/software/wyrd/
COMMENT=		Text-based front-end to Remind
LICENSE=		gnu-gpl-v2

DEPENDS+=		remind>=3.00.24:../../time/remind

USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes # chgat(), typeahead(), ...
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-ncurses
GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		no

CONF_FILES+=		${PREFIX}/share/examples/wyrd/wyrdrc \
			${PKG_SYSCONFDIR}/wyrdrc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
