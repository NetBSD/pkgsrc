# $NetBSD: Makefile,v 1.6 2021/05/24 19:55:19 wiz Exp $

DISTNAME=	Browser-Open-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CF/CFRANKS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Browser::Open
COMMENT=	Open a browser in a given URL
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Browser/Open/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
