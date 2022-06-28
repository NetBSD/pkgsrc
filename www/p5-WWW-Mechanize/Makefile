# $NetBSD: Makefile,v 1.64 2022/06/28 11:37:46 wiz Exp $

DISTNAME=	WWW-Mechanize-2.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Mechanize
COMMENT=	Automates web page form & link interaction
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=	p5-HTML-Form>=6.00:../../www/p5-HTML-Form
DEPENDS+=	p5-HTML-Parser>=3.33:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tree>=5.0:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTTP-Daemon>=6.12:../../www/p5-HTTP-Daemon
DEPENDS+=	p5-HTTP-Message>=1.3:../../www/p5-HTTP-Message
DEPENDS+=	p5-HTTP-Server-Simple>=0.35:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-Path-Tiny>=0:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-URI>=1.36:../../www/p5-URI
DEPENDS+=	p5-libwww>=6.45:../../www/p5-libwww
# recommended for HTML::Tree ...
DEPENDS+=	p5-HTML-Format-[0-9]*:../../www/p5-HTML-Format

TEST_DEPENDS+=	p5-PadWalker-[0-9]*:../../devel/p5-PadWalker
TEST_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle
TEST_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
TEST_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet
TEST_DEPENDS+=	p5-Test-Taint-[0-9]*:../../devel/p5-Test-Taint
TEST_DEPENDS+=	p5-Test-Warn>=0.11:../../devel/p5-Test-Warn
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

# use defaults from Makefile.PL, to avoid user interaction
# if not set explicitly
MAKE_PARAMS+=	--mech-dump --nolive

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/WWW/Mechanize/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
