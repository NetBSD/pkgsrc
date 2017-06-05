# $NetBSD: Makefile,v 1.21 2017/06/05 14:25:03 ryoon Exp $

DISTNAME=	DateTime-Format-Pg-0.16012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Pg/
COMMENT=	Parse and format PostgreSQL dates and times
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.1000:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.72:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone>=0.05:../../time/p5-DateTime-TimeZone

PERL5_PACKLIST=		auto/DateTime/Format/Pg/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
