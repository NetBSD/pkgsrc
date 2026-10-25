# $NetBSD: Makefile,v 1.7 2026/10/25 09:51:00 wiz Exp $

DISTNAME=	HTTP-Headers-ActionPack-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRWO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Headers-ActionPack
COMMENT=	HTTP Action, Adventure and Excitement
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Sub-Exporter-[0-9]*:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

TEST_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
# needs unpackaged p5-Test-Timer

PERL5_PACKLIST=		auto/HTTP/Headers/ActionPack/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
