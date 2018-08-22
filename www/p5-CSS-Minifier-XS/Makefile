# $NetBSD: Makefile,v 1.3 2018/08/22 09:47:31 wiz Exp $

DISTNAME=	CSS-Minifier-XS-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GT/GTERMARS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS-Minifier-XS
COMMENT=	XS based CSS minifier
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CSS/Minifier/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
