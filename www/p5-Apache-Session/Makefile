# $NetBSD: Makefile,v 1.41 2019/08/11 13:24:24 wiz Exp $
#

DISTNAME=		Apache-Session-1.93
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Apache-Session
COMMENT=		Perl5 module to provide persistent storage
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Test-Deep>=0.082:../../devel/p5-Test-Deep
DEPENDS+=		p5-Test-Exception>=0.15:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Apache/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
