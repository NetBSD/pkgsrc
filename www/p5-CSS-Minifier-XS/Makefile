# $NetBSD: Makefile,v 1.2 2017/06/05 14:25:11 ryoon Exp $

DISTNAME=	CSS-Minifier-XS-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GT/GTERMARS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS-Minifier-XS
COMMENT=	XS based CSS minifier
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/CSS/Minifier/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
