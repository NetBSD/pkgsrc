# $NetBSD: Makefile,v 1.28 2023/12/03 00:59:39 wen Exp $

DISTNAME=	DateTime-Format-MySQL-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-MySQL
COMMENT=	Parse and format MySQL dates and times
LICENSE=	${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Format/MySQL/.packlist

DEPENDS+=	p5-DateTime-Format-Builder>=0.60:../../time/p5-DateTime-Format-Builder
# for make test
TOOL_DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash
TOOL_DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
