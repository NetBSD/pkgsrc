# $NetBSD: Makefile,v 1.1 2023/03/08 15:35:04 schmonz Exp $

DISTNAME=	Playwright-1.291
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TE/TEODESIAN/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Playwright
COMMENT=	Perl client for Playwright
LICENSE=	mit

DEPENDS+=	p5-Capture-Tiny>=0:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-File-ShareDir>=0:../../devel/p5-File-ShareDir
DEPENDS+=	p5-File-Which>=0:../../devel/p5-File-Which
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-JSON-MaybeXS>=0:../../converters/p5-JSON-MaybeXS
DEPENDS+=	p5-Proc-ProcessTable>=0:../../devel/p5-Proc-ProcessTable
DEPENDS+=	p5-Sereal-Decoder>=0:../../converters/p5-Sereal-Decoder
DEPENDS+=	p5-Sereal-Encoder>=0:../../converters/p5-Sereal-Encoder
DEPENDS+=	p5-Sub-Install>=0:../../devel/p5-Sub-Install
DEPENDS+=	p5-Test-TCP>=0:../../net/p5-Test-TCP

PERL5_PACKLIST=	auto/Playwright/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
