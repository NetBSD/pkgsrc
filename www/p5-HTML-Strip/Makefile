# $NetBSD: Makefile,v 1.24 2023/04/29 09:19:41 wen Exp $

DISTNAME=	HTML-Strip-2.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Strip
COMMENT=	Perl5 module for strip HTML tag
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/HTML/Strip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
