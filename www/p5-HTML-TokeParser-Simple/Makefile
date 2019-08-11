# $NetBSD: Makefile,v 1.16 2019/08/11 13:24:42 wiz Exp $

DISTNAME=		HTML-TokeParser-Simple-3.16
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-TokeParser-Simple
COMMENT=		Perl 5 module prodiving an easy to use HTML::TokeParser interface
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/HTML/TokeParser/Simple/.packlist

DEPENDS+=		p5-HTML-Parser>=3.25:../../www/p5-HTML-Parser
DEPENDS+=		p5-Sub-Override-[0-9]*:../../devel/p5-Sub-Override

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
