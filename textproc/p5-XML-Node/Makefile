# $NetBSD: Makefile,v 1.4 2001/05/25 02:47:09 hubertf Exp $
#

DISTNAME=	XML-Node-0.10
PKGNAME=	p5-${DISTNAME}nb1
CATEGORIES=	textproc perl5
MASTER_SITES=	http://belmont-shores.ics.uci.edu/pub/ \
		${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://belmont-shores.ics.uci.edu/XML::Node/
COMMENT=	Node-based XML parsing: an simplified interface to XML::Parser

DEPENDS+=	p5-XML-Parser-2.*:../p5-XML-Parser

USE_PERL5=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Node/.packlist

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-install:
		${INSTALL_DATA} \
			${WRKSRC}/orders.xml \
			${WRKSRC}/test.xml \
			${WRKSRC}/foo.xml \
			${WRKSRC}/README \
			${PERL5_SITELIB}/XML

.include "../../mk/bsd.pkg.mk"
