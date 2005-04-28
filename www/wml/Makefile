# $NetBSD: Makefile,v 1.20 2005/04/28 23:37:31 jlam Exp $
#

DISTNAME=	wml-2.0.9
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://thewml.org/distrib/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://thewml.org/
COMMENT=	Web Meta Language

DEPENDS+=	p5-Bit-Vector>=5.2:../../devel/p5-Bit-Vector
DEPENDS+=	p5-Image-Size>=2.6:../../graphics/p5-Image-Size
DEPENDS+=	p5-Term-ReadKey>=2.11:../../devel/p5-Term-ReadKey
#DEPENDS+=	tidy-[0-9]*:../../www/tidy

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL5} \
		--with-openworld \
		--with-tidy=${LOCALBASE}/bin/tidy

TEST_TARGET=	test

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*

PERL_ARCHNAME_cmd!=	eval `${PERL5} -V:archname 2>/dev/null`; \
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
	    cd ${WRKSRC}/$$i && ${AUTORECONF} --force || exit 1; \
	done

post-install:
	cd ${PREFIX}/man/cat1 ; \
	for i in wml_aux_tidy wml_aux_txt2html wml_p4_gm4 ; \
	do \
	    ${MV} $${i}.1 $${i}.0 ; \
	done
	cd ${PREFIX}/man/cat7 ; \
	for i in wml_barebone wml_std_css1 wml_std_css2 wml_std_csspos \
	    wml_std_html20 wml_std_html32 wml_std_html40 wml_std_html401 \
	    wml_std_wai10 wml_std_xhtml10 ; \
	do \
	    ${MV} $${i}.7 $${i}.0 ; \
	done

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
