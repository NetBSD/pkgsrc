# $NetBSD: Makefile,v 1.10 2023/07/06 09:42:25 wiz Exp $

DISTNAME=	CSS-Minifier-XS-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GT/GTERMARS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CSS-Minifier-XS
COMMENT=	XS based CSS minifier
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CSS/Minifier/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
