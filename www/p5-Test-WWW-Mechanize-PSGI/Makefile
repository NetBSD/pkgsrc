# $NetBSD: Makefile,v 1.3 2011/08/14 16:06:10 obache Exp $

DISTNAME=	Test-WWW-Mechanize-PSGI-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Mechanize-PSGI/
COMMENT=	Perl 5 module to test PSGI programs using WWW::Mechanize
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/WWW/Mechanize/PSGI/.packlist

DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Test-WWW-Mechanize-[0-9]*:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
