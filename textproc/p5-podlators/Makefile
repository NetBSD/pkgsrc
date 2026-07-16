# $NetBSD: Makefile,v 1.36 2026/07/16 19:05:31 wiz Exp $

DISTNAME=	podlators-v6.0.2
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/podlators
COMMENT=	Collection of pod related perl modules
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
