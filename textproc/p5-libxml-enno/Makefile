# $NetBSD: Makefile,v 1.3 2001/04/26 20:58:22 jtb Exp $

DISTNAME=	libxml-enno-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.erols.com/enno/
COMMENT=	Several XML manipulation tools, including XML::DOM

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Date-Manip>=5.39:../../devel/p5-Date-Manip
DEPENDS+=	p5-libwww>=5.50:../../www/p5-libwww
DEPENDS+=	p5-libxml>=0.07:../../textproc/p5-libxml
DEPENDS+=	p5-Parse-Yapp>=1.04:../../devel/p5-Parse-Yapp

USE_PERL5=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libxml-enno/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
