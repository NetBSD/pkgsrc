# $NetBSD: Makefile,v 1.20 2023/07/06 09:42:33 wiz Exp $

DISTNAME=		HTML-Email-Obfuscate-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/HTML-Email-Obfuscate
COMMENT=		Perl5 module for obfuscating HTML email addresses

DEPENDS+=		p5-HTML-Parser>=3.46:../../www/p5-HTML-Parser

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/HTML/Email/Obfuscate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
