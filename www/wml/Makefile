# $NetBSD: Makefile,v 1.15 2004/04/25 06:17:46 snj Exp $
#

DISTNAME=	wml-2.0.3
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://www.engelschall.com/sw/wml/distrib/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.engelschall.com/sw/wml/
COMMENT=	Web Meta Language

DEPENDS+=	p5-Bit-Vector>=5.2:../../devel/p5-Bit-Vector
DEPENDS+=	p5-File-PathConvert-[0-9]*:../../devel/p5-File-PathConvert
DEPENDS+=	p5-Image-Size>=2.6:../../graphics/p5-Image-Size
DEPENDS+=	p5-Term-ReadKey>=2.11:../../devel/p5-Term-ReadKey
#DEPENDS+=	tidy-[0-9]*:../../www/tidy

GNU_CONFIGURE=	yes
# Don't change incdir/libdir -- they need to be this way so
# that ncurses.h is found even if base system curses.h is used.
CONFIGURE_ARGS=	--with-perl=${PERL5} \
		--with-incdir=${LOCALBASE}/include \
		--with-libdir=${LOCALBASE}/lib \
		--with-openworld \
		--with-tidy=${LOCALBASE}/bin/tidy

USE_BUILDLINK3=	yes
TEST_TARGET=	test

INCOMPAT_CURSES=	NetBSD-1.5* NetBSD-1.6[-_.]*
INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-C]*

post-install:
	cd ${PREFIX}/man/cat1 ; \
	for i in wml_aux_linklint wml_aux_tidy wml_aux_txt2html wml_p4_gm4 ; \
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
.include "../../mk/bsd.pkg.mk"
