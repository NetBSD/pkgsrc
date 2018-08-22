# $NetBSD: Makefile,v 1.15 2018/08/22 09:47:31 wiz Exp $
#

DISTNAME=	Captcha-reCAPTCHA-0.97
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PH/PHRED/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Captcha-reCAPTCHA/
COMMENT=	Perl implementation of the reCAPTCHA API
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Tiny>=0.904:../../www/p5-HTML-Tiny
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww  # for LWP::UserAgent

PERL5_PACKLIST=	auto/Captcha/reCAPTCHA/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
