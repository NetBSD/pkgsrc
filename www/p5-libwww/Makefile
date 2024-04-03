# $NetBSD: Makefile,v 1.143 2024/04/03 07:15:39 wiz Exp $

DISTNAME=	libwww-perl-6.77
PKGNAME=	p5-${DISTNAME:S/-perl-/-/}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OA/OALDERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/libwww-perl
COMMENT=	Perl5 library for WWW access
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Encode-Locale>=0:../../textproc/p5-Encode-Locale
DEPENDS+=	p5-File-Listing>=6:../../devel/p5-File-Listing
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTTP-Cookies>=6:../../www/p5-HTTP-Cookies
DEPENDS+=	p5-HTTP-Daemon>=6.12:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-HTTP-Date>=6:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Negotiate>=6:../../www/p5-HTTP-Negotiate
DEPENDS+=	p5-HTTP-Message>=6:../../www/p5-HTTP-Message
DEPENDS+=	p5-LWP-MediaTypes>=6:../../www/p5-LWP-MediaTypes
DEPENDS+=	p5-Net-HTTP>=6.18:../../www/p5-Net-HTTP
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-URI>=1.10:../../www/p5-URI
DEPENDS+=	p5-WWW-RobotRules>=6.01:../../www/p5-WWW-RobotRules
# LWP::Protocol::https is an optional dependency, but it requires this package,
# so don't depend on it.

TEST_DEPENDS+=	p5-HTTP-CookieJar>=0:../../www/p5-HTTP-CookieJar
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/LWP/.packlist
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "options.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
