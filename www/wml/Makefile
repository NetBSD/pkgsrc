# $NetBSD: Makefile,v 1.1.1.1 2000/09/04 21:41:50 kim Exp $
#

DISTNAME=	wml-2.0.2
CATEGORIES=	www perl5
MASTER_SITES=	http://www.engelschall.com/sw/wml/distrib/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.engelschall.com/sw/wml/

DEPENDS+=	ncurses-*:../../devel/ncurses
DEPENDS+=	p5-Bit-Vector>=5.2:../../devel/p5-Bit-Vector
DEPENDS+=	p5-File-PathConvert-*:../../devel/p5-File-PathConvert
DEPENDS+=	p5-Image-Size>=2.6:../../graphics/p5-Image-Size
DEPENDS+=	p5-Term-ReadKey>=2.11:../../devel/p5-Term-ReadKey
#DEPENDS+=	tidy-*:../../www/tidy

USE_PERL5=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL5} \
		--with-incdir=${LOCALBASE}/include \
		--with-libdir=${LOCALBASE}/lib \
		--with-openworld \
		--with-tidy=${LOCALBASE}/bin/tidy

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

test:
	@cd ${WRKSRC} && ${MAKE} test

.include "../../mk/bsd.pkg.mk"
