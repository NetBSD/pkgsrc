# $NetBSD: Makefile,v 1.12 2024/11/16 12:07:49 wiz Exp $

DISTNAME=	JavaScript-Minifier-XS-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GT/GTERMARS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/JavaScript-Minifier-XS
COMMENT=	XS based JavaScript minifier
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/JavaScript/Minifier/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
