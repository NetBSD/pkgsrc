# $NetBSD: Makefile,v 1.5 2011/08/14 16:05:46 obache Exp $
#

DISTNAME=	Captcha-reCAPTCHA-0.94
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AN/ANDYA/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Captcha-reCAPTCHA/
COMMENT=	Perl implementation of the reCAPTCHA API
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-HTML-Tiny>=0.904:../../www/p5-HTML-Tiny
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww  # for LWP::UserAgent

PERL5_PACKLIST=	auto/Captcha/reCAPTCHA/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
