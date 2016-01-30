# $NetBSD: Makefile,v 1.14 2016/01/30 13:11:49 mef Exp $

DISTNAME=	DateTime-Format-MySQL-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-MySQL/
COMMENT=	Parse and format MySQL dates and times

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Format/MySQL/.packlist

DEPENDS+=	p5-DateTime-Format-Builder>=0.60:../../time/p5-DateTime-Format-Builder
# for make test
BUILD_DEPENDS+=	p5-Package-Stash-[0-9]*:../../devel/p5-Package-Stash

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
