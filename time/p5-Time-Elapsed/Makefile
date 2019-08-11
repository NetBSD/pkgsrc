# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:11 wiz Exp $

DISTNAME=		Time-Elapsed-0.33
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Time-Elapsed
COMMENT=		Displays the elapsed time as a human readable string
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Time/Elapsed/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
