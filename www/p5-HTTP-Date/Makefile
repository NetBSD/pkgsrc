# $NetBSD: Makefile,v 1.19 2021/05/24 19:55:36 wiz Exp $

DISTNAME=	HTTP-Date-6.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Date
COMMENT=	Perl 5 module providing date conversion routines
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-libwww<6.00

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
