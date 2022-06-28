# $NetBSD: Makefile,v 1.21 2022/06/28 11:37:44 wiz Exp $

DISTNAME=	Test-WWW-Mechanize-PSGI-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-WWW-Mechanize-PSGI
COMMENT=	Perl 5 module to test PSGI programs using WWW::Mechanize
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/WWW/Mechanize/PSGI/.packlist

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
