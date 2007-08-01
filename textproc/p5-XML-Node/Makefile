# $NetBSD: Makefile,v 1.20 2007/08/01 19:50:29 joerg Exp $
#

DISTNAME=	XML-Node-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5xno
CATEGORIES=	textproc perl5
MASTER_SITES=	http://belmont-shores.ics.uci.edu/pub/ \
		${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://belmont-shores.ics.uci.edu/XML::Node/
COMMENT=	Node-based XML parsing: an simplified interface to XML::Parser

DEPENDS+=	p5-XML-Parser-2.*:../../textproc/p5-XML-Parser

PERL5_PACKLIST=		auto/XML/Node/.packlist

REPLACE_PERL=	parse-orders.pl parse-foo.pl parse-testsuite.pl

post-install:
	${INSTALL_DATA} \
		${WRKSRC}/orders.xml \
		${WRKSRC}/test.xml \
		${WRKSRC}/foo.xml \
		${WRKSRC}/README \
		${PERL5_INSTALLVENDORLIB}/XML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
