# $NetBSD: Makefile,v 1.19 2019/06/30 20:17:31 nia Exp $

DISTNAME=	HTML-Strip-2.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Strip
COMMENT=	Perl5 module for strip HTML tag
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/HTML/Strip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
