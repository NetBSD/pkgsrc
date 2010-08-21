# $NetBSD: Makefile,v 1.3 2010/08/21 16:36:38 seb Exp $
#

DISTNAME=	Captcha-reCAPTCHA-Mailhide-0.93
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AN/ANDYA/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Captcha-reCAPTCHA-Mailhide/
COMMENT=	Perl implementation of the reCAPTCHA Mailhide API

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Crypt-Rijndael-[0-9]*:../../security/p5-Crypt-Rijndael
DEPENDS+=	p5-HTML-Tiny>=0.904:../../www/p5-HTML-Tiny
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/Captcha/reCAPTCHA/Mailhide/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
