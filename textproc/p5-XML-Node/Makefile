# $NetBSD: Makefile,v 1.10 2004/05/04 23:46:37 snj Exp $
#

DISTNAME=	XML-Node-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xno
CATEGORIES=	textproc perl5
MASTER_SITES=	http://belmont-shores.ics.uci.edu/pub/ \
		${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://belmont-shores.ics.uci.edu/XML::Node/
COMMENT=	Node-based XML parsing: an simplified interface to XML::Parser

DEPENDS+=	p5-XML-Parser-2.*:../p5-XML-Parser

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Node/.packlist

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/orders.xml \
		${WRKSRC}/test.xml \
		${WRKSRC}/foo.xml \
		${WRKSRC}/README \
		${PERL5_SITELIB}/XML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
