# $NetBSD: Makefile,v 1.22 2024/11/16 12:07:22 wiz Exp $

DISTNAME=		Time-Elapsed-0.33
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Time-Elapsed
COMMENT=		Displays the elapsed time as a human readable string
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Time/Elapsed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
