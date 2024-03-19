# $NetBSD: Makefile,v 1.33 2024/03/19 10:41:41 wiz Exp $

DISTNAME=	LWP-Protocol-https-6.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OA/OALDERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/LWP-Protocol-https
COMMENT=	Provide https support for LWP::UserAgent
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-Socket-SSL>=1.970:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-libwww>=6.77:../../www/p5-libwww
DEPENDS+=	p5-Net-HTTP>=0:../../www/p5-Net-HTTP
TEST_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TEST_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TEST_DEPENDS+=	p5-Test-RequiresInternet-[0-9]*:../../net/p5-Test-RequiresInternet

CONFLICTS+=	p5-libwww<6.02

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Protocol/https/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
