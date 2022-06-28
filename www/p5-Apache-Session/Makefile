# $NetBSD: Makefile,v 1.45 2022/06/28 11:37:08 wiz Exp $

DISTNAME=		Apache-Session-1.94
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Apache-Session
COMMENT=		Perl5 module to provide persistent storage
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Test-Deep>=0.082:../../devel/p5-Test-Deep
TEST_DEPENDS+=		p5-Test-Exception>=0.15:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
