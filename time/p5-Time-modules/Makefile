# $NetBSD: Makefile,v 1.19 2020/08/31 18:12:27 wiz Exp $

DISTNAME=	Time-modules-2013.0912
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-modules
COMMENT=	Miscellaneous date parsing and formatting
LICENSE=	public-domain

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Time-modules/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
