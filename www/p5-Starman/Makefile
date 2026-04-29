# $NetBSD: Makefile,v 1.34 2026/04/29 06:52:22 wiz Exp $

DISTNAME=	Starman-0.4018
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Starman
COMMENT=	High-performance preforking PSGI web server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Starman/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

DEPENDS+=	p5-Net-Server-SS-PreFork-[0-9]*:../../net/p5-Net-Server-SS-PreFork
DEPENDS+=	p5-Server-Starter-[0-9]*:../../sysutils/p5-Server-Starter
DEPENDS+=	p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-HTTP-Parser-XS-[0-9]*:../../www/p5-HTTP-Parser-XS
DEPENDS+=	p5-Net-Server>=0.91:../../net/p5-Net-Server
DEPENDS+=	p5-Plack>=0.9931:../../www/p5-Plack
TEST_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork
TEST_DEPENDS+=	p5-LWP-Protocol-https-[0-9]*:../../www/p5-LWP-Protocol-https

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
