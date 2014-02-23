# $NetBSD: Makefile,v 1.9 2014/02/23 13:02:50 wen Exp $

DISTNAME=		HTML-TokeParser-Simple-3.16
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-TokeParser-Simple/
COMMENT=		Perl 5 module prodiving an easy to use HTML::TokeParser interface
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/HTML/TokeParser/Simple/.packlist

DEPENDS+=		p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=		p5-Sub-Override-[0-9]*:../../devel/p5-Sub-Override

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
