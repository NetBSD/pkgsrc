# $NetBSD: Makefile,v 1.5 2019/08/11 13:24:48 wiz Exp $

DISTNAME=	JavaScript-Minifier-XS-0.11
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
