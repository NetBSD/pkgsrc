# $NetBSD: Makefile,v 1.38 2026/09/19 18:33:02 wiz Exp $

DISTNAME=	podlators-v6.1.1
PKGNAME=	p5-${DISTNAME:S/-v/-/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RR/RRA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/podlators
COMMENT=	Collection of pod related perl modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
