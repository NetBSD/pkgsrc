# $NetBSD: Makefile,v 1.6 2001/12/25 19:25:28 wiz Exp $
#

DISTNAME=	wml-2.0.3
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

USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl=${PERL5} \
		--with-incdir=${BUILDLINK_DIR}/include \
		--with-libdir=${BUILDLINK_DIR}/lib \
		--with-openworld \
		--with-tidy=${LOCALBASE}/bin/tidy

USE_BUILDLINK_ONLY=	yes

# redrawwin()
USE_NCURSES=	yes

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

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
