# $NetBSD: Makefile,v 1.38 2015/01/16 12:15:31 wiz Exp $

DISTNAME=	wml-2.0.11
CATEGORIES=	www perl5
MASTER_SITES=	http://thewml.org/distrib/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://thewml.org/
COMMENT=	Web Meta Language

DEPENDS+=	p5-Bit-Vector>=5.2:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Image-Size>=2.6:../../graphics/p5-Image-Size
DEPENDS+=	p5-Term-ReadKey>=2.11:../../devel/p5-Term-ReadKey
#DEPENDS+=	tidy-[0-9]*:../../www/tidy
BUILD_DEPENDS+=	lynx-[0-9]*:../../www/lynx

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=	automake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-perl=${PERL5:Q} \
		--with-openworld \
		--with-tidy=${LOCALBASE}/bin/tidy

TEST_TARGET=	test

INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*-*

PERL_ARCHNAME_cmd=	eval `${PERL5} -V:archname 2>/dev/null`; \
			${ECHO} $${archname}
PLIST_SUBST+=		PERL_ARCHNAME=${PERL_ARCHNAME_cmd:sh}

pre-configure:
	for i in \
	    wml_aux/iselect \
	    wml_backend/p3_eperl \
	    wml_backend/p4_gm4 \
	    wml_common/gd \
	    ; \
	do \
	    cd ${WRKSRC}/$$i && autoreconf --force || exit 1; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
