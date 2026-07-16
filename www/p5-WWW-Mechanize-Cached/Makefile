# $NetBSD: Makefile,v 1.23 2026/07/16 19:06:21 wiz Exp $

DISTNAME=	WWW-Mechanize-Cached-2.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OA/OALDERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Mechanize-Cached
COMMENT=	Cache response to be polite
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Cache-Cache-[0-9]*:../../devel/p5-Cache-Cache
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-File-XDG-[0-9]*:../../devel/p5-File-XDG
DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-libwww>=6.66:../../www/p5-libwww
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-CHI-[0-9]*:../../devel/p5-CHI

PERL5_PACKLIST=		auto/WWW/Mechanize/Cached/.packlist
USE_LANGUAGES=		# none

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
