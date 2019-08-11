# $NetBSD: Makefile,v 1.45 2019/08/11 13:24:25 wiz Exp $

DISTNAME=		CGI-Application-4.61
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Application
COMMENT=		Perl5 module to create sophisticated, reusable web-based applications
LICENSE=		${PERL5_LICENSE}

#DEPENDS+=		{p5-CGI>=2.66,perl>=5.6.1nb2}:../../www/p5-CGI
DEPENDS+=		p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

PERL5_PACKLIST=		auto/CGI/Application/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
