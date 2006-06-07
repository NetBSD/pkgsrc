# $NetBSD: Makefile,v 1.1.1.1 2006/06/07 11:48:28 abs Exp $

DISTNAME=	DateTime-Format-ISO8601-0.0403
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jhoblitt/DateTime-Format-ISO8601/
COMMENT=	Parses ISO8601 formats

DEPENDS+=	p5-DateTime>=0.18:../../time/p5-DateTime
PERL5_MODULE_TYPE=   Module::Build

PERL5_PACKLIST=		auto/DateTime/Format/ISO8601/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
