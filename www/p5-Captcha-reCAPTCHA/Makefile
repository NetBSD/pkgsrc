# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:28 wiz Exp $
#

DISTNAME=	Captcha-reCAPTCHA-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PH/PHRED/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Captcha-reCAPTCHA
COMMENT=	Perl implementation of the reCAPTCHA API
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Tiny>=0.904:../../www/p5-HTML-Tiny
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww  # for LWP::UserAgent

PERL5_PACKLIST=	auto/Captcha/reCAPTCHA/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
