# $NetBSD: Makefile,v 1.3 2008/06/20 01:09:39 joerg Exp $

DISTNAME=	DateTime-Format-ISO8601-0.0403
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jhoblitt/DateTime-Format-ISO8601/
COMMENT=	Parses ISO8601 formats

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.18:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.77:../../time/p5-DateTime-Format-Builder
PERL5_MODULE_TYPE=   Module::Build

PERL5_PACKLIST=		auto/DateTime/Format/ISO8601/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
