# $NetBSD: Makefile,v 1.1.1.1 2007/06/10 11:24:36 abs Exp $

DISTNAME=	DateTime-Format-MySQL-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-MySQL/
COMMENT=	Parse and format MySQL dates and times

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Format/MySQL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
