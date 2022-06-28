# $NetBSD: Makefile,v 1.15 2022/06/28 11:37:35 wiz Exp $

DISTNAME=	LWP-ConsoleLogger-0.000043
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LWP-ConsoleLogger
COMMENT=	LWP tracing and debugging
LICENSE=	artistic-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/ConsoleLogger/.packlist

DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=	p5-Data-Printer>=0.36:../../devel/p5-Data-Printer
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-HTML-Restrict-[0-9]*:../../www/p5-HTML-Restrict
DEPENDS+=	p5-HTTP-Body-[0-9]*:../../www/p5-HTTP-Body
DEPENDS+=	p5-HTTP-CookieMonster-[0-9]*:../../www/p5-HTTP-CookieMonster
DEPENDS+=	p5-JSON-MaybeXS>=1.003005:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch
DEPENDS+=	p5-Module-Build>=0.28:../../devel/p5-Module-Build
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-MooX-StrictConstructor-[0-9]*:../../devel/p5-MooX-StrictConstructor
DEPENDS+=	p5-Parse-MIME-[0-9]*:../../mail/p5-Parse-MIME
DEPENDS+=	p5-String-Trim-[0-9]*:../../textproc/p5-String-Trim
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-Term-Size-Any-[0-9]*:../../devel/p5-Term-Size-Any
DEPENDS+=	p5-Text-SimpleTable-AutoWidth>=0.09:../../textproc/p5-Text-SimpleTable-AutoWidth
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
DEPENDS+=	p5-URI-Query-[0-9]*:../../www/p5-URI-Query
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

# not officially requested but needed by tests
TEST_DEPENDS+=	p5-Log-Dispatch-Array-[0-9]*:../../devel/p5-Log-Dispatch-Array
TEST_DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
TEST_DEPENDS+=	p5-Test-LWP-UserAgent-[0-9]*:../../www/p5-Test-LWP-UserAgent
TEST_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet
TEST_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
TEST_DEPENDS+=	p5-WWW-Mechanize-[0-9]*:../../www/p5-WWW-Mechanize
TEST_DEPENDS+=	p5-HTML-FormatText-WithLinks-[0-9]*:../../textproc/p5-HTML-FormatText-WithLinks
TEST_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
TEST_DEPENDS+=	p5-Plack-Test-Agent-[0-9]*:../../www/p5-Plack-Test-Agent
TEST_DEPENDS+=	p5-HTTP-Server-Simple-PSGI-[0-9]*:../../www/p5-HTTP-Server-Simple-PSGI
TEST_DEPENDS+=	p5-Test-FailWarnings-[0-9]*:../../devel/p5-Test-FailWarnings
TEST_DEPENDS+=	p5-HTTP-CookieJar-[0-9]*:../../www/p5-HTTP-CookieJar

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
