# $NetBSD: Makefile,v 1.5 2012/10/08 13:04:30 asau Exp $
#

DISTNAME=		wyrd-1.4.1
PKGREVISION=		2
CATEGORIES=		time
MASTER_SITES=		http://www.eecs.umich.edu/~pelzlpj/wyrd/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.eecs.umich.edu/~pelzlpj/wyrd/
COMMENT=		Text-based front-end to Remind

DEPENDS+=		remind>=3.00.24:../../time/remind

USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes # chgat(), typeahead(), ...
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-ncurses
GNU_CONFIGURE=		yes

CONF_FILES+=		${PREFIX}/share/examples/wyrd/wyrdrc \
			${PKG_SYSCONFDIR}/wyrdrc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
